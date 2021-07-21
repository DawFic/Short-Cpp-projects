#include <iostream>
#include "Vector2D.h"

using namespace std;

int main()
{

	Vector2D vector1(Point2D(1,2), Point2D(3,1)), vector2;
    cout<<vector1<<endl;
	cout<<" = "<<endl;
	vector2 = vector1;
	cout<<"Vector2: "<<vector2<<endl;
	cout<<endl;

	cout<<" + "<<endl;
	vector1 = vector2 + Vector2D(Point2D(5, 2), Point2D(3, 2));
	cout<<vector1<<endl;
	cout<<endl;

	cout<<" - "<<endl;
	vector1.setDefault();
	vector1 = vector2 - Vector2D(Point2D(2,4), Point2D(5,1));
	cout<<vector1<<endl;
	cout<<endl;

	cout<<" += "<<endl;
	vector1.setDefault();
	vector1 += Vector2D(Point2D(3, 0), Point2D(1, 0));
	cout<<vector1<<endl;
	cout<<endl;

	cout<<" -= "<<endl;
	vector1.setDefault();
	vector1 -= Vector2D(Point2D(5, 2), Point2D(3, 4));
    cout<<vector1<<endl;
    cout<<endl;

    cout<<" == "<<endl;
	vector1.setDefault();
	cout<<(vector1 == vector2 ? "True" : "False")<<endl;
    cout<<endl;

    cout<<" != "<<endl;
	cout<< (vector1 != vector2 ? "True" : "False")<<endl;
    cout<<endl;

    cout<<" * "<<endl;
	vector1 * 4;
    cout<<vector1<<endl;
    cout<<endl;

    cout<<" / "<<endl;
	vector1.setDefault();
	vector1 / 2;
    cout<<vector1<<endl;
    cout<<endl;

    cout<<" *= "<<endl;
	vector1.setDefault();
	vector1 *= 3;
    cout<<vector1<<endl;
    cout<<endl;

    cout<<" /= "<<endl;
	vector1.setDefault();
	vector1 /= 4;
    cout<<vector1<<endl;
    cout<<endl;

    cout<<" << "<<endl;
	vector1.setDefault();
    cout<<vector1<<endl;
    cout<<endl;

	cout<<"Dlugosc Vector1: "<<vector1.getLength()<<endl;

}