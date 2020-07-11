#include <windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse (int button, int state, int x,int y);
void mouseMotion (int x,int y);
void ukuran(int, int);

float xrot = 0.0f;
float yrot =0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("Fransiscus Bryan Prasetio - 672018435");
	init();
	glutDisplayFunc(tampil);
	glutReshapeFunc(ukuran);
    glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutMainLoop();
	return 0;
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glPointSize(10.0);
	glLineWidth(5.0);
	is_depth = 1;

}

void mouse (int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y +xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void tampil(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f); //untuk mengatur penglihatan mata/objek
	glRotatef(xrot,1.0f,0.0f,0.0f);
	glRotatef(yrot,0.0f,1.0f,0.0f);

	//depan

	glBegin(GL_QUADS);
	glColor3f(1.5f, 1.5f, 1.5f);
	glVertex3f(-25.0, -20.0, 10.0);
	glVertex3f(-25.0, 35.0, 10.0);
	glVertex3f(50.0, 35.0, 10.0);
	glVertex3f(50.0, -20.0, 10.0);
	glEnd();

	//pintu
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, -20.0, 10.5);
	glVertex3f(0.0, 25.0, 10.5);
	glVertex3f(15.0, 25.0, 10.5);
	glVertex3f(15.0, -20.0, 10.5);
	glEnd();

	//gagangpintu1
	glBegin(GL_POINTS);
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glVertex3f(13.0,0.0,11.0);
	glEnd();

	//jendeladepan1
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(17.0, 5.0, 11.0);
	glVertex3f(17.0, 20.0, 11.0);
	glVertex3f(32.0, 20.0, 11.0);
	glVertex3f(32.0, 5.0, 11.0);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glVertex3f(16.0,12.0,11.5);
	glVertex3f(33.0,12.0,11.5);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glVertex3f(41.5,20.0,11.5);
	glVertex3f(41.5,5.0,11.5);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glVertex3f(34.0,12.0,11.5);
	glVertex3f(48.0,12.0,11.5);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glVertex3f(25,20.0,11.5);
	glVertex3f(25,5.0,11.5);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glVertex3f(-1.0,12.0,11.5);
	glVertex3f(-16.0,12.0,11.5);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glVertex3f(-8,25.0,11.5);
	glVertex3f(-8,0.0,11.5);
	glEnd();

	//jendeladepan1/2
	glBegin(GL_QUADS);
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glVertex3f(16.0, 4.0, 10.5);
	glVertex3f(16.0, 21.0, 10.5);
	glVertex3f(33.0, 21.0, 10.5);
	glVertex3f(33.0, 4.0, 10.5);
	glEnd();

	//jendeladepan2
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(48.0, 5.0, 11);
	glVertex3f(48.0, 20.0, 11);
	glVertex3f(35.0, 20.0, 11);
	glVertex3f(35.0, 5.0, 11);
	glEnd();

	//jendeladepan2/2
	glBegin(GL_QUADS);
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glVertex3f(49.0, 4.0, 10.5);
	glVertex3f(49.0, 21.0, 10.5);
	glVertex3f(34.0, 21.0, 10.5);
	glVertex3f(34.0, 4.0, 10.5);
	glEnd();

	//jendeladepan3
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-15.0, 0.0, 11);
	glVertex3f(-15.0, 25.0, 11);
	glVertex3f(-2.0, 25.0, 11);
	glVertex3f(-2.0, 0.0, 11);
	glEnd();

	//jendeladepan3/3
	glBegin(GL_QUADS);
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glVertex3f(-16.0, -1.0, 10.5);
	glVertex3f(-16.0, 26.0, 10.5);
	glVertex3f(-1.0, 26.0, 10.5);
	glVertex3f(-1.0, -1.0, 10.5);
	glEnd();

	//belakang
	glBegin(GL_QUADS);
	glColor3f(1.5f, 1.5f, 1.5f);
	glVertex3f(-45.0, -20.0, -70.0);
	glVertex3f(-45.0, 35.0, -70.0);
	glVertex3f(50.0, 35.0, -70.0);
	glVertex3f(50.0, -20.0, -70.0);
	glEnd();

	//kaca
	glBegin(GL_QUADS);
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
	glVertex3f(30.0, 5.0, -69.0);
	glVertex3f(30.0, 25.0, -69.0);
	glVertex3f(45.0, 25.0, -69.0);
	glVertex3f(45.0, 5.0, -69.0);
	glEnd();

	//wastafel1
	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3f(30.0, -5.0, -69.0);
	glVertex3f(30.0, 0.0, -69.0);
	glVertex3f(45.0, 0.0, -69.0);
	glVertex3f(45.0, -5.0, -69.0);
	glEnd();

	//wastafel2
	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3f(30.0, -5.0, -66.0);
	glVertex3f(30.0, 0.0, -66.0);
	glVertex3f(45.0, 0.0, -66.0);
	glVertex3f(45.0, -5.0, -66.0);
	glEnd();

	//wastafel3
	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3f(30.0, 0.0, -66.0);
	glVertex3f(30.0, 0.0, -69.0);
	glVertex3f(45.0, 0.0, -66.0);
	glVertex3f(45.0, 0.0, -69.0);
	glEnd();

	//kursi1
	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3f(10.0, 5.0, -69.0);
	glVertex3f(10.0, -5.0, -69.0);
	glVertex3f(20.0, -5.0, -69.0);
	glVertex3f(20.0, 5.0, -69.0);
	glEnd();

	//kursi2
	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3f(10.0, -5.0, -69.0);
	glVertex3f(10.0, -10.0, -69.0);
	glVertex3f(12.0, -10.0, -69.0);
	glVertex3f(12.0, -5.0, -69.0);
	glEnd();

	//kursi3
	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3f(20.0, -5.0, -69.0);
	glVertex3f(20.0, -10.0, -69.0);
	glVertex3f(18.0, -10.0, -69.0);
	glVertex3f(18.0, -5.0, -69.0);
	glEnd();

	//kursi4
	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3f(10.0, -10.0, -69.0);
	glVertex3f(10.0, -10.0, -60.0);
	glVertex3f(20.0, -10.0, -60.0);
	glVertex3f(20.0, -10.0, -69.0);
	glEnd();

	//kursi5
	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3f(20.0, -10.0, -69.0);
	glVertex3f(20.0, -20.0, -69.0);
	glVertex3f(18.0, -20.0, -69.0);
	glVertex3f(18.0, -10.0, -69.0);
	glEnd();

	//kursi6
	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3f(12.0, -10.0, -69.0);
	glVertex3f(12.0, -20.0, -69.0);
	glVertex3f(10.0, -20.0, -69.0);
	glVertex3f(10.0, -10.0, -69.0);
	glEnd();

	//kursi7
	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3f(12.0, -10.0, -60.0);
	glVertex3f(12.0, -20.0, -60.0);
	glVertex3f(10.0, -20.0, -60.0);
	glVertex3f(10.0, -10.0, -60.0);
	glEnd();

	//kursi8
	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3f(20.0, -10.0, -60.0);
	glVertex3f(20.0, -20.0, -60.0);
	glVertex3f(18.0, -20.0, -60.0);
	glVertex3f(18.0, -10.0, -60.0);
	glEnd();


	//kanan
	glBegin(GL_QUADS);
	glColor3f(1.5f, 1.5f, 1.5f);
	glVertex3f(50.0, 35.0, 10.0);
	glVertex3f(50.0, -20.0, 10.0);
	glVertex3f(50.0, -20.0, -70.0);
	glVertex3f(50.0, 35.0, -70.0);
	glEnd();

	//TV1
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(49.0, 0.0, 10.0);
	glVertex3f(49.0, 15.0, 10.0);
	glVertex3f(49.0, 15.0, -10.0);
	glVertex3f(49.0, 0.0, -10.0);
	glEnd();

	//TV2
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(47.0, 0.0, 10.0);
	glVertex3f(47.0, 15.0, 10.0);
	glVertex3f(47.0, 15.0, -10.0);
	glVertex3f(47.0, 0.0, -10.0);
	glEnd();

	//TV3
	glBegin(GL_QUADS);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	glVertex3f(46.5, 2.0, 8.0);
	glVertex3f(46.5, 13.0, 8.0);
	glVertex3f(46.5, 13.0, -8.0);
	glVertex3f(46.5, 2.0, -8.0);
	glEnd();

	//TV4
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(49.0, 0.0, 10.0);
	glVertex3f(49.0, 15.0, 10.0);
	glVertex3f(47.0, 15.0, 10.0);
	glVertex3f(47.0, 0.0, 10.0);
	glEnd();

	//TV5
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(49.0, 0.0, -8.0);
	glVertex3f(49.0, 15.0, -8.0);
	glVertex3f(47.0, 15.0, -8.0);
	glVertex3f(47.0, 0.0, -8.0);
	glEnd();

	//kiri1
	glBegin(GL_QUADS);
	glColor3f(1.5f, 1.5f, 1.5f);
	glVertex3f(-25.0, 35.0, 10.0);
	glVertex3f(-25.0, -20.0, 10.0);
	glVertex3f(-25.0, -20.0, -45.0);
	glVertex3f(-25.0, 35.0, -45.0);
	glEnd();

	//pintukiri
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-27.0, -20.0, -44.6);
	glVertex3f(-27.0, 25.0, -44.5);
	glVertex3f(-43.0, 25.0, -44.5);
	glVertex3f(-43.0, -20.0, -44.5);
	glEnd();

	//gagangpintu2
	glBegin(GL_POINTS);
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glVertex3f(-32.0,0.0,-44);
	glEnd();

	//kiri2
	glBegin(GL_QUADS);
	glColor3f(1.5f, 1.5f, 1.5f);
	glVertex3f(-25.0, -20.0, -45.0);
	glVertex3f(-25.0, 35.0, -45.0);
	glVertex3f(-45.0, 35.0, -45.0);
	glVertex3f(-45.0, -20.0, -45.0);
	glEnd();

	//kiri3
	glBegin(GL_QUADS);
	glColor3f(1.5f, 1.5f, 1.5f);
	glVertex3f(-45.0, 35.0, -45.0);
	glVertex3f(-45.0, -20.0, -45.0);
	glVertex3f(-45.0, -20.0, -70.0);
	glVertex3f(-45.0, 35.0, -70.0);
	glEnd();

	//jendelakiri1
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-26, 30.0, -27.0);
	glVertex3f(-26, 0.0, -27.0);
	glVertex3f(-26, 0.0, -40.0);
	glVertex3f(-26, 30.0, -40.0);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glVertex3f(-26.5, 0.0, -33.0);
	glVertex3f(-26.5, 30.0, -33.0);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glVertex3f(-26.5, 0.0, -17.0);
	glVertex3f(-26.5, 30.0, -17.0);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glVertex3f(-26.5, 0.0, 0.0);
	glVertex3f(-26.5, 30.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glVertex3f(-26.5, 20.0, 8.0);
	glVertex3f(-26.5, 20.0, -40.0);
	glEnd();

	//jendelakiri2
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-26, 30.0, -25.0);
	glVertex3f(-26, 0.0, -25.0);
	glVertex3f(-26, 0.0, -9.0);
	glVertex3f(-26, 30.0, -9.0);
	glEnd();

	//jendelakiri3
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-26, 30.0, -7.0);
	glVertex3f(-26, 0.0, -7.0);
	glVertex3f(-26, 0.0, 7.0);
	glVertex3f(-26, 30.0, 7.0);
	glEnd();

	//jendelakiri4
	glBegin(GL_QUADS);
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glVertex3f(-25.5, 31.0, 8.0);
	glVertex3f(-25.5, -1.0, 8.0);
	glVertex3f(-25.5, -1.0, -41.0);
	glVertex3f(-25.5, 31.0, -41.0);
	glEnd();

	//atas
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-50.0, 35.0, 40.0);
	glVertex3f(50.0, 35.0, 40.0);
	glVertex3f(50.0, 35.0, -70.0);
	glVertex3f(-50.0, 35.0, -70.0);
	glEnd();

	//atap1
	glBegin(GL_TRIANGLES);
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3f(10.0,35.0,10.0);
	glVertex3f(50.0,35.0,10.0);
	glVertex3f(25.0,60.0,-5.0);
	glEnd();

	//atap2
	glBegin(GL_TRIANGLES);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(10.0,35.0,10.0);
	glVertex3f(15.0,35.0,-25.0);
	glVertex3f(25.0,60.0,-5.0);
	glEnd();

	//atap3
	glBegin(GL_TRIANGLES);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(50.0,35.0,10.0);
	glVertex3f(50.0,35.0,-25.0);
	glVertex3f(25.0,60.0,-5.0);
	glEnd();

	//atap4
	glBegin(GL_TRIANGLES);
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3f(15.0,35.0,-25.0);
	glVertex3f(50.0,35.0,-25.0);
	glVertex3f(25.0,60.0,-5.0);
	glEnd();

	//atap5
	glBegin(GL_TRIANGLES);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(-25.0,35.0,-25.0);
	glVertex3f(50.0,35.0,-25.0);
	glVertex3f(20.0,65.0,-40.0);
	glEnd();

	//atap6
	glBegin(GL_TRIANGLES);
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3f(50.0,35.0,-70.0);
	glVertex3f(50.0,35.0,-25.0);
	glVertex3f(20.0,65.0,-40.0);
	glEnd();

	//atap7
	glBegin(GL_TRIANGLES);
	glColor3f(1.0,1.0,0.0);
	glVertex3f(50.0,35.0,-70.0);
	glVertex3f(-25.0,35.0,-70.0);
	glVertex3f(20.0,65.0,-40.0);
	glEnd();

	//atap8
	glBegin(GL_TRIANGLES);
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3f(-25.0,35.0,-25.0);
	glVertex3f(-25.0,35.0,-70.0);
	glVertex3f(20.0,65.0,-40.0);
	glEnd();


	//bawah1
	glBegin(GL_QUADS);
	glColor3f(2.0f, 0.5f, 1.0f);
	glVertex3f(-50.0, -20.0, 50.0);
	glVertex3f(50.0, -20.0, 50.0);
	glVertex3f(50.0, -20.0, -70.0);
	glVertex3f(-50.0, -20.0, -70.0);
	glEnd();

	//vas
	glBegin(GL_QUADS);
	glColor3f(1.5, 1.5, 0.0);
	glVertex3f(25.0, -19.5, 50.0);
	glVertex3f(20.0, -19.5, 50.0);
	glVertex3f(20.0, -19.5, 45.0);
	glVertex3f(25.0, -19.5, 45.0);
	glEnd();

	//vas2
	glBegin(GL_QUADS);
	glColor3f(1.5, 1.5, 0.0);
	glVertex3f(25.0, -19.5, 50.0);
	glVertex3f(26.0, -15.0, 52.0);
	glVertex3f(26.0, -15.0, 43.0);
	glVertex3f(25.0, -19.5, 45.0);
	glEnd();

	//vas3
	glBegin(GL_QUADS);
	glColor3f(1.5, 1.5, 0.0);
	glVertex3f(20.0, -19.5, 50.0);
	glVertex3f(19.0, -15.0, 52.0);
	glVertex3f(19.0, -15.0, 43.0);
	glVertex3f(20.0, -19.5, 45.0);
	glEnd();

	//vas4
	glBegin(GL_QUADS);
	glColor3f(0, 1.5, 1.5);
	glVertex3f(26.0, -15.0, 52.0);
	glVertex3f(19.0, -15.0, 52.0);
	glVertex3f(20.0, -19.5, 50.0);
	glVertex3f(25.0, -19.5, 50.0);
	glEnd();

	//vas5
	glBegin(GL_QUADS);
	glColor3f(0, 1.5, 1.5);
	glVertex3f(26.0, -15.0, 43.0);
	glVertex3f(19.0, -15.0, 43.0);
	glVertex3f(20.0, -19.5, 45.0);
	glVertex3f(25.0, -19.5, 45.0);
	glEnd();

	//vas6
	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3f(25.0, -16, 50.0);
	glVertex3f(20.0, -16, 50.0);
	glVertex3f(20.0, -16, 45.0);
	glVertex3f(25.0, -16, 45.0);
	glEnd();

	//tangkai
	glBegin(GL_LINES);
	glColor3f(0.1f, 0.0f, 0.0f);
	glVertex3f(22.5,-16.0,48.0);
	glVertex3f(22.5,-10.0,48.0);
	glEnd();

	//bunga
	glBegin(GL_POINTS);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(23.0,-10.0,48.0);
	glEnd();

	//bunga
    glBegin(GL_POINTS);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(22.0,-10.0,48.0);
	glEnd();

	//bunga
    glBegin(GL_POINTS);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(22.5,-11.0,49.0);
	glEnd();

	//bunga
    glBegin(GL_POINTS);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(22.5,-11.0,47.0);
	glEnd();

	//bunga
    glBegin(GL_POINTS);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(22.5,-9.0,48.0);
	glEnd();

	//bunga
    glBegin(GL_POINTS);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(23.5,-11.0,47.0);
	glEnd();

	//bunga
    glBegin(GL_POINTS);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(21.5,-11.0,47.0);
	glEnd();


	//bawah2
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.5, 0.0);
	glVertex3f(-60.0, -25.0, 60.0);
	glVertex3f(60.0, -25.0, 60.0);
	glVertex3f(60.0, -25.0, -70.0);
	glVertex3f(-60.0, -25.0, -70.0);
	glEnd();


	//bawah3
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-50.0, -25.0, 50.0);
	glVertex3f(-50.0, -20.0, 50.0);
	glVertex3f(50.0, -20.0, 50.0);
	glVertex3f(50.0, -25.0, 50.0);
	glEnd();

	//bawah4
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-50.0, -25.0, 50.0);
	glVertex3f(-50.0, -20.0, 50.0);
	glVertex3f(-50.0, -20.0, -70.0);
	glVertex3f(-50.0, -25.0, -70.0);
	glEnd();

	//bawah5
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-50.0, -25.0, -70.0);
	glVertex3f(-50.0, -20.0, -70.0);
	glVertex3f(50.0, -20.0, -70.0);
	glVertex3f(50.0, -25.0, -70.0);
	glEnd();

	//bawah6
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(50.0, -25.0, 50.0);
	glVertex3f(50.0, -20.0, 50.0);
	glVertex3f(50.0, -20.0, -70.0);
	glVertex3f(50.0, -25.0, -70.0);
	glEnd();

	//pembatasdepankanan1
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(20.0, -20.0, 40.0);
	glVertex3f(20.0, -5.0, 40.0);
	glVertex3f(50.0, -5.0, 40.0);
	glVertex3f(50.0, -20.0, 40.0);
    glEnd();

    //tiang1
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(47.0, 35.0, 35.0);
	glVertex3f(47.0, -5.0, 35.0);
	glVertex3f(50.0, -5.0, 35.0);
	glVertex3f(50.0, 35.0, 35.0);
	glEnd();

	//tiang2
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(50.0, 35.0, 40.0);
	glVertex3f(50.0, -5.0, 40.0);
	glVertex3f(47.0, -5.0, 40.0);
	glVertex3f(47.0, 35.0, 40.0);
	glEnd();

	//tiang3
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(23.0, 35.0, 40.0);
	glVertex3f(23.0, -5.0, 40.0);
	glVertex3f(20.0, -5.0, 40.0);
	glVertex3f(20.0, 35.0, 40.0);
	glEnd();

	//tiang4
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(23.0, 35.0, 35.0);
	glVertex3f(23.0, -5.0, 35.0);
	glVertex3f(20.0, -5.0, 35.0);
	glVertex3f(20.0, 35.0, 35.0);
	glEnd();

	//tiang5
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-8.0, 35.0, 35.0);
	glVertex3f(-8.0, -5.0, 35.0);
	glVertex3f(-5.0, -5.0, 35.0);
	glVertex3f(-5.0, 35.0, 35.0);
	glEnd();

	//tiang6
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-8.0, 35.0, 40.0);
	glVertex3f(-8.0, -5.0, 40.0);
	glVertex3f(-5.0, -5.0, 40.0);
	glVertex3f(-5.0, 35.0, 40.0);
	glEnd();

	//tiang7
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-50.0, 35.0, 40.0);
	glVertex3f(-50.0, -5.0, 40.0);
	glVertex3f(-47.0, -5.0, 40.0);
	glVertex3f(-47.0, 35.0, 40.0);
	glEnd();

	//tiang8
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-50.0, 35.0, 35.0);
	glVertex3f(-50.0, -5.0, 35.0);
	glVertex3f(-47.0, -5.0, 35.0);
	glVertex3f(-47.0, 35.0, 35.0);
	glEnd();

	//tiang9
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-50.0, 35.0, -5.0);
	glVertex3f(-50.0, -5.0, -5.0);
	glVertex3f(-47.0, -5.0, -5.0);
	glVertex3f(-47.0, 35.0, -5.0);
	glEnd();

	//tiang10
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-50.0, 35.0, -10.0);
	glVertex3f(-50.0, -5.0, -10.0);
	glVertex3f(-47.0, -5.0, -10.0);
	glVertex3f(-47.0, 35.0, -10.0);
	glEnd();

	//tiang11
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-50.0, 35.0, -65.0);
	glVertex3f(-50.0, -5.0, -65.0);
	glVertex3f(-47.0, -5.0, -65.0);
	glVertex3f(-47.0, 35.0, -65.0);
	glEnd();

	//tiang12
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-50.0, 35.0, -70.0);
	glVertex3f(-50.0, -5.0, -70.0);
	glVertex3f(-47.0, -5.0, -70.0);
	glVertex3f(-47.0, 35.0, -70.0);
	glEnd();

	//tiang13
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(50.0, 35.0, 40.0);
	glVertex3f(50.0, -5.0, 40.0);
	glVertex3f(50.0, -5.0, 35.0);
	glVertex3f(50.0, 35.0, 35.0);
	glEnd();

	//tiang14
	glBegin(GL_QUADS);glVertex3f(-50.0, 35.0, 40.0);
	glVertex3f(50.0, 35.0, 40.0);
	glVertex3f(50.0, 35.0, -70.0);
	glVertex3f(-50.0, 35.0, -70.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(47.0, 35.0, 40.0);
	glVertex3f(47.0, -5.0, 40.0);
	glVertex3f(47.0, -5.0, 35.0);
	glVertex3f(47.0, 35.0, 35.0);
	glEnd();

	//tiang15
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(23.0, 35.0, 40.0);
	glVertex3f(23.0, -5.0, 40.0);
	glVertex3f(23.0, -5.0, 35.0);
	glVertex3f(23.0, 35.0, 35.0);
	glEnd();

	//tiang16
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(20.0, 35.0, 40.0);
	glVertex3f(20.0, -5.0, 40.0);
	glVertex3f(20.0, -5.0, 35.0);
	glVertex3f(20.0, 35.0, 35.0);
	glEnd();

	//tiang17
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-8.0, 35.0, 40.0);
	glVertex3f(-8.0, -5.0, 40.0);
	glVertex3f(-8.0, -5.0, 35.0);
	glVertex3f(-8.0, 35.0, 35.0);
	glEnd();

	//tiang18
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-5.0, 35.0, 40.0);
	glVertex3f(-5.0, -5.0, 40.0);
	glVertex3f(-5.0, -5.0, 35.0);
	glVertex3f(-5.0, 35.0, 35.0);
	glEnd();

	//tiang19
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-50.0, 35.0, 40.0);
	glVertex3f(-50.0, -5.0, 40.0);
	glVertex3f(-50.0, -5.0, 35.0);
	glVertex3f(-50.0, 35.0, 35.0);
	glEnd();

	//tiang20
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-47.0, 35.0, 40.0);
	glVertex3f(-47.0, -5.0, 40.0);
	glVertex3f(-47.0, -5.0, 35.0);
	glVertex3f(-47.0, 35.0, 35.0);
	glEnd();

	//tiang21
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-50.0, 35.0, -10.0);
	glVertex3f(-50.0, -5.0, -10.0);
	glVertex3f(-50.0, -5.0, -5.0);
	glVertex3f(-50.0, 35.0, -5.0);
	glEnd();

	//tiang22
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-47.0, 35.0, -5.0);
	glVertex3f(-47.0, -5.0, -5.0);
	glVertex3f(-47.0, -5.0, -10.0);
	glVertex3f(-47.0, 35.0, -10.0);
	glEnd();

	//tiang23
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-50.0, 35.0, -65.0);
	glVertex3f(-50.0, -5.0, -65.0);
	glVertex3f(-50.0, -5.0, -70.0);
	glVertex3f(-50.0, 35.0, -70.0);
	glEnd();

	//tiang24
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-47.0, 35.0, -70.0);
	glVertex3f(-47.0, -5.0, -70.0);
	glVertex3f(-47.0, -5.0, -65.0);
	glVertex3f(-47.0, 35.0, -65.0);
	glEnd();



    //pembatasdepankanan2
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(20.0, -20.0, 35.0);
	glVertex3f(20.0, -5.0, 35.0);
	glVertex3f(50.0, -5.0, 35.0);
	glVertex3f(50.0, -20.0, 35.0);
    glEnd();

    //pembatasdepankanan3
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(20.0, -20.0, 40.0);
	glVertex3f(20.0, -5.0, 40.0);
	glVertex3f(20.0, -5.0, 35.0);
	glVertex3f(20.0, -20.0, 35.0);
    glEnd();

    //pembatasdepankanan4
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(50.0, -20.0, 40.0);
	glVertex3f(50.0, -5.0, 40.0);
	glVertex3f(50.0, -5.0, 10.0);
	glVertex3f(50.0, -20.0, 10.0);
    glEnd();

    //pembatasdepankanan5
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(45.0, -20.0, 40.0);
	glVertex3f(45.0, -5.0, 40.0);
	glVertex3f(45.0, -5.0, 10.0);
	glVertex3f(45.0, -20.0, 10.0);
    glEnd();

    //pembatasdepankanan6
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(45.0, -5.0, 40.0);
	glVertex3f(50.0, -5.0, 40.0);
	glVertex3f(50.0, -5.0, 10.0);
	glVertex3f(45.0, -5.0, 10.0);
	glEnd();

	//pembatasdepankanan7
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(20.0, -5.0, 40.0);
	glVertex3f(45.0, -5.0, 40.0);
	glVertex3f(45.0, -5.0, 35.0);
	glVertex3f(20.0, -5.0, 35.0);
	glEnd();

	//pembatasdepankiri1
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-5.0, -20.0, 40.0);
	glVertex3f(-5.0, -5.0, 40.0);
	glVertex3f(-5.0, -5.0, 35.0);
	glVertex3f(-5.0, -20.0, 35.0);
    glEnd();

    //pembatasdepakiri2
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-5.0, -20.0, 40.0);
	glVertex3f(-5.0, -5.0, 40.0);
	glVertex3f(-50.0, -5.0, 40.0);
	glVertex3f(-50.0, -20.0, 40.0);
    glEnd();

    //pembatasdepakiri3
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-5.0, -20.0, 35.0);
	glVertex3f(-5.0, -5.0, 35.0);
	glVertex3f(-50.0, -5.0, 35.0);
	glVertex3f(-50.0, -20.0, 35.0);
    glEnd();

    //pembatasdepankiri4
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-50.0, -20.0, 40.0);
	glVertex3f(-50.0, -5.0, 40.0);
	glVertex3f(-50.0, -5.0, -70.0);
	glVertex3f(-50.0, -20.0, -70.0);
    glEnd();

    //pembatasdepankiri4
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-45.0, -20.0, 40.0);
	glVertex3f(-45.0, -5.0, 40.0);
	glVertex3f(-45.0, -5.0, -70.0);
	glVertex3f(-45.0, -20.0, -70.0);
    glEnd();

    //pembatasdepankiri5
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-50.0, -20.0, -70.0);
	glVertex3f(-50.0, -5.0, -70.0);
	glVertex3f(-45.0, -5.0, -70.0);
	glVertex3f(-45.0, -20.0, -70.0);
    glEnd();

    //pembatasdepankiri6
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-5.0, -5.0, 40.0);
	glVertex3f(-50.0, -5.0, 40.0);
	glVertex3f(-50.0, -5.0, 35.0);
	glVertex3f(-5.0, -5.0, 35.0);
	glEnd();

	//pembatasdepankiri7
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-45.0, -5.0, -70.0);
	glVertex3f(-50.0, -5.0, -70.0);
	glVertex3f(-50.0, -5.0, 35.0);
	glVertex3f(-45.0, -5.0, 35.0);
	glEnd();

	//kasur1
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-25.0, -20.0, 8.0);
	glVertex3f(-25.0, -10.0, 8.0);
	glVertex3f(5.0, -10.0, 8.0);
	glVertex3f(5.0, -20.0, 8.0);
	glEnd();

	//kasur2
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(-25.0, -10.0, -8.0);
	glVertex3f(5.0, -10.0, -8.0);
	glVertex3f(5.0, -10.0, 8.0);
	glVertex3f(-25.0, -10.0, 8.0);
	glEnd();

	//kasur3
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-25.0, -20.0, -8.0);
	glVertex3f(-25.0, -10.0, -8.0);
	glVertex3f(5.0, -10.0, -8.0);
	glVertex3f(5.0, -20.0, -8.0);
	glEnd();

	//kasur4
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(5.0, -20.0, -8.0);
	glVertex3f(5.0, -10.0, -8.0);
	glVertex3f(5.0, -20.0, 8.0);
	glVertex3f(5.0, -10.0, 8.0);
	glEnd();

	//kasur5
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-25.0, -20.0, -8.0);
	glVertex3f(-25.0, 0.0, -8.0);
	glVertex3f(-25.0, -20.0, 8.0);
	glVertex3f(-25.0, 0.0, 8.0);
	glEnd();
	glPushMatrix();
	glPopMatrix();
	glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '5':
		if (is_depth)
		{
			is_depth = 0;
			glDisable(GL_DEPTH_TEST);
		}
		else
		{
			is_depth = 10;
			glEnable(GL_DEPTH_TEST);
		}
	}
	tampil();
}

void ukuran(int lebar, int tinggi)
{
	if (tinggi == 0) tinggi = 1;
	glMatrixMode(GL_PROJECTION);
	gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}

/*void idle ()
{
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}*/
