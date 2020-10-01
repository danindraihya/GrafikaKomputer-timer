#include <GL/glut.h>
#include <math.h>
using namespace std;

float sudut = 0.0;
float sudut1 = 0.0;
float sudut2 = 0.0;
float sudut3 = 0.0;
float sudut4 = 0.0;

typedef struct {
	float x;
	float y;
} Point2D_t;

typedef struct {
	float r;
	float g;
	float b;
} Color_t;

void setColor(Color_t col)
{
	glColor3f(col.r, col.g, col.b);
}

void drawLine(Point2D_t pnt[], int n, Color_t color)
{
	int i;
	setColor(color);
	glBegin(GL_LINES);
	for (i = 0; i < n; i++) {
		glVertex2f(pnt[i].x, pnt[i].y);
		}
	glEnd();
}

void drawPolygon(Point2D_t pnt[], int n, Color_t color)
{
	int i;
	setColor(color);
	glBegin(GL_POLYGON);
	for (i = 0; i < n; i++) {
			glVertex2f(pnt[i].x, pnt[i].y);
			}
	glEnd();
}

void drawPolyline(Point2D_t pnt[], int n, Color_t color)
{
	int i;
	setColor(color);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i < n; i++) {
		glVertex2f(pnt[i].x, pnt[i].y);
	}
	glEnd();
}

void drawDot(int x, int y) {
	glColor3f(0.0, 0.0, 1.0);
	glPointSize(5);
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
}

void sumbu_koordinat() {
	Point2D_t sumbuX[2] = { {-200.0, 0.0}, {200.0, 0.0} };
	Point2D_t sumbuY[2] = { {0.0, -200.0}, {0.0, 200.0} };
	Color_t col = {0.0, 0.0, 1.0};
	drawLine(sumbuX, 2, col);
	drawLine(sumbuY, 2, col);
}

void segitiga()
{
	Point2D_t segitiga01[3] = { {-20.0,60.0},{20.0,60.0},{0.0,100.0} };
	Point2D_t segitiga02[3] = { {-20.0,-60.0},{20.0,-60.0},{0.0,-100.0} };
	Point2D_t segitiga03[3] = { {60.0,20.0},{60.0,-20.0},{100.0,0.0} };
	Point2D_t segitiga04[3] = { {-60.0,20.0},{-60.0,-20.0},{-100.0,0.0} };
	Color_t col = { 0.0,1.0,0.0 };
	drawPolygon(segitiga01,3,col);
	drawPolygon(segitiga02,3,col);
	drawPolygon(segitiga03, 3, col);
	drawPolygon(segitiga04, 3, col);

	Color_t col1 = { 1.0,0.0,0.0 };
	Point2D_t segitiga05[3] = { {40.0,40.0},{60.0,100.0},{80.0,40.0} };
	Point2D_t segitiga06[3] = { {-40.0,40.0},{-60.0,100.0},{-80.0,40.0} };
	Point2D_t segitiga07[3] = { {-40.0,-40.0},{-60.0,-100.0},{-80.0,-40.0} };
	Point2D_t segitiga08[3] = { {40.0,-40.0},{60.0,-100.0},{80.0,-40.0} };

	drawPolyline(segitiga05,3,col1);
	drawPolyline(segitiga06, 3, col1);
	drawPolyline(segitiga07, 3, col1);
	drawPolyline(segitiga08, 3, col1);
}

void kotak()
{
	Point2D_t kotak01[4] = { {100.0,40.0}, {100.0,80.0}, {140.0,80.0}, {140.0,40.0} };
	Point2D_t kotak02[4] = { {-100.0,40.0}, {-100.0,80.0}, {-140.0,80.0}, {-140.0,40.0} };
	Point2D_t kotak03[4] = { {-100.0,-40.0}, {-100.0,-80.0}, {-140.0,-80.0}, {-140.0,-40.0} };
	Point2D_t kotak04[4] = { {100.0,-40.0}, {100.0,-80.0}, {140.0,-80.0}, {140.0,-40.0} };
	Color_t col = { 0.0,0.0,1.0 };
	drawPolygon(kotak01, 4, col);
	drawPolygon(kotak02, 4, col);
	drawPolygon(kotak03, 4, col);
	drawPolygon(kotak04, 4, col);
}

void bintang()
{
	Point2D_t bintang01[10]{ {0, 90}, {19,30}, {77,30}, {25,-5}, {47,-60}, {0, -30}, {-47,-60}, {-25,-5}, {-77,30}, {-19,30} };
	Point2D_t bintang02[10]{ {99, 90}, {118, 30}, {176,30}, {124,-5}, {146,-60}, {99,-30}, {52,-60}, {74,-5}, {22,30}, {80,30} };
	Point2D_t bintang03[10]{ {0, 204}, {19,144}, {77, 144}, {25, 109}, {47, 54}, {0, 84}, {-47, 54}, {-25, 109}, {-77, 144}, {-19, 144} };
	Point2D_t bintang04[10]{ {-99, 90}, {-118, 30}, {-176, 30}, {-124, -5}, {-146, -60}, {-99, -30}, {-52, -60}, {-74, -5}, {-22, 30}, {-80, 30} };
	Point2D_t bintang05[10]{ {0, -24}, {19, -84}, {77, -84}, {25, -119}, {47, -174}, {0, -144}, {-47, -174}, {-25, -119}, {-77, -84}, {-19, -84} };
	Color_t col = {1.0, 0.0, 0.0};
	Color_t col1 = {0.0, 0.0, 1.0};
	
	drawPolyline(bintang01, 10, col);
	drawPolyline(bintang02, 10, col1);
	drawPolyline(bintang03, 10, col1);
	drawPolyline(bintang04, 10, col1);
	drawPolyline(bintang05, 10, col1);
}

