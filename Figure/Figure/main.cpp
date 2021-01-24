#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Figure.h"
#include "Triangle.h"
#include "Point.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Polygon.h"

using namespace std;
int main(void) {
	Point first = Point(0, 0);
	Point second = Point(0, 5);
	Point third = Point(2, 0);
	Point triangle_points[3];
	triangle_points[0] = first;
	triangle_points[1] = second;
	triangle_points[2] = third;
	Triangle triangle = Triangle(triangle_points);
	Circle circle = Circle(5);
	Point first_rect = Point(2, 0);
	Point second_rect = Point(2, 4);
	Point third_rect = Point(0, 4);
	Point rect_points[3];
	rect_points[0] = first_rect;
	rect_points[1] = second_rect;
	rect_points[2] = third_rect;
	Rectangle rect = Rectangle(rect_points);
	ifstream in;
	in.open("polygon.txt");
	if (!in.is_open()) {
		cout << "No such file!";
		system("pause");
		return -1;
	}
	int length, x, y;
	in >> length;
	Point* polygon_angles = new Point[length + 1];
	for (size_t i = 0; i < length + 1; i++)
	{
		in >> x >> y;
		polygon_angles[i] = Point(x, y);
	}
	Polygon polygon = Polygon(polygon_angles, length);
	vector<Figure*> figures_array;
	figures_array.push_back(&triangle);
	figures_array.push_back(&circle);
	figures_array.push_back(&rect);
	figures_array.push_back(&polygon);
	for (int i = 0; i < figures_array.size(); i++)
	{
		cout << "Figure # " << i + 1 << " " << figures_array.at(i)->printClass() << ":" << endl;
		cout << "perimetr: " << figures_array.at(i)->getPerimetr() << endl;
		cout << "square: " << figures_array.at(i)->getSquare() << endl;
	}
	system("pause");
	return 1;
}
