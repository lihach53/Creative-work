#pragma once
#include <GL/freeglut.h>
#include "SOIL.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

bool pr = false;
vector<int> CommiRoads;

struct CityCoords
{
	int x, y;
};

CityCoords CityCoord[15];

template<class T>
class Map
{
	vector<T> CityList;
public:
	int Matrix[15][15];

	Map() {
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				this->Matrix[i][j] = 0;
			}
		}
	}

	void addCity(const T& City) {
		if (this->CityList.size() == 15) {
			cout << "\nК сожалению, вы хотите ввести для подсчета более 15 городов, что противоречит условиям конкретной задачи";
			return;
		}
		else {
			this->CityList.push_back(City);
		}
	}

	void deleteCity() {
		if (this->CityList.size() == 0) {
			cout << "\nК сожалению, городов в списке больше нет: удалять нечего";
		}
		else {
			this->CityList.pop_back();
		}
	}

	int number(const T& City) {
		for (int i = 0; i < this->CityList.size(); i++) {
			if (this->CityList[i] == City) {
				return i;
			}
		}
		return -1;
	}

	void addRoad(const T& Cityfst, const T& Citysnd, const int len) {
		int Number1, Number2;
		if (this->number(Cityfst) == -1) {
			cout << "\nОшибка. Города с номером " << Citysnd << " не существует\n";
		}
		else {
			if (this->number(Citysnd) == -1) {
				cout << "\nОшибка. Города с номером " << Citysnd << " не существует\n";
			}
			else {
				Number1 = number(Cityfst);
				Number2 = number(Citysnd);

				if (Matrix[Number1][Number2] == 0 && Matrix[Number2][Number1] == 0) {
					this->Matrix[Number1][Number2] = len;
					this->Matrix[Number2][Number1] = len;
				}
				else {
					cout << "\nМежду этими городами уже проложен путь";
				}
			}
		}
	}

	void matrixOutput() {
		if ((this->CityList.size()) == 0) {
			cout << "\nСписок городов пуст. Матрица смежности графа не может быть выведена";
		}
		else {

			cout << "\nМатрица смежности городского графа:\n";
			cout << "\t";
			for (int i = 0; i < CityList.size(); i++) {

				cout << CityList[i] << "\t|\t";
			}
			cout << "\n\n";
			for (int i = 0; i < CityList.size(); i++) {

				cout << CityList[i] << "\t";

				for (int j = 0; j < CityList.size(); j++) {

					cout << this->Matrix[i][j] << "\t|\t";
				}
				cout << "\n\n";
			}
		}
	}

	void mapOutput();

	int getVertPos(const int& vertex);

	~Map() {};
};

int countCity;
int** s;
int* road;
int*** Matrixnew;
int* path;
int WinWeight;
int WinHeight;
int R;
int CityQuantity = 0;
int RoadQuantity = 0;
Map<int> map;

GLuint textureID; 


void loadTexture()
{
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);

	textureID = SOIL_load_OGL_texture("sprite.png", SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	if (textureID == 0) {
		return;
	}
}

void findAnswer(int*** Matrixnew, int countCity, int** HelpMatrix, int* path) {
	for (int l = 0; l < countCity; l++) {
		for (int i = 0; i < countCity; i++) {
			int min = 1000000;
			for (int j = 0; j < countCity; j++) {
				if (Matrixnew[i][j] && min > *Matrixnew[i][j])
					min = *Matrixnew[i][j];
			}
			for (int j = 0; j < countCity; j++) {
				if (Matrixnew[i][j])
					*Matrixnew[i][j] -= min;
			}
		}
		for (int j = 0; j < countCity; j++) {
			int min = 1000000;
			for (int i = 0; i < countCity; i++) {
				if (Matrixnew[i][j] && min > *Matrixnew[i][j])
					min = *Matrixnew[i][j];
			}
			for (int i = 0; i < countCity; i++) {
				if (Matrixnew[i][j])
					*Matrixnew[i][j] -= min;
			}
		}
		for (int i = 0; i < countCity; i++) {
			for (int j = 0; j < countCity; j++)
				HelpMatrix[i][j] = 0;
		}
		for (int i = 0; i < countCity; i++)
			for (int j = 0; j < countCity; j++) {
				if (Matrixnew[i][j] && !*Matrixnew[i][j]) {
					int colmin = 1000000;
					int stringmin = 1000000;
					for (int l = 0; l < countCity; l++)
						if (l != i && Matrixnew[l][j] && colmin > *Matrixnew[l][j])

							colmin = *Matrixnew[l][j];
					for (int l = 0; l < countCity; l++)
						if (l != j && Matrixnew[i][l] && stringmin > *Matrixnew[i][l])
							stringmin = *Matrixnew[i][l];

					HelpMatrix[i][j] = colmin + stringmin;
				}
			}
		int mcost = 0, mi = 0, mj = 0;
		for (int i = 0; i < countCity; i++)
			for (int j = 0; j < countCity; j++)
				if (Matrixnew[i][j] && mcost < HelpMatrix[i][j])
				{
					mcost = HelpMatrix[i][j];
					mi = i;
					mj = j;
				}
		path[mi] = mj;

		for (int i = 0; i < countCity; i++)
			Matrixnew[i][mj] = nullptr;
		for (int i = 0; i < countCity; i++)
			Matrixnew[mi][i] = nullptr;

		Matrixnew[mj][mi] = nullptr;
	}
}

