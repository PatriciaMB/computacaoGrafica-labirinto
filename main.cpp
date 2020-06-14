#include <GL/freeglut.h>
#include <cmath>

float angulo = 0;
float angulo_camera = 0;
float angulo_up = 0;

float fov = 45.0f;
float longe = 20.f;
float perto = 0.1f;

float eyex = 0.0f;
float eyey = 0.0f;
float eyez = 0.0f;

void desenha(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glLoadIdentity();
    gluLookAt(eyex, eyey, eyez,                                                                    //ONDE ESTOU
              longe*sin(angulo_camera * M_PI / 180), 0.0f, -longe*cos(angulo_camera * M_PI / 180), //PARA ONDE ESTOU OLHANDO
              sin(angulo_up * M_PI / 180), cos(angulo_up * M_PI / 180), 0.0f);                     //COMO ESTOUS DISPOSTO
    glTranslatef(0.0f, 0.0f, -2.0f);
    //glRotatef(angulo, 0.0f, 1.0f, 0.0f);
    glutWireCube(0.8f);
    glutSwapBuffers();
}

void timer(int t){
    angulo++;
    glutPostRedisplay();
    glutTimerFunc(10, timer, 0);
}

void desenhaMundo(){
    glLoadIdentity();
    glColor3b(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex3d(-2.5f, 2.0f, -2.0f);
    glVertex3d( 2.5f, 2.0f, -2.0f);
    glVertex3d( 2.5f,-2.0f, -2.0f);
    glVertex3d(-2.5f,-2.0f, -2.0f);

    glBegin(GL_LINE_LOOP);
    glVertex3d(-2.5f, 2.0f, -7.0f);
    glVertex3d( 2.5f, 2.0f, -7.0f);
    glVertex3d( 2.5f,-2.0f, -7.0f);
    glVertex3d(-2.5f,-2.0f, -7.0f);

    glBegin(GL_LINES);
    glVertex3d(-2.5f, 2.0f, -2.0f);
    glVertex3d(-2.5f, 2.0f, -7.0f);
    glVertex3d( 2.5f, 2.0f, -2.0f);
    glVertex3d( 2.5f, 2.0f, -7.0f);

    glVertex3d( 2.5f,-2.0f, -2.0f);
    glVertex3d( 2.5f,-2.0f, -7.0f);
    glVertex3d(-2.5f,-2.0f, -2.0f);
    glVertex3d(-2.5f,-2.0f, -7.0f);
    glEnd();
}

void teclado(unsigned char tecla, int x, int y){
    if(tecla == 'q') //SUBIR A CAMERA
        eyey += 0.1f;
    if(tecla == 'a') //INDO PARA ESQUERDA
        eyex -= 0.1f;
    if(tecla == 'w') //INDO PARA FRENTE
        eyez -= 0.1f;
    if(tecla == 's') //INDO PARA TRAS
        eyez += 0.1f;
    if(tecla == 'e') //DESCER CAMERA
        eyey -= 0.1f;
    if(tecla == 'd') //INDO PARA A DIREITA
        eyex += 0.1f;
    if(tecla == ',')
        angulo_camera -= 1.0f;
    if(tecla == '.')
        angulo_camera += 1.0f;
     if(tecla == '[')
        angulo_up -= 1.0f;
    if(tecla == ']')
        angulo_up += 1.0f;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov, 800./800., perto, longe);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800,800);
    glutCreateWindow("P2");
    glutTimerFunc(0, timer, 0);
    glutDisplayFunc(desenha);
    glutKeyboardFunc(teclado);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(fov, 800./800., perto, longe);
    glMatrixMode(GL_MODELVIEW);
    glutMainLoop();
    return 0;
}
