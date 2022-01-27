#ifndef GLDISPLAYWIDGET_H
#include <GL/glu.h>
#include "QMouseEvent"
#include "QWheelEvent"
#include "QDebug"
#include "QDir"
#define GLDISPLAYWIDGET_H
class GLDisplayWidget{

public :
    GLDisplayWidget(QWidget *parent);
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

};
#endif // GLDISPLAYWIDGET_H