void createMatrix(int***& Matrixnew, int& countCity, int**& s, int*& road) {
	countCity = CityQuantity;
	s = new int* [countCity];
	road = new int[countCity];
	Matrixnew = new int** [countCity];
	for (int i = 0; i <= countCity; i++) {
		s[i] = new int[countCity];
	}
	for (int i = 0; i < countCity; i++) {
		Matrixnew[i] = new int* [countCity];
		for (int j = 0; j < countCity; j++) {
			if (map.Matrix[i][j] == 0) {
				Matrixnew[i][j] = nullptr;
				continue;
			}
			Matrixnew[i][j] = new int(map.Matrix[i][j]);
		}
	}
}

void TSP(int*** Matrixnew, int countCity, int** s, int* road)
{
	CommiRoads.clear();
	createMatrix(Matrixnew, countCity, s, road);
	findAnswer(Matrixnew, countCity, s, road);
	int sumlength = 0;
	for (int i = 0, j = 0; i < countCity; i++) {
		j = road[i];
		sumlength += map.Matrix[i][j];
	}
	cout << "\n\nКратчайший путь, пройденный Коммивояжером ";
	int selLenght = 0;
	for (int l = 0; l < countCity;) {
		for (int i = 0, j = 0; i < countCity; i++) {
			if ((selLenght == 0) || (selLenght == i + 1)) {
				if (selLenght == 0) {
					CommiRoads.push_back(i+1);
					cout << i + 1;
				}
				j = road[i];
				selLenght = j + 1;
				if (selLenght > 0) {
					cout << " -> " << selLenght;
					CommiRoads.push_back(selLenght);
				}
				l++;
			}
		}
	}
	cout << "\n\nОбщая длина пути, который пройдет Коммивояжер: " << sumlength << "\n\n";
	if (pr)
		pr = false;
	else
		pr = true;
}

void ouputRoads(int*** Matrixnew, int countCity, int** s, int* road) {
	createMatrix(Matrixnew, countCity, s, road);
	findAnswer(Matrixnew, countCity, s, road);
	int sumlength = 0;
	cout << "\nВсе пути между городами, по которым пройдет коммивояжер: \n";
	for (int i = 0, j = 0; i < countCity; i++) {
		j = road[i];
		cout << i + 1 << " -> " << j + 1 << '\n';
	}
}

Map <int> createMap() {

	Map<int> Map;
	int first, second, length;
	int* firstCity;
	int* secondCity;
	int* NewCity;

	cout << "\nВведите количество городов, которые необходимо посетить Коммивояжеру : ";
	cout << "\n";
	cin >> CityQuantity;
	cout << "\nВведите количество маршрутов между этими городами: ";
	cout << "\n";
	cin >> RoadQuantity;
	for (int i = 1; i <= CityQuantity; ++i) {
		NewCity = &i;
		Map.addCity(*NewCity); 
	}
	for (int i = 0; i < RoadQuantity; ++i) {
		cout << "\nВведите номер города, из которого начинается маршрут: ";
		cin >> first;
		firstCity = &first;

		cout << "\nВведите номер города, к которому ведет маршрут: ";
		cin >> second;
		secondCity = &second;

		cout << "\n\tВведите расстояние между городами " << first << " и " << second << " : ";
		cin >> length;

		Map.addRoad(*firstCity, *secondCity, length);
	}

	return Map;
}

