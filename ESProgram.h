#ifndef ESPROGRAM_H
#define ESPROGRAM_H
#include <QOpenGLFunctions>
#include <QMap>
#include "ESUniform.h"
#include "ESAttribute.h"

class ESProgram : public QObject, protected QOpenGLFunctions
{
public:

    ESProgram();

    bool initWithShaderPath(const QString& szVertexShaderPath, const QString& szFragmentShaderPath);

    void use();

    ESAttribute* getArribLocation(const QString& name);

    ESUniform* getUniformLoaction(const QString& name);

protected:

    GLuint buildShader(const QString& shaderPath, GLenum shaderType);

protected:

    GLuint m_vertexShader;

    GLuint m_fragmentShader;

    GLuint m_program;

    QMap<QString, ESUniform*> m_mapUniform;

    QMap<QString, ESAttribute*> m_mapAttribute;
};

#endif // ESPROGRAM_H
