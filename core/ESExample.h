#ifndef ESEXAMPLE_H
#define ESEXAMPLE_H

#include <QObject>
#include <QOpenGLFunctions>
#include "ESProgram.h"

class ESExample : public QObject, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit ESExample(QObject *parent = 0);

public:

    virtual void init();

    virtual void paint();

signals:

public slots:

protected:

      ESProgram m_program;
};

#endif // ESEXAMPLE_H
