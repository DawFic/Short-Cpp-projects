#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H


#include <memory>
#include "Shape.h"

#define SQUARE 1
#define RECTANGLE 2
#define RECTANGULAR_TRIANGLE 3
#define DIAMOND 4
#define TRAPEZE 5
#define REGULAR_HEXAGON 6
using namespace std;


class ShapeFactory
{
public:
	void showTriggerClassName();

	ShapeFactory(std::vector<Vector2D> vectors, int type) {shape_pointer = Create(vectors, type);}

	static std::shared_ptr<Shape> Create(std::vector<Vector2D> vectors, uint8_t type)
	{
		//this->classType = type;
		//showTriggerClassName();
		switch (type)
		{
		case SQUARE:
            cout << "SQUARE" << endl;
			return std::make_shared<Square>(Square(vectors));
			break;
		case RECTANGLE:
            cout << "RECTANGLE" << endl;
			return std::make_shared<Rectangle>(Rectangle(vectors));
			break;
		case RECTANGULAR_TRIANGLE:
            cout << "RECTANGULAR_TRIANGLE" << endl;
			return std::make_shared<RectangularTriangle>(RectangularTriangle(vectors));
			break;
		case DIAMOND:
            cout << "DIAMOND" << endl;
			return std::make_shared<Diamond>(Diamond(vectors));
			break;
		case TRAPEZE:
            cout << "TRAPEZE" << endl;
			return std::make_shared<Trapeze>(Trapeze(vectors));
			break;
		case REGULAR_HEXAGON:
            cout << "REGULAR_HEXAGON" << endl;
			return std::make_shared<RegularHexagon>(RegularHexagon(vectors));
			break;
		default:
		    return nullptr;
			break;
		}
	}
protected:
	std::shared_ptr<Shape> getClassType()
	{
		return this->shape_pointer;
	}

private:
    std::shared_ptr<Shape> shape_pointer;
};

#endif
