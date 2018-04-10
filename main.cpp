#include <iostream>
#include <utility>
#include <vector>
#include "figures.h"
#include <string>

int main() {
	double x, y, r;
	std::string polygon;
	std::cout << "Enter the coordinates of circle" << std::endl;
	std::cin >> x >> y;
	std::cout << "Enter the length circle's radius" << std::endl;
	std::cin >> r;
	Circle _circle;
	_circle.center = std::make_pair(x, y);
	_circle.radius = r;
	std::cout << "Enter the polygon: triangle or quadrangle" << std::endl;
	std::cin >> polygon;
	std::vector<std::pair<double, double>> v;
	if (polygon == "triangle") {
		std::cout << "Enter the coordinates of triangle" << std::endl;
		for (int i = 0; i < 3; ++i) {
			std::cin >> x >> y;
			v.push_back(std::make_pair(x, y));
		}
	}
	else if (polygon == "quadrangle") {
		std::cout << "Enter the coordinates of quadrangle" << std::endl;
		for (int i = 0; i < 4; ++i) {
			std::cin >> x >> y;
			v.push_back(std::make_pair(x, y));
		}
	}
	else {
		std::cout << "Incorrect name of polygon!" << std::endl;
		exit(0);
	}
	Polygon p(v);
	int check = check_inside(_circle, p);
	if (check == 1)
		std::cout << "OUTSIDE" << std::endl;
	else if (check == -1)
		std::cout << "INSIDE" << std::endl;
	else
		std::cout << "TOUCH" << std::endl;
	return 0;
}