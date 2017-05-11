#include "ShapesFabric.h"

int main()
{
	/*
	Shape * shapes[5];
	shapes[0] = &ShapesFabric::CreateShape(ShapesFabric::point_shape);
	shapes[1] = &ShapesFabric::CreateShape(ShapesFabric::circle_shape);
	shapes[2] = &ShapesFabric::CreateShape(ShapesFabric::rect_shape);
	shapes[3] = &ShapesFabric::CreateShape(ShapesFabric::polyline_shape);
	shapes[4] = &ShapesFabric::CreateShape(ShapesFabric::polygon_shape);
	*/

	Shape & point = ShapesFabric::CreateShape(ShapesFabric::point_shape);

	// Ошибка "нарушение доступа для чтения", убила кучу времени, но так и не поняла почему :(
	point.print();

	std::cout << Shape::GetCount() << "\n";
	/*
	for (int i = 0; i < 5; i++)
	{
		(*(shapes[0])).print();
	}
	*/
	getchar();
}