void saveCity(int i, int countCity)
{
	int NewR;
	int x0 = WinWeight / 2;
	int y0 = WinHeight / 2;
	if (WinWeight > WinHeight)
	{
		R = 5 * (WinHeight / 13) / countCity;
		NewR = WinHeight / 2 - R - 10;
	}
	else {
		R = 5 * (WinWeight / 13) / countCity;
		NewR = WinWeight / 2 - R - 10;
	}
	float theta = 2.0f * 3.1415926f * float(i) / float(countCity);
	float y1 = NewR * cos(theta) + y0;
	float x1 = NewR * sin(theta) + x0;

	CityCoord[i].x = x1;
	CityCoord[i].y = y1;
}

void drawCity(int x, int y, int R)
{

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glColor4f(1.0f, 1.0f, 1.0f, 0.0f);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(x - R, y - R);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(x + R, y - R);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(x + R, y + R);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(x - R, y + R);
	glEnd();
	glFlush();
}


void newTSPText(int nom, int x1, int y1)
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = to_string(nom);
	glRasterPos2i(x1 - 5, y1 - 5);
	for (int j = 0; j < s.length(); j++)
		glutBitmapCharacter(font, s[j]);
}

void newCityText(int nom, int x1, int y1)
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = to_string(nom);
	glColor3f(0.0f, 1.0f, 0.0f);
	glRasterPos2i(x1 - 5, y1 - 5);
	for (int j = 0; j < s.length(); j++) {
		glutBitmapCharacter(font, s[j]);
	}
}

void newText(int nom, int x1, int y1)
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = to_string(nom);
	glColor3f(0.0f, 0.0f, 0.0f); 
	glRasterPos2i(x1 - 5, y1 - 5);
	for (int j = 0; j < s.length(); j++) {
		glutBitmapCharacter(font, s[j]);
	}
}

void drawCity(int countCity)
{
	for (int i = 0; i < countCity; i++) {
		drawCity(CityCoord[i].x, CityCoord[i].y, R);
		newCityText(i + 1, CityCoord[i].x, CityCoord[i].y);
	}
}

void drawRoad(int text, int x0, int y0, int x1, int y1, bool b)
{
	if (b)
		glColor3f(1.0f, 0.0f, 0.0f);
	else
		glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
	if (b) {
		newText(text, (x0 + x1) / 2 - 10, (y0 + y1) / 2 - 10);
	}
	else {
		newText(text, (x0 + x1) / 2 + 10, (y0 + y1) / 2 + 10);
	}
}

void drawTSPRoad(int text, int x0, int y0, int x1, int y1, bool b)
{
	if (b)
		glColor3f(1.0f, 0.0f, 0.0f);
	else
		glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
	if (b) {
		newTSPText(text, (x0 + x1) / 2 - 10, (y0 + y1) / 2 - 10);
	}
	else {
		newTSPText(text, (x0 + x1) / 2 + 10, (y0 + y1) / 2 + 10);
	}
}

template<class T>
void Map<T>::mapOutput()
{
	for (int i = 0; i < CityList.size(); i++) {
		saveCity(i, CityList.size());
	}
	for (int i = 0; i < CityList.size(); i++) {
		for (int j = i + 1; j < CityList.size(); j++) {
			if (Matrix[i][j] != 0) {
				drawRoad(Matrix[i][j], CityCoord[i].x, CityCoord[i].y, CityCoord[j].x, CityCoord[j].y, false);
			}
		}
	}
	drawCity(CityList.size());
}

void reshape(int w, int sumlength) {
	WinWeight = w;
	WinHeight = sumlength;
	glViewport(0, 0, (GLsizei)WinWeight, (GLsizei)WinHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)WinWeight, 0, (GLdouble)WinHeight);
	glutPostRedisplay();
}

void drawMenuText(string text, int x1, int y1)
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = text;
	glRasterPos2i(x1 + 5, y1 - 20);
	for (int j = 0; j < s.length(); j++)
		glutBitmapCharacter(font, s[j]);
}