void lingkaran()
{
	Point2D_t lingkaran1[360];
	Point2D_t lingkaran2[360];
	Point2D_t lingkaran3[360];
	Point2D_t lingkaran4[360];
	Point2D_t lingkaran5[360];
	Color_t col2 = {0.0, 1.0, 0.0};
	Color_t col = {1.0, 0.0, 0.0};
	float r = 50.0;
	for (int i = 0; i < 360; i++) {
		lingkaran1[i].x = (float)(r * cos(i * 3.14 / 100));
		lingkaran1[i].y = (float)(r * sin(i * 3.14 / 100));
	}
	for (int i = 0; i < 360; i++) {
		lingkaran2[i].x = (float)(r * cos(i * 3.14 / 100)) + 100;
		lingkaran2[i].y = (float)(r * sin(i * 3.14 / 100)) + 100;
	}
	for (int i = 0; i < 360; i++) {
		lingkaran3[i].x = (float)(r * cos(i * 3.14 / 100)) - 100;
		lingkaran3[i].y = (float)(r * sin(i * 3.14 / 100)) - 100;
	}

	for (int i = 0; i < 360; i++) {
		lingkaran4[i].x = (float)(r * cos(i * 3.14 / 100)) + 100;
		lingkaran4[i].y = (float)(r * sin(i * 3.14 / 100)) - 100;
	}

	for (int i = 0; i < 360; i++) {
		lingkaran5[i].x = (float)(r * cos(i * 3.14 / 100)) - 100;
		lingkaran5[i].y = (float)(r * sin(i * 3.14 / 100)) + 100;
	}

	drawPolyline(lingkaran1, 360, col);
	drawPolyline(lingkaran2, 360, col2);
	drawPolyline(lingkaran3, 360, col2);
	drawPolyline(lingkaran4, 360, col2);
	drawPolyline(lingkaran5, 360, col2);
}


void titik_berputar(int r)
{
	float teta = (float)(sudut / 57.3);
	int x = (int)(r * cos(teta));
	int y = (int)(r * sin(teta));
	drawDot(x,y);
	sudut = sudut + 1;
	if (sudut <= -360) sudut = 0.0;
}

void titik_berputar1(int r) //kiri bawah
{
	float teta = (float)(sudut1 / 57.3);
	int x = (int)(r * cos(teta) + 100);
	int y = (int)(r * sin(teta) + 100);
	drawDot(x, y);
	sudut1 = sudut1 + 0.5;
	if (sudut1 <= -360) sudut1 = 0.0;
}

void titik_berputar2(int r) //kanan atas
{
	float teta = (float)(sudut2 / 57.3);
	int x = (int)(r * cos(teta) - 100);
	int y = (int)(r * sin(teta) - 100);
	drawDot(x, y);
	sudut2 = sudut2 - 0.3;
	if (sudut2 <= -360) sudut2 = 0.0;
}

void titik_berputar3(int r) //kanan bawah
{
	float teta = (float)(sudut3 / 57.3);
	int x = (int)(r * cos(teta) + 100);
	int y = (int)(r * sin(teta) - 100);
	drawDot(x, y);
	sudut3 = sudut3 + 2;
	if (sudut3 <= -360) sudut3 = 0.0;
}

void titik_berputar4(int r) //kiri atas
{
	float teta = (float)(sudut4 / 57.3);
	int x = (int)(r * cos(teta) - 100);
	int y = (int)(r * sin(teta) + 100);
	drawDot(x, y);
	sudut4 = sudut4 + 0.7;
	if (sudut4 <= -360) sudut4 = 0.5;
}

void tvRusak() {
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5);
	glBegin(GL_POINTS);
	for (int i = 0; i < 220; i++) {
		float a = (float)(rand()%100);
		float b = (float)(rand() % 100);
		glVertex2i(a, b);
		glVertex2i(-a, b);
		glVertex2i(a, -b);
		glVertex2i(-a, -b);
	}
	glEnd();
}

void userdraw(void) {
	// Disini tempat untuk menggambar
	sumbu_koordinat();
	
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	sumbu_koordinat();
	lingkaran();
	titik_berputar(50);
	titik_berputar1(50);
	titik_berputar2(50);
	titik_berputar3(50);
	titik_berputar4(50);
	glFlush();
}

void draw0() {
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void Initialize()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200.0, 200.0, -200.0, 200.0);
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(10, timer, 0);
}


int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(400,400);
	glutCreateWindow("2103181043 Danindra Ihya' Maulalhaq");
	Initialize();
	//glutIdleFunc(draw0);
	glutDisplayFunc(display);
	glutTimerFunc(10, timer, 0);
	glutMainLoop();
	return 0;
}