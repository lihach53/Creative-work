#include "graph.h"
#include <GL/freeglut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>



int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUS");

	glutInit(&argc, argv);
	cout << "Вашему вниманию представлена задача Коммивояжера. \nЧтобы программа работала корректно, введите не более 14 различных городов, через которые вам нужно проложить маршрут. \nДля удобства заполнения запишите каждый город в соответствии с его серийным номером. \n\n\n";
	graph = Create_Graph();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	
	// Setting interface window options
	glutInitWindowSize(1350, 730);
	glutCreateWindow("Коммивояжер");
	WinW = glutGet(GLUT_WINDOW_WIDTH);
	WinH = glutGet(GLUT_WINDOW_HEIGHT);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMouseFunc(mouseClick);

	glutMainLoop();



	return 0;
}