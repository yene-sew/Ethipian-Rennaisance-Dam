#include<windows.h>
#include<GL/glut.h>
#include<iostream>
#include<cstdlib> 


using namespace std;
int cmd = 0;
int car = 0;
int wuha = 0;

struct LightValues {
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
};

// Define two sets of light values: one for day and one for night
LightValues dayTime = {
	{0.8, 0.8, 0.8, 1.0},
	{1.0, 1.0, 1.0, 1.0},
	{0.9, 0.9, 0.9, 1.0}
};

LightValues nightTime = {
	 {0.9, 0.9, 0.4, 1.0},
	{0.8, 0.8, 0.8, 1.0},
	{0.7, 0.9, 0.9, 1.0}
};

bool isDay = true;


void command(char key) {
	switch (key)
	{
	case 'y':
	case 'Y':
	{
		cmd = 1;
		break;
	}

	case 'x':
	case 'X':
	{
		system("cls");
		cout << "              NAME                ID\n";

		cout << "     1. MINTESNOT AYELE      NSR/1535/13\n";
		cout << "     2. SAMUEL FIKRE         NSR/1813/13\n";
		cout << "     2. YENESEW SILESH       NSR/2198/13\n";
	}

	
	

	


	default:
		break;
	}
}



float tx = -15;
float ty = -10.7;
float ttx = -20;
float tty = 2;
float my = 0;
float mx = 0;
float mmy = 0;
float mmx = 0;


void init() {
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-20, 18, -20, 30, -20, 20);
	
}
void timer(int w)
{


	glutTimerFunc(1000 / 60, timer, 0);
	glutPostRedisplay();

	if (car == 2) {



		if ((tx <= 3) && (ty >= -17)) {
			tx += 0.08;
			ty -= 0.03;

			ttx += 0.02;
			tty += 0.01;

		}

		else if ((tx < 20) && (ty <= -11)) {
			tx += 0.08;
			ty += 0.025;
		}



		else {
			tx = -15;
			ty = -10.7;
			ttx = -20;
			tty = 2;
		}
	}
}

void timer2(int w)
{
	glutTimerFunc(1000 / 60, timer2, 0);
	glutPostRedisplay();

	if ((ttx <= 3) && (tty >= -17)) {
		ttx += 0.02;
		tty += 0.01;

	}

	else if ((ttx < 20) && (tty <= -11)) {
		tx += 0.08;
		ty += 0.025;
	}

	else {
	
		ttx = -20;
		tty = 2;
	}
}

