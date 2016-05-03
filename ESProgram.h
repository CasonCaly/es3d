#ifndef ESPROGRAM_H
#define ESPROGRAM_H
#include <QOpenGLFunctions>

class ESProgram : protected QOpenGLFunctions
{
public:

    ESProgram();

    bool initWithShaderPath(const QString& szVertexShaderPath, const QString& szFragmentShaderPath);

    void use();

protected:

    GLuint buildShader(const QString& shaderPath, GLenum shaderType);

protected:

    GLuint m_vertexShader;

    GLuint m_fragmentShader;

    GLuint m_program;
};

#endif // ESPROGRAM_H
