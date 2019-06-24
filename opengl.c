#include <GL/glut.h> 

float xMov = 0, yMov = 0;
float escala = 1.0f;
int altura = 1000, largura = 1000;
float v1[3] = {0.0f, 0.0f, 0.0f};
float v2[3] = {1.0f, 1.0f, 0.0f};
float v3[3] = {1.0f, 1.0f, 1.0f};
float v4[3] = {1.0f, 0.0f, 0.0f};

void desenhaGrade()
{
    glColor3f(0.8f,0.8f,0.8f);
    glBegin(GL_LINES);
    float i = -100;
    for( ; i <= 100; i++)
    {
        glVertex2f(-100, i);
        glVertex2f(100, i);
        glVertex2f(i, -100);
        glVertex2f(i, 100);
    }
    glEnd();
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex2f(-100,0);
    glVertex2f( 100,0);
    glVertex2f(0,-100);
    glVertex2f(0, 100);
    glEnd();
}

void desenhaPoligono(void)
{
    glBegin(GL_POLYGON);
    glColor3f(v1[0], v1[1], v1[2]);
    glVertex2f((0 + xMov) * escala, (2 + yMov) * escala);
    glColor3f(v2[0], v2[1], v2[2]);
    glVertex2f((1 + xMov) * escala, (7 + yMov) * escala);
    glColor3f(v3[0], v3[1], v3[2]);
    glVertex2f((4 + xMov) * escala, (8 + yMov) * escala);
    glColor3f(v4[0], v4[1], v4[2]);
    glVertex2f((7 + xMov) * escala, (4 + yMov) * escala);
    glEnd();
}

void desenhaTela(void)
{
    glClear(GL_COLOR_BUFFER_BIT); 
    desenhaGrade();
    desenhaPoligono();
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
} 

void inicializaTela(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW); 
} 

void funcoesTeclado(unsigned char key, int x, int y)
{
    if(key == 27 || (char)key == 'q' || (char)key == 'Q')
        exit(0);

    if((char)key == 'b' || (char)key == 'b')
    {
        v4[0] = 0.0f;
        v4[1] = 0.0f;
        v4[2] = 1.0f;
    }
    
    if((char)key == 'v' || (char)key == 'V')
    {
        v2[0] = 0.0f;
        v2[1] = 1.0f;
        v2[2] = 0.0f;
    }
}

void funcoesEspeciais(int key, int x, int y)
{
    if(key == GLUT_KEY_UP && yMov < 5) 
        yMov += 1;
    if(key == GLUT_KEY_DOWN && yMov > -15)
        yMov -= 1;
    if(key == GLUT_KEY_RIGHT && xMov < 5)
        xMov += 1;
    if(key == GLUT_KEY_LEFT && xMov > -15)
        xMov -= 1;
    if(key == GLUT_KEY_PAGE_UP)
        escala += 0.5f;
    if(key == GLUT_KEY_PAGE_DOWN && escala > 0.5f)
        escala -= 0.5f;
    if(key == GLUT_KEY_HOME)
    {
        escala = 1.0f;
        xMov = 0.0f;
        yMov = 0.0f;
    }
}

void funcoesMouse(int button, int state, int x, int y){

    if(button == GLUT_LEFT_BUTTON){
        if(state == GLUT_DOWN)
            glScalef(1.5f, 1.5f, 1.5f);
        else if (state == GLUT_UP){
        }
    }else if(button == GLUT_RIGHT_BUTTON){
        if(state == GLUT_DOWN)
            glScalef(0.5f, 0.5f, 0.5f);
        else if(state == GLUT_UP){
        }
    }else if (button == GLUT_MIDDLE_BUTTON){
        if(state == GLUT_DOWN){
        }else if(state == GLUT_UP){
        }
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(largura, altura);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL - Camila e Giovani");
    glViewport(0, 0, largura, altura);
    glutDisplayFunc(desenhaTela);
    glutIdleFunc(desenhaTela);
    glutMouseFunc(funcoesMouse);
    glutKeyboardFunc(funcoesTeclado);
    glutSpecialFunc(funcoesEspeciais);
    inicializaTela();
    glutMainLoop();
}
