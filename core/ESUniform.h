#ifndef ESUNIFORM_H
#define ESUNIFORM_H
#include <QOpenGLFunctions>
#include <QObject>

class ESUniform : public QObject, public QOpenGLFunctions
{
public:

    ESUniform(GLuint location);

    void uniformMatrix4fv(GLsizei count, GLboolean transpose, const GLfloat* value);

protected:

    GLuint m_location;
};

#endif // ESUNIFORM_H
