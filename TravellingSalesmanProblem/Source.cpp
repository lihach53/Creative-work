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
	cout << "������ �������� ������������ ������ ������������. \n����� ��������� �������� ���������, ������� �� ����� 14 ��������� �������, ����� ������� ��� ����� ��������� �������. \n��� �������� ���������� �������� ������ ����� � ������������ � ��� �������� �������. \n\n\n";
	map = createMap();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	
	glutInitWindowSize(1350, 730);
	glutCreateWindow("�����������");
	WinWeight = glutGet(GLUT_WINDOW_WIDTH);
	WinHeight = glutGet(GLUT_WINDOW_HEIGHT);
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouseClick);
	glutMainLoop();

	return 0;
}

