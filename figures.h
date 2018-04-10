#ifndef FIGURES_H_
#define FIGURES_H_

#include <utility>
#include <vector>
#include <iostream>

class Figure {
public:
	Figure();
	virtual ~Figure();
};

class Circle : public Figure {
public:
	std::pair<double, double> center;
	double radius;
	Circle();
	Circle(double, double, double);
	Circle(const Circle &);
	~Circle();
};

class Polygon : public Figure {
public:
	std::vector<std::pair<double, double>> vertex;
	int num_vertex;
	Polygon();
	Polygon(std::vector<std::pair<double, double>> &);
	Polygon(const Polygon &);
	virtual ~Polygon();
};

class Triangle : public Polygon {
public:
	Triangle();
	Triangle(std::vector<std::pair<double, double>> &);
	Triangle(const Triangle &);
	~Triangle();
};

class Quadrangle : public Polygon {
public:
	Quadrangle();
	Quadrangle(std::vector<std::pair<double, double>> &);
	Quadrangle(const Quadrangle &);
	~Quadrangle();
};

int check_inside(Circle &, Polygon &);

#endif