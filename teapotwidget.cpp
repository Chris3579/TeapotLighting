#include "teapotwidget.h"
#include <GL/glut.h> // 确保包含 GLUT 头文件

TeapotWidget::TeapotWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

TeapotWidget::~TeapotWidget()
{
}

void TeapotWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat lightPos[] = { 0.0f, 0.0f, 10.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    // 初始化 GLUT
    int argc = 1;
    char *argv[1] = { (char*)"Something" };
    glutInit(&argc, argv);
}

void TeapotWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w/h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void TeapotWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    drawTeapot();
}

void TeapotWidget::drawTeapot()
{
    glPushMatrix();
    glRotatef(30.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(30.0f, 0.0f, 1.0f, 0.0f);

    // 设置茶壶颜色为蓝色
    GLfloat blue[] = {0.0f, 0.0f, 1.0f, 1.0f};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);

    glutSolidTeapot(1.0);
    glPopMatrix();
}
