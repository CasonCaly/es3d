#include "ESAttribute.h"

ESAttribute::ESAttribute(GLuint location):m_location(location)
{

}

void ESAttribute::enableVertexAttribArray(bool enable)
{
    if(enable)
        glEnableVertexAttribArray(m_location);
    else
        glDisableVertexAttribArray(m_location);
}

void ESAttribute::vertextAttribPointer(GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* ptr)
{
    glVertexAttribPointer(m_location, size, type, normalized, stride, ptr);
}
