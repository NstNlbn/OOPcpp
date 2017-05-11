#pragma once

#include "Base.h"
#include "Container.h"
#include <math.h>
#include <string>

class Shape : public Printable
{
	static int count;
public:
	Shape(void)
	{
		count++;
	}
	static int GetCount()
	{
		return count;
	}
};

int Shape::count = 0;

class Point : public Named, public Shape
{
	double coordinate_x;
	double coordinate_y;
public:
	Point() : Point(0, 0) {}
	Point(double x, double y) : coordinate_x(x), coordinate_y(y), Named("Point") {}
	Point(Point const & point) : Point(point.GetX(), point.GetY()) {}
	double GetX(void) const
	{
		return coordinate_x;
	}
	double GetY(void) const
	{
		return coordinate_y;
	}
	void print(void) const
	{
		std::cout << GetName() << ": " << "(" << coordinate_x << "," << coordinate_y << ")\n";
	}
};

class Circle : public Named, public Shape
{
	double radius;
	Point point;
public:
	Circle(double r, Point con_point) : radius(r), point(con_point), Named("Circle") {}
	double area() const
	{
		return 3.14159 * radius * radius;
	}
	void print(void) const
	{
		std::cout << GetName() << ": \n";
		std::cout << "radius: " << radius << ", area: " << area();
	}
};

class Rect : public Named, public Shape
{
	Point point1;
	Point point2;
	Point point3;
	Point point4;
public:
	Rect(Point con_point1, Point con_point2) : point1(con_point1), point2(con_point2),
		point3(point1.GetX(), point2.GetY()), point4(point2.GetX(), point1.GetY()), Named("Rect") {}
	void print(void) const
	{
		std::cout << GetName() << ": \n";
		point1.print();
		std::cout << ", ";
		point2.print();
		std::cout << ", ";
		point3.print();
		std::cout << ", ";
		point4.print();
	}
};

class Square : public Rect, public Named
{
	double length;
public:
	Square(Point point1, double l) : length(l), Rect (point1, Point(point1.GetX() + length, point1.GetY() + length)),
		Named("Square") {}
	double area() const
	{
		return length * length;
	}
	void print(void) const
	{
		std::cout << Named::GetName() << ": \n";
		std::cout << "length of the side: " << length << ", area: " << area();
	}
};

class Polyline : public Named, public Shape
{
protected:
	Container<Point> points;
	double GetDistance(Point point1, Point point2) const
	{
		return sqrt(pow(point1.GetX() - point2.GetX(), 2) + pow(point1.GetY() - point2.GetY(), 2));
	}
public:
	Polyline() : Named("Polyline") {};
	void AddPoint(Point const & point)
	{
		points.insert_end(point);
	}
	double GetLength(void) const
	{
		double length = 0;
		Point firstpoint = points.GetHead();
		Point temp_point = firstpoint;
		for (Container<Point>::iterator i = points.begin(); i != points.end(); ++i)
		{
			length += GetDistance(*i, temp_point);
			temp_point = (*i);
		}
		return length;
	}
	void print(void) const
	{
		std::cout << GetName() << ": \n";
		std::cout << "Length: " << GetLength() << "\n";
		for (Container<Point>::iterator i = points.begin(); i != points.end(); ++i)
		{
			(*i).print();
		}
	}
};

class Polygon : public Polyline, public Named
{
public:
	Polygon() : Named("Polygon") {};
	double GetLength(void) const
	{
		double length = Polyline::GetLength();
		length += GetDistance(points.GetHead(), points.GetEnd());
		return length;
	}
	void print(void) const
	{
		Polyline::print();
	}
};
