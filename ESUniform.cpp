#include "ESUniform.h"

ESUniform::ESUniform(GLuint location):m_location(location)
{

}

void ESUniform::uniformMatrix4fv(GLsizei count, GLboolean transpose, const GLfloat* value)
{
    glUniformMatrix4fv(m_location, count, transpose, value);
}
