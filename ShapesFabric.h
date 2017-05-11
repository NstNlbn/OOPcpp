#pragma once

#include "Shapes.h"
#include <string>
#include <time.h>

#define start 1
#define end 10

class ShapesFabric
{
	static int intRand()
	{
		srand(time(0));
		return 1+rand() % 10;
	}

	static double doubleRand()
	{
		double f = (double)intRand() / RAND_MAX;
		return start + f * (end - start);
	}

	static Point & randPoint()
	{
		double x = doubleRand();
		double y = doubleRand();
		return Point(x, y);
	}

public:
	static const std::string point_shape;
	static const std::string circle_shape;
	static const std::string square_shape;
	static const std::string rect_shape;
	static const std::string polyline_shape;
	static const std::string polygon_shape;

	static Shape & CreateShape(std::string name)
	{
		if (name == point_shape)
		{
			return randPoint();
		}
		if (name == circle_shape)
		{ 
			double r = doubleRand();
			Point p = randPoint();
			return Circle(r, p);
		}
		if (name == square_shape)
		{
			double l = doubleRand();
			Point p = randPoint();
			return Square(p, l);
		}
		if (name == rect_shape)
		{
			Point p1 = randPoint();
			Point p2 = randPoint();
			return Rect(p1, p2);
		}
		if (name == polyline_shape)
		{ 
			Polyline polyline;
			int n = intRand();
			for (int i = 0; i < n; i++)
			{
				Point temp_point = randPoint();
				polyline.AddPoint(temp_point);
			}
			return polyline;
		}
		if (name == polygon_shape)
		{
			Polygon polygon;
			int n = intRand();
			for (int i = 0; i < n; i++)
			{
				Point temp_point = randPoint();
				polygon.AddPoint(temp_point);
			}
			return polygon;
		}
	}
};

const std::string ShapesFabric::point_shape = "Point";
const std::string ShapesFabric::circle_shape = "Circle";
const std::string ShapesFabric::square_shape = "Square";
const std::string ShapesFabric::rect_shape = "Rect";
const std::string ShapesFabric::polyline_shape = "Polyline";
const std::string ShapesFabric::polygon_shape = "Polygon";
