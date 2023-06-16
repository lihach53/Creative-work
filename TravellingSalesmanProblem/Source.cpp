#include "graph.h"
#include <GL/freeglut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUS");

	glutInit(&argc, argv);
	cout << "Вашему вниманию представлена задача Коммивояжера. \nЧтобы программа работала корректно, введите не более 15 различных городов, через которые вам нужно проложить маршрут. \nДля удобства заполнения запишите каждый город в соответствии с его серийным номером. \n\n\n";
	map = createMap();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	
	glutInitWindowSize(1350, 730);
	glutCreateWindow("Коммивояжер");
	WinWeight = glutGet(GLUT_WINDOW_WIDTH);
	WinHeight = glutGet(GLUT_WINDOW_HEIGHT);

	loadTexture();
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouseClick);
	glutMainLoop();

	return 0;
}

