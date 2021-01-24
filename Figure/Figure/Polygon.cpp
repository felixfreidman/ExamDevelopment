#include "Polygon.h"
#include <cmath>
#include "QuickPow.h"
#include "Point.h"

Polygon::Polygon(Point* arr, int angles) {
	this->angles = angles;
	this->polygon_points = new Point[angles + 1];
	for (size_t i = 0; i < angles + 1; i++)
	{
		this->polygon_points[i] = arr[i];
	}
}

Polygon::~Polygon() {
	delete[] polygon_points;
}

std::string Polygon::printClass()
{
	return "Polygon";
}

double Polygon::getPerimetr() {
	double perimetr = 0;
	for (size_t i = 1; i < angles + 1; i++) {
		perimetr += sqrt(QuickPow::getPower((polygon_points[i] - polygon_points[i - 1]).getX(), 2) + QuickPow::getPower((polygon_points[i] - polygon_points[i - 1]).getY(), 2));
	}
	return perimetr;
}

double Polygon::getSquare() {
	double square = 0;
	for (size_t i = 2; i < angles + 1; i++) {
		Point vector_a = polygon_points[i] - polygon_points[0];
		Point vector_b = polygon_points[i - 1] - polygon_points[0];
		square += (vector_a.getX() * vector_b.getY() - vector_a.getY() * vector_b.getX()) / 2;
	}
	return square;
}

std::ostream & operator<<(std::ostream& out, Polygon& polygon) {
	out << polygon.angles << "\n";
	for (size_t i = 0; i <= polygon.angles; i++) {
		out << polygon.polygon_points[i] << "\n";
	}
	return out;
}
