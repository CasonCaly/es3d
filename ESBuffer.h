#ifndef ESBUFFER_H
#define ESBUFFER_H
#include <QOpenGLFunctions>

class ESBuffer : protected QOpenGLFunctions
{
public:

    ESBuffer();

    bool initRenderBuffer();

    bool initFrameBuffer();

    GLuint getBufferHandle();

    static void frameBufferRenderBuffer(ESBuffer* renderBuffer);

protected:

     GLuint m_buffer;
};

#endif // ESBUFFER_H
