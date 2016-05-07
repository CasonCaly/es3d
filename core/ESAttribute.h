#ifndef ESATTRIBUTE_H
#define ESATTRIBUTE_H
#include <QOpenGLFunctions>
#include <QObject>

class ESAttribute : public QObject, public QOpenGLFunctions
{
public:

    ESAttribute(GLuint location);

    void enableVertexAttribArray(bool enable);

    void vertextAttribPointer(GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* ptr);

protected:

    GLuint m_location;
};

#endif // ESATTRIBUTE_H
