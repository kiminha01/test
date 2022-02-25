#include "OBJ.h"

#define WIDTH 640		// window's width
#define HEIGHT 640		// window's height


OBJ cube;
float angle = 0;
int k = 0;


void idle() {
	angle += 0.1;

	glutPostRedisplay();
}

void drawCube() {
	/* Implement: Draw cube after applying rotation, translation, and scale */

	cube.draw();
}

void renderScene() {
	glClearColor(0, 0, 0, 0);
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Set the correct perspective.
	gluPerspective(45.0f, 1.0f, 0.1f, 100.0f);

	// Reset transformations
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Set the camera
	gluLookAt(10.0f, 10.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	/* Implement: Enable depth testing and call drawCube function */
	glenable(GL_DEPTH_TEST);
	drawCube();
	gldisable(GL_DEPTH_TEST);

	glutSwapBuffers();
}

void main(int argc, char** argv) {
	cube.ReadOBJFile("cube.obj");

	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(650, 300);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Draw a rotating cube");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutIdleFunc(idle);

	// enter GLUT event processing cycle
	glutMainLoop();
}
