#pragma once
#include "Figure.h"
#include "Point.h"

class Polygon : public Figure {
private:
	Point* polygon_points;
	int angles;
public:
	Polygon(Point* arr, int angles);
	~Polygon();
	std::string printClass();
	double getPerimetr();
	double getSquare();
	/*friend std::fstream& operator>>(std::fstream& in, Poligon& polygon);*/
	friend std::ostream& operator<<(std::ostream& out, Polygon& polygon);
};
