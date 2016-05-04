#include "ESProgram.h"
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>

ESProgram::ESProgram()
{
    m_fragmentShader = 0;
    m_vertexShader = 0;
    m_program = 0;

}

 bool ESProgram::initWithShaderPath(const QString& szVertexShaderPath, const QString& szFragmentShaderPath)
 {
     this->initializeOpenGLFunctions();
    m_vertexShader = this->buildShader(szVertexShaderPath, GL_VERTEX_SHADER);
    if(0 == m_vertexShader)
        return false;

    m_fragmentShader = this->buildShader(szFragmentShaderPath, GL_FRAGMENT_SHADER);
    if(0 == m_fragmentShader)
    {
        glDeleteShader(m_vertexShader);
        m_vertexShader = 0;
        return false;
    }

    m_program = glCreateProgram();
    glAttachShader(m_program, m_fragmentShader);
    glAttachShader(m_program, m_vertexShader);
    glLinkProgram(m_program);

    GLint linkSuccess = 0;
    glGetProgramiv(m_program, GL_LINK_STATUS, &linkSuccess);
    if(GL_FALSE == linkSuccess)
    {
        GLsizei logLen = 0;
        glGetProgramInfoLog(m_program, 0, &logLen, nullptr );
        if(0 != logLen)
        {
            GLchar* szLog = new GLchar[logLen + 1];
            glGetProgramInfoLog(m_program, logLen, nullptr, szLog);
            qDebug("%s", szLog);
        }
        return false;
    }
    return true;
 }

 void ESProgram::use()
 {
    if(0 != m_program)
        glUseProgram(m_program);
 }

 ESAttribute* ESProgram::getArribLocation(const QString& name)
 {
     auto target =  m_mapAttribute.find(name);
     ESAttribute* attribute = nullptr;
     if(target == m_mapAttribute.end())
     {
         std::string strName = name.toStdString();
         GLuint loaction = glGetAttribLocation(m_program, strName.c_str());
           attribute = new ESAttribute(loaction);
           attribute->setParent(this);
           attribute->initializeOpenGLFunctions();
           m_mapAttribute.insert(name, attribute);
     }
     else
     {
         attribute = target.value();
     }
      return attribute;
 }

 ESUniform* ESProgram::getUniformLoaction(const QString& name)
 {
     auto target =  m_mapUniform.find(name);
     ESUniform* uniform = nullptr;
     if(target == m_mapUniform.end())
     {
         std::string strName = name.toStdString();
         GLuint loaction = glGetUniformLocation(m_program, strName.c_str());
           uniform = new ESUniform(loaction);
           uniform->setParent(this);
           uniform->initializeOpenGLFunctions();
           m_mapUniform.insert(name, uniform);
     }
     else
     {
         uniform = target.value();
     }
      return uniform;
 }

 GLuint ESProgram::buildShader(const QString& shaderPath, GLenum shaderType)
 {
    QFile file(shaderPath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return 0;
    }

    QTextStream textStream(&file);
    QString text = textStream.readAll();
    std::string strText = text.toStdString();
    const char* szText = strText.c_str();

    GLuint shaderHandle = glCreateShader(shaderType);
    glShaderSource(shaderHandle, 1, &szText, nullptr);
    glCompileShader(shaderHandle);

    GLint compileResult = 0;
    glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &compileResult);

    if(compileResult == GL_FALSE)
    {
        GLsizei logLen = 0;
        glGetShaderInfoLog(shaderHandle, 0, &logLen, nullptr );
        if(0 != logLen)
        {
            GLchar* szLog = new GLchar[logLen + 1];
            glGetShaderInfoLog(shaderHandle, logLen, nullptr, szLog);
            qDebug("%s", szLog);
        }
    }
    file.close();
    return shaderHandle;
 }
