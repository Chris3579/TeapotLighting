#ifndef TEAPOTWIDGET_H
#define TEAPOTWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class TeapotWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit TeapotWidget(QWidget *parent = nullptr);
    ~TeapotWidget();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    void drawTeapot();
};

#endif // TEAPOTWIDGET_H
