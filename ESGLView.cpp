#include "ESGLView.h"

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

ESGLView::ESGLView(QWidget* parent):QGLWidget(parent, 0, 0)
{

}

 ESGLView::~ESGLView()
{

}

void ESGLView::initializeGL()
{
    this->makeCurrent();
    this->initializeOpenGLFunctions();

    m_program.initWithShaderPath("Simple.vert", "Simple.frag");
    m_program.use();
    this->applyOrtho(2, 3);
}

void ESGLView::applyOrtho(float maxX, float maxY)
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

void ESGLView::paintGL()
{
    glClearColor(0.5f, 0.5f, 0.5f, 1);
    glClear(GL_COLOR_BUFFER_BIT);

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

void ESGLView::resizeGL(int width, int height )
{
    glViewport(0, 0, width, height);
}

