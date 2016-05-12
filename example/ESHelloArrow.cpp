#include "ESHelloArrow.h"

struct Vertex {
    float Position[2];
    float Color[4];
};

// Define the positions and colors of two triangles.
const Vertex Vertices[] = {
    {{-0.5, -0.866}, {1, 1, 0.5f, 1}},
    {{0.5, -0.866},  {1, 1, 0.5f, 1}},
    {{0, 1},         {1, 1, 0.5f, 1}},
    {{-0.5, -0.866}, {0.5f, 0.5f, 0.5f}},
    {{0.5, -0.866},  {0.5f, 0.5f, 0.5f}},
    {{0, -0.4f},     {0.5f, 0.5f, 0.5f}},
};

ESHelloArrow::ESHelloArrow()
{
    m_currentAngle = 0.0f;
}

void ESHelloArrow::init()
{
    ESExample::init();
    m_program.initWithShaderPath("hello_arrow/simple.vert", "hello_arrow/simple.frag");
    m_program.use();
    this->applyOrtho(2, 3);
}

void ESHelloArrow::paint()
{
    glClearColor(0.5f, 0.5f, 0.5f, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    applyRotation(m_currentAngle);

    ESAttribute* posAttri = m_program.getArribLocation("Position");
    ESAttribute* colorAttri = m_program.getArribLocation("SourceColor");

    posAttri->enableVertexAttribArray(true);
    colorAttri->enableVertexAttribArray(true);

    GLsizei stride = sizeof(Vertex);
    const GLvoid* pCoords = &Vertices[0].Position[0];
    const GLvoid* pColors = &Vertices[0].Color[0];

    posAttri->vertextAttribPointer(2, GL_FLOAT, GL_FALSE, stride, pCoords);
    colorAttri->vertextAttribPointer( 4, GL_FLOAT, GL_FALSE, stride, pColors);

    GLsizei vertexCount = sizeof(Vertices) / sizeof(Vertex);
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);

    posAttri->enableVertexAttribArray(false);
    colorAttri->enableVertexAttribArray(false);
}

void ESHelloArrow::applyOrtho(float maxX, float maxY)
{
    float a = 1.0f / maxX;
    float b = 1.0f / maxY;
    float ortho[16] = {
        a, 0,  0, 0,
        0, b,  0, 0,
        0, 0, -1, 0,
        0, 0,  0, 1
    };

    ESUniform* uniform = m_program.getUniformLoaction("Projection");
    uniform->uniformMatrix4fv(1, 0, &ortho[0]);
}

void ESHelloArrow::applyRotation(float degrees)
{
    float radians = degrees * 3.14159f / 180.0f;
    float s = sin(radians);
    float c = cos(radians);
    float zRotation[16] = {
        c, s, 0, 0,
       -s, c, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };

    ESUniform* uniform = m_program.getUniformLoaction("Modelview");
    uniform->uniformMatrix4fv(1, 0, &zRotation[0]);
}
