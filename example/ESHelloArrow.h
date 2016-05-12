#ifndef ES_HELLO_ARROW_H
#define ES_HELLO_ARROW_H
#include "core/ESExample.h"

class ESHelloArrow : public ESExample
{
public:

    ESHelloArrow();

    virtual void init();

    virtual void paint();

public:

    void applyOrtho(float maxX, float maxY);

    void applyRotation(float degrees);

protected:

      float m_currentAngle;
};

#endif
