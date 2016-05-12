#include "ESExample.h"

ESExample::ESExample(QObject *parent) : QObject(parent)
{

}

void ESExample::init()
{
    this->initializeOpenGLFunctions();
}

void ESExample::paint()
{

}