//chelema
void night() {
	// Set the light properties
	GLfloat lightPosition[] = { 0.0, 0.0, 2.0, 1.0 };
	GLfloat lightAmbient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat lightDiffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat lightSpecular[] = { 0.1, 0.1, 0.2, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

	// Enable lighting and set the lighting model
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
}

void disp() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(4);





	glBegin(GL_QUADS);

	// semay
	glColor3f(0.0f, 0.0f, 0.9f);
	glVertex2f(20, 30);
	glColor3f(0.0f, 0.0f, 0.9f);
	glVertex2f(-20, 30);
	glColor3f(0.0f, 0.5f, 0.9f);
	glVertex2f(-20, 20);
	glColor3f(0.1f, 0.5f, 0.8f);
	glVertex2f(20, 20);

	// bridge C  sar 1
	glColor3f(0.5f, 1.0f, 0.5f);

	glVertex2f(-10, 20);
	glVertex2f(-20, 20);
	glVertex2f(-20, -20);
	glVertex2f(-8.8, -16.6);

	// water 1
	glColor3f(0.1f, 0.4f, 0.9f);
	glVertex2f(25, 20);
	glVertex2f(-11, 20);
	glColor3f(0.422f, 0.763f, 0.960f);
	glVertex2f(-15, 18);
	glVertex2f(18, 7);

	// dar ginb
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex2f(23, 14.5);
	glVertex2f(18, 8);
	glVertex2f(18, -4);
	glVertex2f(23, -3);



	// bridge C sar 2
	glVertex2f(18, 0);
	glVertex2f(0, -6);
	glVertex2f(-10, -20);
	glVertex2f(18, -20);

	// water 2
	glColor3f(0.422f, 0.763f, 0.960f);
	glVertex2f(-16.5, 5);
	glVertex2f(-10, -10);
	glVertex2f(10, -14);
	glVertex2f(14, -2);


	// water 3
	glColor3f(0.422f, 0.763f, 0.960f);
	glVertex2f(-1, -9);
	glVertex2f(-8, -7);
	glVertex2f(-20, -20);
	glVertex2f(-9, -20);

	// bridge A
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex2f(18, 7);
	glVertex2f(-15, 18);
	glVertex2f(-14, 6.5);
	glVertex2f(18, -4);
	// bridge B yewuhaw mewureja
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2f(9, 9.6);
	glVertex2f(-1, 13);
	glVertex2f(-4, 2.5);
	glVertex2f(5.5, -0.2);


	// bridge J 
	glColor3f(0.3f, 0.3f, 0.3f);

	glVertex2f(5.5, 0.1);
	glVertex2f(0, -4.5);
	glVertex2f(0, -7.0);
	glVertex2f(5.5, -2.7);

	// bridge turbine house 1
	glColor3f(0.7f, 0.7f, 0.7f);

	glVertex2f(-5.5, 5.6);
	glVertex2f(-13.8, 9.6);
	glVertex2f(-14.7, 8.3);
	glVertex2f(-6.2, 4);


	glColor3f(0.9f, 0.9f, 0.9f);

	glVertex2f(-6.2, 4);
	glVertex2f(-14.7, 8.3);
	glVertex2f(-14.8, 7.4);
	glVertex2f(-6.4, 3.2);

	glColor3f(0.7f, 0.7f, 0.7f);

	glVertex2f(-6.4, 3.2);
	glVertex2f(-14.8, 7.4);
	glVertex2f(-15.3, 6.7);
	glVertex2f(-6.8, 2.3);

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex2f(-6.8, 2.3);
	glVertex2f(-15.3, 6.7);
	glVertex2f(-15.3, 3.9);
	glVertex2f(-9.0, 0.5);


	// bridge H terbine house 2


	glColor3f(0.7f, 0.7f, 0.7f);

	glVertex2f(14.8, -1.5);
	glVertex2f(6.5, 2.5);
	glVertex2f(5.5, 1.2);
	glVertex2f(14, -3.1);

	glColor3f(0.9f, 0.9f, 0.9f);

	glVertex2f(14, -3.1);
	glVertex2f(5.5, 1.2);
	glVertex2f(5.5, 0.2);
	glVertex2f(13.9, -3.9);

	glColor3f(0.7f, 0.7f, 0.7f);

	glVertex2f(14, -3.9);
	glVertex2f(5.5, 0.2);
	glVertex2f(5, -0.5);
	glVertex2f(13.5, -4.8);

	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex2f(13.5, -4.8);
	glVertex2f(5, -0.5);
	glVertex2f(5, -3.2);
	glVertex2f(13.2, -7.5);

	glColor3f(0.9f, 0.9f, 0.9f);
	glVertex2f(14.8, -1.5);
	glVertex2f(14, -3.1);
	glVertex2f(13.9, -3.9);
	glVertex2f(14.6, -2.9);

	glColor3f(0.7f, 0.7f, 0.7f);

	glVertex2f(14.6, -2.9);
	glVertex2f(13.5, -4.7);
	glVertex2f(13.2, -7.5);
	glVertex2f(14.2, -6.5);

	// bridge C
	glColor3f(0.5f, 1.0f, 0.5f);

	glVertex2f(-15, 18);
	glVertex2f(-20, 18);
	glVertex2f(-20, 3);
	glVertex2f(-13.8, 9.6);

	// bridge E
	glColor3f(0.3f, 0.3f, 0.3f);

	glVertex2f(-5, 4.7);
	glVertex2f(-10, 1.);
	glVertex2f(-10, -1.5);
	glVertex2f(-5, 2.7);

	// tinishua bet 1
	glColor3f(0.7f, 0.7f, 0.7f);

	glVertex2f(-3.3, 4.2);
	glVertex2f(-5, 4.5);
	glVertex2f(-6, 3.8);
	glVertex2f(-4.3, 3.5);

	glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(-4.3, 3.5);
	glVertex2f(-6, 3.8);
	glVertex2f(-6, 2.7);
	glVertex2f(-4.3, 2.4);




	// bridge D
	glColor3f(0.3f, 0.3f, 0.3f);

	glVertex2f(-3.3, 4.5);
	glVertex2f(-5.5, 2.5);
	glVertex2f(-5.5, 0.5);
	glVertex2f(-4, 2);
	glEnd();
	//miwetaw wuha

	glBegin(GL_POINTS);


	glColor3f(0.8, 0.8, 0.6);
	glVertex2f(-4, -10.9);
	glVertex2f(-5, -10.5);
	glVertex2f(-6, -10);
	glVertex2f(-7, -9.6);
	glVertex2f(-8, -9.2);
	glVertex2f(-9, -8.9);

	glVertex2f(-4.7, -11.9);
	glVertex2f(-5.7, -11.5);
	glVertex2f(-6.7, -11);
	glVertex2f(-7.7, -10.6);
	glVertex2f(-8.7, -10.2);
	glVertex2f(-9.7, -9.9);


	glVertex2f(-5.4, -12.9);
	glVertex2f(-6.4, -12.5);
	glVertex2f(-7.4, -12);
	glVertex2f(-8.4, -11.6);
	glVertex2f(-9.4, -11.2);
	glVertex2f(-10.4, -10.9);


	glVertex2f(-6.1, -13.9);
	glVertex2f(-7.1, -13.5);
	glVertex2f(-8.1, -13);
	glVertex2f(-9.1, -12.6);
	glVertex2f(-10.1, -12.2);
	glVertex2f(-11.1, -11.9);

	glVertex2f(-6.8, -14.9);
	glVertex2f(-7.8, -14.5);
	glVertex2f(-8.8, -14);
	glVertex2f(-9.8, -13.6);
	glVertex2f(-10.8, -13.2);
	glVertex2f(-11.8, -12.9);

	glVertex2f(-7.5, -15.9);
	glVertex2f(-8.5, -15.5);
	glVertex2f(-9.5, -15);
	glVertex2f(-10.5, -14.6);
	glVertex2f(-11.5, -14.2);
	glVertex2f(-12.5, -13.9);

	glVertex2f(-8.2, -16.9);
	glVertex2f(-9.2, -16.5);
	glVertex2f(-10.2, -16);
	glVertex2f(-11.2, -15.6);
	glVertex2f(-12.2, -15.2);
	glVertex2f(-13.2, -14.9);

	glVertex2f(-8.9, -17.9);
	glVertex2f(-9.9, -17.5);
	glVertex2f(-10.9, -17);
	glVertex2f(-11.9, -16.6);
	glVertex2f(-12.9, -16.2);
	glVertex2f(-13.9, -15.9);

	glVertex2f(-9.6, -18.9);
	glVertex2f(-10.6, -18.5);
	glVertex2f(-11.6, -18);
	glVertex2f(-12.6, -17.6);
	glVertex2f(-13.6, -17.2);
	glVertex2f(-14.6, -16.9);

	glVertex2f(-10.3, -19.9);
	glVertex2f(-11.3, -19.5);
	glVertex2f(-12.3, -19);
	glVertex2f(-13.3, -18.6);
	glVertex2f(-14.3, -18.2);
	glVertex2f(-15.3, -17.9);

	glEnd();

	glPushMatrix();
	glTranslatef(mmx, mmy, 0);

	glPointSize(8);
	glBegin(GL_POINTS);


	glColor3f(0.8, 0.8, 0.6);
	glVertex2f(-4, -10.9);
	glVertex2f(-5, -10.5);
	glVertex2f(-6, -10);
	glVertex2f(-7, -9.6);
	glVertex2f(-8, -9.2);
	glVertex2f(-9, -8.9);

	glVertex2f(-4.7, -11.9);
	glVertex2f(-5.7, -11.5);
	glVertex2f(-6.7, -11);
	glVertex2f(-7.7, -10.6);
	glVertex2f(-8.7, -10.2);
	glVertex2f(-9.7, -9.9);


	glVertex2f(-5.4, -12.9);
	glVertex2f(-6.4, -12.5);
	glVertex2f(-7.4, -12);
	glVertex2f(-8.4, -11.6);
	glVertex2f(-9.4, -11.2);
	glVertex2f(-10.4, -10.9);


	glVertex2f(-6.1, -13.9);
	glVertex2f(-7.1, -13.5);
	glVertex2f(-8.1, -13);
	glVertex2f(-9.1, -12.6);
	glVertex2f(-10.1, -12.2);
	glVertex2f(-11.1, -11.9);

	glVertex2f(-6.8, -14.9);
	glVertex2f(-7.8, -14.5);
	glVertex2f(-8.8, -14);
	glVertex2f(-9.8, -13.6);
	glVertex2f(-10.8, -13.2);
	glVertex2f(-11.8, -12.9);

	glVertex2f(-7.5, -15.9);
	glVertex2f(-8.5, -15.5);
	glVertex2f(-9.5, -15);
	glVertex2f(-10.5, -14.6);
	glVertex2f(-11.5, -14.2);
	glVertex2f(-12.5, -13.9);

	glVertex2f(-8.2, -16.9);
	glVertex2f(-9.2, -16.5);
	glVertex2f(-10.2, -16);
	glVertex2f(-11.2, -15.6);
	glVertex2f(-12.2, -15.2);
	glVertex2f(-13.2, -14.9);

	glVertex2f(-8.9, -17.9);
	glVertex2f(-9.9, -17.5);
	glVertex2f(-10.9, -17);
	glVertex2f(-11.9, -16.6);
	glVertex2f(-12.9, -16.2);
	glVertex2f(-13.9, -15.9);

	glVertex2f(-9.6, -18.9);
	glVertex2f(-10.6, -18.5);
	glVertex2f(-11.6, -18);
	glVertex2f(-12.6, -17.6);
	glVertex2f(-13.6, -17.2);
	glVertex2f(-14.6, -16.9);

	glVertex2f(-10.3, -19.9);
	glVertex2f(-11.3, -19.5);
	glVertex2f(-12.3, -19);
	glVertex2f(-13.3, -18.6);
	glVertex2f(-14.3, -18.2);
	glVertex2f(-15.3, -17.9);

	glEnd();
	glPopMatrix();

	glBegin(GL_QUADS);
	// bridge F Asphalt
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex2f(-20, -8);
	glVertex2f(-20, -11);
	glVertex2f(3, -19);
	glVertex2f(3, -15.5);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-15.4, 5.5);
	glVertex2f(-20, 2);
	glVertex2f(-20, 0.5);
	glVertex2f(-15.4, 4);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(20, -14);
	glVertex2f(20, -11);
	glVertex2f(3, -15.5);
	glVertex2f(3, -19);
	glEnd();



	// yewuha mewureja line
	glBegin(GL_LINES);
	glColor3f(0.4f, 0.4f, 0.4f);

	glVertex2f(1, 12.3);
	glVertex2f(0.7, 11.6);

	glVertex2f(3, 11.6);
	glVertex2f(2.7, 10.9);

	glVertex2f(5, 10.9);
	glVertex2f(4.7, 10.25);

	glVertex2f(7, 10.2);
	glVertex2f(6.7, 9.5);


	glEnd();







	// bridge G
	glBegin(GL_LINES);
	// asphalt line

	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2f(-17, -7.9);
	glVertex2f(-3, -13);

	// asphaltu lay yalew mesmer

	glVertex2f(4, -16.8);
	glVertex2f(5.5, -16.3);

	glVertex2f(7, -16);
	glVertex2f(8.5, -15.5);

	glVertex2f(10, -15.1);
	glVertex2f(11.5, -14.55);

	glVertex2f(13, -14.3);
	glVertex2f(14.4, -13.8);

	glVertex2f(16, -13.5);
	glVertex2f(17.5, -13);

	// misosowoch
	glVertex2f(-15, -8.8);
	glVertex2f(-15, -9.6);

	glVertex2f(-12, -9.8);
	glVertex2f(-12, -10.6);

	glVertex2f(-9, -10.8);
	glVertex2f(-9, -11.6);

	glVertex2f(-6, -11.8);
	glVertex2f(-6, -12.6);

	

	// asphalt misoso

	glColor3f(.3f, 0.3f, 0.3f);

	glVertex2f(-15, -12.5);
	glVertex2f(-15, -14);

	

	glVertex2f(-12, -13.6);
	glVertex2f(-12, -16);

	glVertex2f(-9, -14.4);
	glVertex2f(-9, -17);

	glVertex2f(-6, -15.3);
	glVertex2f(-6, -18);

	

	// turbine house 2 kedadoch

	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex2f(9, 4.4);
	glVertex2f(7.4, 2.1);
	glVertex2f(9.3, 4.3);
	glVertex2f(7.7, 2);

	glVertex2f(10.5, 3.7);
	glVertex2f(8.9, 1.3);
	glVertex2f(10.8, 3.6);
	glVertex2f(9.2, 1.2);


	glVertex2f(12, 2.9);
	glVertex2f(10.4, 0.5);
	glVertex2f(12.3, 2.8);
	glVertex2f(10.7, 0.4);

	glVertex2f(13.5, 2.1);
	glVertex2f(11.9, -0.3);
	glVertex2f(13.8, 2);
	glVertex2f(12.2, -0.4);

	glVertex2f(15, 1.3);
	glVertex2f(13.4, -1.1);
	glVertex2f(15.3, 1.2);
	glVertex2f(13.7, -1.2);

	// turbine house 2 mesmer

	glColor3f(0.3f, 0.3f, 0.3f);

	glVertex2f(6, -1);
	glVertex2f(5.9, -3.6);
	glVertex2f(6.3, -1.1);
	glVertex2f(6.2, -3.7);

	glVertex2f(7.5, -1.7);
	glVertex2f(7.4, -4.4);
	glVertex2f(7.8, -1.8);
	glVertex2f(7.7, -4.5);


	glVertex2f(9, -2.5);
	glVertex2f(8.9, -5.2);
	glVertex2f(9.3, -2.6);
	glVertex2f(9.2, -5.3);

	glVertex2f(10.5, -3.3);
	glVertex2f(10.4, -6);
	glVertex2f(10.8, -3.4);
	glVertex2f(10.7, -6.1);

	glVertex2f(12, -4.1);
	glVertex2f(11.9, -6.8);
	glVertex2f(12.3, -4.2);
	glVertex2f(12.2, -6.9);

	// turbine house 1 kedadoch
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex2f(-11.3, 11.5);
	glVertex2f(-12.9, 9.2);
	glVertex2f(-11, 11.4);
	glVertex2f(-12.6, 9.1);

	glVertex2f(-9.8, 10.8);
	glVertex2f(-11.4, 8.5);
	glVertex2f(-9.5, 10.7);
	glVertex2f(-11.1, 8.4);

	glVertex2f(-8.3, 10.1);
	glVertex2f(-9.9, 7.8);
	glVertex2f(-8, 10.);
	glVertex2f(-9.6, 7.7);

	glVertex2f(-6.8, 9.4);
	glVertex2f(-8.4, 7.1);
	glVertex2f(-6.5, 9.3);
	glVertex2f(-8.1, 7.0);

	glVertex2f(-5.3, 8.7);
	glVertex2f(-6.9, 6.4);
	glVertex2f(-5, 8.6);
	glVertex2f(-6.6, 6.3);

	// turbine house 1 mesmer
	glColor3f(0.3f, 0.3f, 0.3f);

	glVertex2f(-14.3, 6.1);
	glVertex2f(-14.4, 3.5);
	glVertex2f(-14, 6);
	glVertex2f(-14.1, 3.4);

	glVertex2f(-12.8, 5.4);
	glVertex2f(-12.9, 2.7);
	glVertex2f(-12.5, 5.3);
	glVertex2f(-12.6, 2.6);


	glVertex2f(-11.3, 4.6);
	glVertex2f(-11.4, 1.9);
	glVertex2f(-11, 4.5);
	glVertex2f(-11.1, 1.8);

	glVertex2f(-9.8, 3.9);
	glVertex2f(-9.9, 1.1);
	glVertex2f(-9.5, 3.7);
	glVertex2f(-9.6, 1);

	glVertex2f(-8.3, 3);
	glVertex2f(-8.4, 2.3);
	glVertex2f(-8, 2.9);
	glVertex2f(-8.1, 2.2);

	// ye tinishu bet kedada 1
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex2f(-5.7, 3.4);
	glVertex2f(-5.7, 3);

	glVertex2f(-5.2, 3.3);
	glVertex2f(-5.2, 2.9);

	

	glEnd();
	glPointSize(15);
	glBegin(GL_POINTS);
	
	glColor3f(0.1f, 0.0f, 0.0f);

	// yeterbine house 1 kedadoch anat 

	glVertex2f(-11, 11.5);
	glVertex2f(-9.5, 10.8);
	glVertex2f(-8.0, 10.1);
	glVertex2f(-6.5, 9.4);
	glVertex2f(-5.0, 8.7);

	// yeterbine house 2 kedadoch anat 

	glVertex2f(9.3, 4.4);
	glVertex2f(10.8, 3.7);
	glVertex2f(12.3, 2.9);
	glVertex2f(13.8, 2.1);
	glVertex2f(15.3, 1.3);


	glEnd();


	//sewuye


	glPushMatrix();
	glTranslatef(ttx, tty, 0);
	glColor3f(0.2, 0.6, 0.8);

	// draw the torso
	glBegin(GL_LINES);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 0.5);
	glEnd();

	// draw the arms
	glBegin(GL_LINES);
	glVertex2f(0.0, 0.4);
	glVertex2f(0.3, 0.2);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0.0, 0.4);
	glVertex2f(-0.3, 0.2);
	glEnd();

	// draw the legs
	glBegin(GL_LINES);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.2, -0.4);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0.0, 0.0);
	glVertex2f(-0.2, -0.4);
	glEnd();

	// add shading to the figure
	glLineWidth(5.0);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-0.1, 0.5);
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(0.1, 0.5);
	glColor3f(0.2, 0.6, 0.8);
	glVertex2f(0.0, 0.9);

	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-0.3, 0.1);
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(-0.1, 0.5);
	glColor3f(0.2, 0.6, 0.8);
	glVertex2f(0.0, 0.2);

	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0.3, 0.1);
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(0.1, 0.5);
	glColor3f(0.2, 0.6, 0.8);
	glVertex2f(0.0, 0.2);

	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-0.2, -0.2);
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(-0.1, 0.0);
	glColor3f(0.2, 0.6, 0.8);
	glVertex2f(0.0, -0.2);

	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0.2, -0.2);
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f(0.1, 0.0);
	glColor3f(0.2, 0.6, 0.8);
	glVertex2f(0.0, -0.2);
	glEnd();
	glPopMatrix();

	//tsahay

	glPushMatrix();
	glTranslatef(17.5, 25, 0);
	glColor3f(0.9f, 0.8f, 0.1f);
	glutSolidSphere(1.5, 20, 20);

	glPopMatrix();

	//damena 1

	glPushMatrix();
	glTranslatef(-18.5, 23, 0);
	glColor3f(0.9f, 0.9f, 0.9f);
	glutSolidSphere(1.1, 20, 20);

	glPopMatrix();


	glPushMatrix();
	glTranslatef(-18.5, 22, 0);
	glutSolidSphere(1.1, 20, 20);

	glPopMatrix();


	glPushMatrix();
	glTranslatef(-17.5, 23, 0);
	glutSolidSphere(1.1, 20, 20);

	glPopMatrix();

	//damena 2

	glPushMatrix();
	glTranslatef(-5, 27, 0);
	glutSolidSphere(1.1, 20, 20);

	glPopMatrix();


	glPushMatrix();
	glTranslatef(-5, 26, 0);
	glutSolidSphere(1.1, 20, 20);

	glPopMatrix();


	glPushMatrix();
	glTranslatef(-4, 27, 0);
	glutSolidSphere(1.1, 20, 20);

	glPopMatrix();

	



	//yemebrat pol ena ampol 2

	glPushMatrix();
	glTranslatef(-17.5, -3, 0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glutSolidSphere(1.3, 20, 20);

	glPopMatrix();

	glBegin(GL_QUADS);
	glColor3f(0.3f, 0.4f, 0.3f);
	glVertex2f(-17.5, -3);
	glVertex2f(-18.5, -3);
	glVertex2f(-18.5, -15);
	glVertex2f(-17.5, -15);
	glEnd();

	// bilon 2
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-18, -4);
	glVertex2f(-18, -4.4);

	glVertex2f(-18, -3.8);
	glVertex2f(-18, -3.4);
	glEnd();




	// mekina
	glPushMatrix();
	glTranslatef(tx, ty, 0);
	glScalef(1.2,1.5,1);
	glColor3f(0.2, 0.5, 0.8);

	// draw the body of the car
	glBegin(GL_QUADS);
	glVertex2f(-0.8, 0.4);
	glVertex2f(0.8, 0.4);
	glVertex2f(0.6, -0.4);
	glVertex2f(-0.6, -0.4);
	glEnd();

	// draw the wheels
	glColor3f(0.1, 0.1, 0.1);
	glPushMatrix();
	glTranslatef(-0.4, -0.4, 0.0);
	glutSolidTorus(0.1, 0.2, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.4, -0.4, 0.0);
	glutSolidTorus(0.1, 0.2, 10, 10);
	glPopMatrix();

	// draw the windows
	glColor3f(0.5, 0.8, 1.0);
	glBegin(GL_QUADS);
	glVertex2f(-0.3, 0.3);
	glVertex2f(0.3, 0.3);
	glVertex2f(0.2, 0.0);
	glVertex2f(-0.2, 0.0);
	glEnd();

	// draw the headlights
	glColor3f(1.0, 0.8, 0.2);
	glPushMatrix();
	glTranslatef(-0.5, 0.4, 0.0);
	glutSolidSphere(0.1, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0.4, 0.0);
	glutSolidSphere(0.1, 10, 10);
	glPopMatrix();

	// draw the grille
	glColor3f(0.1, 0.1, 0.1);
	glBegin(GL_QUADS);
	glVertex2f(-0.1, 0.3);
	glVertex2f(0.1, 0.3);
	glVertex2f(0.1, 0.2);
	glVertex2f(-0.1, 0.2);
	glEnd();

	glPopMatrix();
	
	//yewuhaw fiset
	glBegin(GL_QUADS);
	glColor3f(0.422f, 0.763f, 0.960f);

	glVertex2f(8, 9.6);
	glVertex2f(-1, 12.5);
	glVertex2f(-4, 1);
	glVertex2f(4.5, -1);
	glEnd();

	glPointSize(6);
	glBegin(GL_POINTS);


	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(5, 9.7);
	glVertex2f(6, 9.3);
	glVertex2f(7, 9.1);
	glVertex2f(4, 9.9);
	glVertex2f(3, 10.1);
	glVertex2f(2, 10.3);
	glVertex2f(1, 10.5);

	glVertex2f(4, 7.7);
	glVertex2f(5, 7.3);
	glVertex2f(6, 7.1);
	glVertex2f(3, 7.9);
	glVertex2f(2, 8.1);
	glVertex2f(1, 8.3);
	glVertex2f(0, 8.5);

	glVertex2f(3, 5.7);
	glVertex2f(4, 5.3);
	glVertex2f(5, 5.1);
	glVertex2f(2, 5.9);
	glVertex2f(1, 6.1);
	glVertex2f(0, 6.3);
	glVertex2f(-1, 6.5);

	glVertex2f(2, 3.7);
	glVertex2f(3, 3.3);
	glVertex2f(4, 3.1);
	glVertex2f(1, 3.9);
	glVertex2f(0, 4.1);
	glVertex2f(-1, 4.3);
	glVertex2f(-2, 4.5);


	glEnd();

	glPushMatrix();
	glTranslatef(mx, my, 0);
	//mifesew wuha
	glPointSize(6);
	glBegin(GL_POINTS);
	

	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(5, 9.7);
	glVertex2f(6, 9.3);
	glVertex2f(7, 9.1);
	glVertex2f(4, 9.9);
	glVertex2f(3, 10.1);
	glVertex2f(2, 10.3);
	glVertex2f(1, 10.5);

	glVertex2f(4, 7.7);
	glVertex2f(5, 7.3);
	glVertex2f(6, 7.1);
	glVertex2f(3, 7.9);
	glVertex2f(2, 8.1);
	glVertex2f(1, 8.3);
	glVertex2f(0, 8.5);

	glVertex2f(3, 5.7);
	glVertex2f(4, 5.3);
	glVertex2f(5, 5.1);
	glVertex2f(2, 5.9);
	glVertex2f(1, 6.1);
	glVertex2f(0, 6.3);
	glVertex2f(-1, 6.5);

	glVertex2f(2, 3.7);
	glVertex2f(3, 3.3);
	glVertex2f(4, 3.1);
	glVertex2f(1, 3.9);
	glVertex2f(0, 4.1);
	glVertex2f(-1, 4.3);
	glVertex2f(-2, 4.5);

	glEnd();
	glPopMatrix();



	//yemebrat pol ena ampol 1



	glBegin(GL_QUADS);
	glColor3f(0.3f, 0.4f, 0.3f);
	glVertex2f(-17.5, 17);
	glVertex2f(-18.5, 17);
	glVertex2f(-19.5, 8);
	glVertex2f(-18.5, 8);
	glEnd();

	glPushMatrix();
	glTranslatef(-17.5, 16, 0);
	glColor3f(0.9f, 0.6f, 0.1f);
	glutSolidSphere(1.3, 20, 20);

	glPopMatrix();


	//yemebrat pol ena ampol 3

	glPushMatrix();
	glTranslatef(14.5, -6, 0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glutSolidSphere(1.3, 20, 20);

	glPopMatrix();

	glBegin(GL_QUADS);
	glColor3f(0.3f, 0.4f, 0.3f);
	glVertex2f(14.5, -6);
	glVertex2f(15.5, -6);
	glVertex2f(15.5, -18);
	glVertex2f(14.5, -18);
	glEnd();

	// bilon 3
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(15, -7);
	glVertex2f(15, -7.4);

	glVertex2f(15, -6.8);
	glVertex2f(15, -6.4);
	glEnd();

	// tinishua bet 2
	glBegin(GL_QUADS);

	glColor3f(0.7f, 0.7f, 0.7f);

	glVertex2f(6.6, 1.7);
	glVertex2f(4.3, 2.7);
	glVertex2f(2.8, 1.);
	glVertex2f(5.2, -0.2);

	glColor3f(0.8f, 0.8f, 0.8f);

	glVertex2f(5.2, -0.2);
	glVertex2f(2.8, 1.);
	glVertex2f(2.8, 0.);
	glVertex2f(5.2, -1.2);
	glEnd();

	// ye tinishu bet kedada 2
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);


	glVertex2f(4.45, 2);
	glVertex2f(3.8, 1.2);

	glVertex2f(5.45, 1.7);
	glVertex2f(4.8, 0.9);

	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex2f(3.7, 0.4);
	glVertex2f(3.7, -0.2);

	glVertex2f(4.3, 0.1);
	glVertex2f(4.3, -0.5);

	// ye dildiyu kurach
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex2f(-17, -10.4);
	glVertex2f(-3, -15.5);

	glVertex2f(-15, -11.2);
	glVertex2f(-15, -12.8);

	glVertex2f(-12, -12.2);
	glVertex2f(-12, -13.8);

	glVertex2f(-9, -13.2);
	glVertex2f(-9, -14.8);

	glVertex2f(-6, -14.2);
	glVertex2f(-6, -15.8);

	

	glEnd();


	

	if (isDay) {
		glDisable(GL_LIGHTING);
		
	}
	else {
		night();

	}

	

	glFlush();
}

