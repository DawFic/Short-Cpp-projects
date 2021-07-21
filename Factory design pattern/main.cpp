#include "ShapeFactory.h"
using namespace std;
int main() {

    vector<Vector2D> square;

    square.push_back(Vector2D(Point2D(0, 0), Point2D(0, 4)));
    square.push_back(Vector2D(Point2D(0, 4), Point2D(4, 4)));
    square.push_back(Vector2D(Point2D(4, 4), Point2D(4, 0)));
    square.push_back(Vector2D(Point2D(4, 0), Point2D(0, 0)));

	vector<Vector2D> rectangle;

	rectangle.push_back(Vector2D(Point2D(0, 0), Point2D(0, 5)));
	rectangle.push_back(Vector2D(Point2D(0, 5), Point2D(6, 5)));
	rectangle.push_back(Vector2D(Point2D(6, 5), Point2D(6, 0)));
	rectangle.push_back(Vector2D(Point2D(6, 0), Point2D(0, 0)));


	vector<Vector2D> rectangularTriangle;

	rectangularTriangle.push_back(Vector2D(Point2D(0, 0), Point2D(0, 6)));
	rectangularTriangle.push_back(Vector2D(Point2D(0, 6), Point2D(8, 0)));
	rectangularTriangle.push_back(Vector2D(Point2D(8, 0), Point2D(0, 0)));

	vector<Vector2D> trapeze;

	trapeze.push_back(Vector2D(Point2D(0, 0), Point2D(1, 2)));
	trapeze.push_back(Vector2D(Point2D(1, 2), Point2D(3, 2)));
	trapeze.push_back(Vector2D(Point2D(3, 2), Point2D(4, 0)));
	trapeze.push_back(Vector2D(Point2D(4, 0), Point2D(0, 0)));

	vector<Vector2D> diamond;

	diamond.push_back(Vector2D(Point2D(0, 0), Point2D(3, 4)));
	diamond.push_back(Vector2D(Point2D(3, 4), Point2D(8, 4)));
	diamond.push_back(Vector2D(Point2D(8, 4), Point2D(5, 0)));
	diamond.push_back(Vector2D(Point2D(5, 0), Point2D(0, 0)));

	vector<Vector2D> regularHexagon;

	regularHexagon.push_back(Vector2D(Point2D(0, 0), Point2D(-3, 4)));
	regularHexagon.push_back(Vector2D(Point2D(-3, 4), Point2D(0, 8)));
	regularHexagon.push_back(Vector2D(Point2D(0, 8), Point2D(5, 8)));
	regularHexagon.push_back(Vector2D(Point2D(5, 8), Point2D(8, 4)));
	regularHexagon.push_back(Vector2D(Point2D(8, 4), Point2D(5, 0)));
	regularHexagon.push_back(Vector2D(Point2D(5, 0), Point2D(0, 0)));


	ShapeFactory kwadrat(square, SQUARE);
    ShapeFactory prostokat(rectangle, RECTANGLE);
    ShapeFactory trojkat(rectangularTriangle, RECTANGULAR_TRIANGLE);
    ShapeFactory trapez(trapeze,TRAPEZE);
    ShapeFactory romb(diamond,DIAMOND);
    ShapeFactory szesciokat(regularHexagon,REGULAR_HEXAGON);


};