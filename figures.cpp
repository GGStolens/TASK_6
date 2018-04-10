#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include "figures.h"

Figure::Figure() {}
Figure::~Figure() {}

Circle::Circle() {
	center = std::make_pair(0, 0);
	radius = 1;
}

Circle::Circle(double x, double y, double r) {
	center = std::make_pair(x, y);
	radius = r;
}

Circle::Circle(const Circle & _circle) {
	center = _circle.center;
	radius = _circle.radius;
}

Circle::~Circle() {}

Polygon::Polygon() {
	vertex.resize(0);
	num_vertex = 0;
}

Polygon::Polygon(std::vector<std::pair<double, double>> & v) {
	vertex = v;
	num_vertex = v.size();
}

Polygon::Polygon(const Polygon & p) {
	vertex = p.vertex;
	num_vertex = p.num_vertex;
}

Polygon::~Polygon() {}

Triangle::Triangle() {
	num_vertex = 3;
	vertex.push_back(std::make_pair(-1, 0));
	vertex.push_back(std::make_pair(0, 1));
	vertex.push_back(std::make_pair(1, 0));
}

Triangle::Triangle(std::vector<std::pair<double, double>> & v) {
	num_vertex = 3;
	for (int i = 0; i < num_vertex; ++i)
		vertex.push_back(std::make_pair(v[i].first, v[i].second));
}

Triangle::Triangle(const Triangle &p) {
	vertex = p.vertex;
}

Triangle::~Triangle() {}

Quadrangle::Quadrangle() {
	num_vertex = 4;
	vertex.push_back(std::make_pair(-1, 0));
	vertex.push_back(std::make_pair(0, 1));
	vertex.push_back(std::make_pair(1, 0));
	vertex.push_back(std::make_pair(0, -1));
}

Quadrangle::Quadrangle(std::vector<std::pair<double, double>> & v) {
	num_vertex = 4;
	for (int i = 0; i < num_vertex; ++i)
		vertex.push_back(std::make_pair(v[i].first, v[i].second));
}

Quadrangle::Quadrangle(const Quadrangle & p) {
	vertex = p.vertex;
}

Quadrangle::~Quadrangle() {}

int check_inside(Circle & c, Polygon & p) {
	int touch = 0;
	for (int i = 0; i < p.num_vertex; ++i) {
		double length = std::sqrt((p.vertex[i].first - c.center.first) * (p.vertex[i].first - c.center.first)
						+ (p.vertex[i].second - c.center.second) * (p.vertex[i].second - c.center.second));
		if (length > c.radius)
			return 1;
		else if (length == c.radius)
			++touch;
	}
	if (touch == p.num_vertex)
		return 0;
	else
		return -1;
}