void water() {
	if (wuha == 1) {

		if (my < 1) {
			my -= 0.005;
			mx -= 0.0025;
			if (my < -4) {
				my = 0;
				mx = 0;
			}
		}

		glutPostRedisplay();
	}
}

void water2() {

	if (mmy < 1) {
		water();
		mmy -= 0.003;
		mmx -= 0.002;
		if (mmy < -9) {
			mmy = 0;
			mmx = 0;
		}
	}
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '1':
		isDay = true;
		glutPostRedisplay(); // Force a redraw to update the lighting
		break;
	case '0':
		isDay = false;
		glutPostRedisplay(); // Force a redraw to update the lighting
		break;

	case 'm':
	case 'M': 
		car = 2;
		break;

	case 's':
	case 'S':
		car = 0;
		break;

	case 'w':
	case 'W':
		wuha = 1;
		break;
	
	case 'q':
	case 'Q':
		wuha = 0;
		break;
	}
}

int main(int argc, char** argv) {


	do {

		cout << "\n\n ########## WELLCOME TO OUR GRAPHICS PROJECT##########\n\n\n";
		cout << "                Choose your option\n\n ";
		cout << "      press 'y' or 'Y' to see the result\n ";
		cout << "      press 'x' or 'X' to see Group members\n ";
		cout << "      press '0' to Exit\n ";

		cout << "      when you access the code\n ";
		cout << "      press '0' make the picture dark\n ";
		cout << "      press '1' make the picture brighter\n ";
		cout << "      press 'w' water flow\n ";
		cout << "      press 'q' to stop water flow\n ";
		cout << "      press 'm' to drive the car\n ";
		cout << "      press 'q' to stop the car\n ";





		char ch;
		cin >> ch;
		command(ch);


		if (cmd == 1) {



			glutInit(&argc, argv);
			glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
			glutInitWindowSize(800, 600);
			glutInitWindowPosition(0, 0);
			glutCreateWindow("Ethio - Rennaissance Dam");
			init();
			glutDisplayFunc(disp);
			glutIdleFunc(water2);
			glutKeyboardFunc(keyboard);
			glutTimerFunc(0, timer, 0);
			glutMainLoop();
		}
	} while (1);
}

