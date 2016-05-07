#include "ESBuffer.h"

ESBuffer::ESBuffer()
{
    m_buffer = 0;
}

bool ESBuffer::initRenderBuffer()
{
    this->initializeOpenGLFunctions();
    glGenRenderbuffers(1, &m_buffer);
    glBindRenderbuffer(GL_RENDERBUFFER, m_buffer);
    return true;
}

bool ESBuffer::initFrameBuffer()
{
    this->initializeOpenGLFunctions();
    glGenFramebuffers(1, &m_buffer);
    glBindFramebuffer(GL_FRAMEBUFFER, m_buffer);
    return true;
}

GLuint ESBuffer::getBufferHandle()
{
    return m_buffer;
}

void ESBuffer::frameBufferRenderBuffer(ESBuffer* renderBuffer)
{
    renderBuffer->glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, renderBuffer->m_buffer);
}