void drawMenu() {
	int width = 60;
	int lgth = 730;


	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(width, lgth - width - 30);
	glVertex2i(width + 150, lgth - width - 30);
	glVertex2i(width + 150, lgth - width);
	glVertex2i(width, lgth - width);
	glEnd();
	glColor3d(1.0, 1.0, 1.0);
	drawMenuText("Add", width + 60, lgth - width - 2);

	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(width, lgth - width - 70);
	glVertex2i(width + 150, lgth - width - 70);
	glVertex2i(width + 150, lgth - width - 40);
	glVertex2i(width, lgth - width - 40);
	glEnd();
	glColor3d(1.0, 1.0, 1.0);
	drawMenuText("Delete", width + 60, lgth - width - 42);

	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(width, lgth - width - 110);
	glVertex2i(width + 255, lgth - width - 110);
	glVertex2i(width + 255, lgth - width - 80);
	glVertex2i(width, lgth - width - 80);
	glEnd();
	glColor3d(1.0, 1.0, 1.0);
	drawMenuText(" Output the matrix of roads", width, lgth - width - 82);

	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(width, lgth - width - 180);
	glVertex2i(width + 255, lgth - width - 180);
	glVertex2i(width + 255, lgth - width - 120);
	glVertex2i(width, lgth - width - 120);
	glEnd();
	glColor3d(1.0, 1.0, 1.0);
	drawMenuText("Calculate the path traveled by ", width, lgth - width - 122);
	glColor3d(1.0, 1.0, 1.0);
	drawMenuText("a traveling salesman", width + 50, lgth - width - 150);

	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(width, lgth - width - 220);
	glVertex2i(width + 255, lgth - width - 220);
	glVertex2i(width + 255, lgth - width - 190);
	glVertex2i(width, lgth - width - 190);
	glEnd();
	glColor3d(1.0, 1.0, 1.0);
	drawMenuText("    Create new map of roads", width, lgth - width - 190);

	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(width, lgth - width - 230);
	glVertex2i(width + 255, lgth - width - 230);
	glVertex2i(width + 255, lgth - width - 260);
	glVertex2i(width, lgth - width - 260);
	glEnd();
	glColor3d(1.0, 1.0, 1.0);
	drawMenuText("     List of possible roads", width, lgth - width - 230);
}

void mouseClick(int button, int stat, int x, int y) {
	int width = 60;
	int lgth = 730;
	if (stat == GLUT_DOWN) {
		if (x > width && x < width + 135 && y >  width && y < width + 30) {
			int first;
			int second;
			int length;
			int* firstCity;
			int* secondCity;
			cout << "\nНомер добавляемого города: ";
			cin >> first;
			firstCity = &first;
			cout << "\nНомер города, с которым будет связан: ";
			cin >> second;
			cout << "\n\n";
			secondCity = &second;
			if (first > CityQuantity || second > CityQuantity) {
				CityQuantity++;
				int* NewCity = &CityQuantity;
				map.addCity(*NewCity);
			}
			cout << "Длина пути между городами: "; cin >> length; cout << endl;
			map.addRoad(*firstCity, *secondCity, length);
		}
		if (x > width && x < width + 135 && y > width + 40 && y < width + 70) {
			int first;
			int second;
			int length;
			int* firstCity;
			cout << "\nНомер удаляемого города: ";
			cin >> first;
			cout << "\n";
			firstCity = &first;
			if (first == CityQuantity) {
				CityQuantity--;
				map.deleteCity();
			}
			else cout << "\nУдалить это город невозможно \n";
		}
		if (x > width && x < width + 240 && y >  width + 80 && y < width + 100) {
			map.matrixOutput();
		}
		if (x > width && x < width + 240 && y >  width + 120 && y < width + 140) {
			TSP(Matrixnew, countCity, s, road);
		}
		if (x > width && x < width + 240 && y >  width + 160 && y < width + 200) {
			map = createMap();
		}
		if (x > width && x < width + 240 && y >  width + 230 && y < width + 260) {
			ouputRoads(Matrixnew, countCity, s, road);
		}
	}
	glutPostRedisplay();
}

template<class T>
int Map<T>::getVertPos(const int& vertex)
{
	for (size_t i = 0; i < CityList.size(); i++)
		if (CityList[i] == vertex)
			return i;

	return -1;
}

void display() {
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, WinWeight, 0, WinHeight);
	glViewport(0, 0, WinWeight, WinHeight);

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	map.mapOutput();

	if (pr)
	{
		for (int i = 0; i < CommiRoads.size()-1; i++)
		{
			int vertPos1 = map.getVertPos(CommiRoads[i]);
			int vertPos2 = map.getVertPos(CommiRoads[i+1]);
			drawTSPRoad(i + 1, CityCoord[vertPos1].x, CityCoord[vertPos1].y, CityCoord[vertPos2].x, CityCoord[vertPos2].y, true);
		}
	}
	drawMenu();
	glutSwapBuffers();
}


