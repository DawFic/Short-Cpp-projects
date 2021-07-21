
#ifndef UNTITLED_SHAPE_H
#define UNTITLED_SHAPE_H

#include <iostream>
#include <cmath>
#include "Vector2D.h"
#include <vector>

class Shape {
public:
    Shape() {};

    virtual float getPerimeter() const { return perimeter; }

    virtual float getArea() const { return area; }

    friend std::ostream& operator << (std::ostream& os, const Shape& sh) {
        os << "area: " << sh.area << " perimeter: " << sh.perimeter << std::endl;

        for (short i = 0; i < sh.vectorShape.size(); i++)
        {
            os << "Wektor " << i + 1 << ": A=(" << sh.vectorShape[i].getA().getX() << "," << sh.vectorShape[i].getA().getY() << ") B: (" << sh.vectorShape[i].getB().getX() << "," << sh.vectorShape[i].getB().getY() << ")\n";
        }

        return os;
    }

    bool checkIfCorrectShape(std::vector<Vector2D> vs, bool isCircle = false) //Wektory musza byc ciagle(koniec pierwszego == poczatek nastepnego)
    {

        for (uint8_t i = 0; i < vs.size(); i++)
        {
            if (isCircle)
            {

                if (i > 0 && vs[i].getA() != vs[i - 1].getA())
                    return false;
            }
            else
            {
                if (i > 0 && vs[i].getA() != vs[i - 1].getB())
                    return false;
            }
        }

        return true;
    }

protected:
    virtual void setPerimeter(float newPerimeter) {
        this->perimeter = newPerimeter;
    }

    virtual void setArea(float newArea) { this->area = newArea; }

    virtual void setVectors(std::vector<Vector2D> newVectors) {
        this->vectorShape = newVectors;
    }


private:
    float area{ 0 };
    float perimeter{ 0 };
    std::vector<Vector2D> vectorShape;

};

class Square : public Shape {
public:
    Square(float side) : side(side), Shape() {
        setSide(side);
        //showParameter();
    }

    Square(std::vector<Vector2D>& vectors) {
        if (vectors.size() == 4 && checkIfCorrectShape(vectors) && isSquare(vectors))
        {
            setVectors(vectors);
            setSide(vectors[0].getLength());
        }
        else {
            std::cout << "Error" << std::endl;
        }
    }

    bool isSquare(std::vector<Vector2D> v)
    {
        for (uint8_t i = 0; i < v.size(); i++)
        {
            if (i > 0 && v[i].getLength() != v[i - 1].getLength())
                return false;
        }
        return true;
    }



    void showParameter(){
        std::cout<<"side: "<<side<<std::endl;
    }

    void setSide(float newSide) {
        side = newSide;
        setArea(side * side);
        setPerimeter(4.0f * side);
    }

    float getSide() const {
        return side;
    }

private:
    float side;
};

class RectangularTriangle : public Shape {
public:
    RectangularTriangle(float side_a, float side_b) : side_a(side_a), side_b(side_b), Shape() {
        setSide(side_a, side_b);
        showParameter();
    }

    RectangularTriangle(std::vector<Vector2D>& vectors) {
        if (vectors.size() == 3 && checkIfCorrectShape(vectors) && isRectangularTriangle(vectors))
        {
            setVectors(vectors);
            setSide(vectors[0].getLength(), vectors[2].getLength());
            showParameter();
        }
        else {
            std::cout << "Error" << std::endl;
        }
    }

    bool isRectangularTriangle(std::vector<Vector2D> vectors) {
        return cmpFloat(pow(vectors[0].getLength(), 2.0) + pow(vectors[2].getLength(), 2.0), pow(vectors[1].getLength(), 2.0));
    }

    bool cmpFloat(float x, float y, float epsilon = 0.001f) {
        if (fabs(x - y) < epsilon)
            return true;
        return false;
    }

    void showParameter(){
        std::cout<<"Side a: "<<side_a<<" , Side b: "<<side_b<<" , Side c: "<<side_c<<std::endl;
    }

    void setSide(float new_side_a, float new_side_b){
        side_a = new_side_a;
        side_b = new_side_b;
        side_c = pow(pow(side_a, 2) + pow(side_b, 2), (0.5));
        setArea((side_a * side_b)/2);
        setPerimeter(side_a + side_b + side_c);
    }

    float getSideA() const {
        return side_a;
    }

    float getSideB() const {
        return side_b;
    }
    float getSideC() const {
        return side_c;
    }

private:
    float side_a, side_b, side_c;
};

class Rectangle : public Shape
{
public:

    Rectangle(float side_a, float side_b) : side_a(side_a), side_b(side_b), Shape() {
        setSide(side_a, side_b);
        showParameter();
    }


    Rectangle(std::vector<Vector2D> vectors) {
        if (vectors.size() == 4 && checkIfCorrectShape(vectors) && isRectangle(vectors))
        {
            setVectors(vectors);
            setSide(vectors[0].getLength(), vectors[1].getLength());
            showParameter();
        }
        else {
            std::cout << "Error" << std::endl;
        }
    }

    bool isRectangle(std::vector<Vector2D> v)
    {
        // Sprawdzenie czy boki równoległe są równej długości
        return v[0].getLength() == v[2].getLength() && v[1].getLength() == v[3].getLength();
    }

    void setSide(float new_side_a, float new_side_b){
        side_a = new_side_a;
        side_b = new_side_b;
        setArea(side_a * side_b);
        setPerimeter(2.0f * side_a + 2.0f * side_b);
    }

    void showParameter(){
        std::cout<<"Side a: "<<side_a<<" , Side b: "<<side_b<<std::endl;
    }

    float getSideA() const {
        return side_a;
    }

    float getSideB() const {
        return side_b;
    }

private:
    float side_a, side_b;
};

class Circle : public Shape {
public:
    Circle(float rad) : rad(rad), Shape() {
        setRadius(rad);
        showParameter();
    }

    Circle(std::vector<Vector2D> vectors) {
        if (vectors.size() == 4 && checkIfCorrectShape(vectors, true) && isCircle(vectors))
        {
            setVectors(vectors);
            setRadius(vectors[0].getLength());
            showParameter();
        }
    }

    bool isCircle(std::vector<Vector2D> v)
    {
        for (uint8_t i = 0; i < v.size(); i++)
        {
            if (i > 0 && v[i].getLength() != v[i - 1].getLength())
            {
                return false;
            }
            return true;
        }
    }

    void setRadius(float new_rad){
        rad = new_rad;
        setArea(3.14 * pow(rad, 2));
        setPerimeter(2.0f * 3.14 * rad);
    }

    void showParameter(){
        std::cout<<"Radius: "<<rad<<std::endl;
    }

    float getRadius() const {
        return rad;
    }

private:
    float rad;
};

class Trapeze : public Shape
{
public:
    Trapeze(float side_a, float side_b, float height) : side_a(side_a), side_b(side_b), height(height), Shape() {
        setSide(side_a, side_b, height);
        showParameter();
    }

    Trapeze(std::vector<Vector2D> vectors) {
        bool a = vectors.size() == 4, b = checkIfCorrectShape(vectors), c = isTrapeze(vectors);

        if (vectors.size() == 4 && checkIfCorrectShape(vectors) && isTrapeze(vectors))
        {
            setVectors(vectors);
            setSideFromVectors(vectors);
            showParameter();
        }
    }

    void setSideFromVectors(std::vector<Vector2D> vectors)
    {
        side_a = vectors[3].getLength();
        side_b = vectors[1].getLength();
        side_c = vectors[0].getLength();
        height = sqrt(pow(side_c, 2) - pow(abs(side_a - side_b) / 2, 2));

        setArea(0.5 * height * (side_a + side_b));
        setPerimeter(side_a + side_b + 2.0f * side_c);
    }

    bool isTrapeze(std::vector<Vector2D> vectors)
    {

        //w trapezie równoramiennym przekątne mają tą samą długość
        return vectors[0].getA().distance(vectors[1].getB()) == vectors[0].getB().distance(vectors[2].getB());
    }

    void setSide(float new_side_a, float new_side_b, float new_height){
        side_a = new_side_a;
        side_b = new_side_b;
        height = new_height;


        float new_side_c = pow((pow((abs(side_a - side_b)) / 2, 2) + pow(height, 2)), 0.5);

        side_c = new_side_c;

        setArea(0.5 * height * (side_a + side_b));
        setPerimeter(side_a + side_b + 2.0f * side_c);

    }

    void showParameter(){
        std::cout<<"Side a: "<<side_a<<" , Side b: "<<side_b<<" , Height: "<<height<<", Side c: "<<side_c<<std::endl;
    }


    float getSideA() const {
        return side_a;
    }

    float getSideB() const {
        return side_b;
    }

    float getHeight() const {
        return height;
    }

private:
    float side_a, side_b, side_c, height;
};

class Diamond : public Shape
{
public:

    Diamond(float side, float height) : side(side), height(height), Shape() {
        setSide(side, height);
        showParameter();
    }

    Diamond(std::vector<Vector2D> vectors) {
        if (vectors.size() == 4 && checkIfCorrectShape(vectors) && isDiamond(vectors))
        {
            setVectors(vectors);
            setSideVectors(vectors);
            showParameterVectors(vectors);
        }
    }

    void setSideVectors(std::vector<Vector2D> vectors)
    {
        setArea(vectors[0].getB().distance(vectors[3].getA()) * vectors[0].getB().distance(vectors[1].getB()) * 0.5);
        setPerimeter(4.0 * vectors[0].getLength());
    }

    void showParameterVectors(std::vector<Vector2D> v)
    {
        std::cout << "Przekatna1: " << v[0].getB().distance(v[3].getA()) << "  , Przekata2: " << v[0].getB().distance(v[1].getB()) << std::endl;
    }

    bool isDiamond(std::vector<Vector2D> vectors)
    {
        for (uint8_t i = 0; i < vectors.size(); i++)
        {
            if (i > 0 && vectors[i].getLength() != vectors[i - 1].getLength())
                return false;
        }

        return vectors[0].getB().distance(vectors[3].getA()) != vectors[0].getB().distance(vectors[1].getB());

    }

    void setSide(float new_side, float new_height){
        side = new_side;
        height = new_height;

        setArea(side * height);
        setPerimeter(4.0 * side);
    }

    void showParameter(){
        std::cout<<"Side: "<<side<<"  , Height: "<<height<<std::endl;
    }

    float getSide() const {
        return side;
    }

    float getHeight() const {
        return height;
    }


private:
    float side, height;
};

class RegularHexagon : public Shape
{
public:
    RegularHexagon(float side) : side(side), Shape() {
        setSide(side);
        showParameter();
    }

    RegularHexagon(std::vector<Vector2D> vectors)
    {
        if (vectors.size() == 6 && checkIfCorrectShape(vectors) && isRegularHexagon(vectors))
        {
            setVectors(vectors);
            setSide(vectors[0].getLength());
            showParameter();
        }
    }

    bool isRegularHexagon(std::vector<Vector2D> vectors)
    {
        for (uint8_t i = 0; i < vectors.size(); i++)
        {
            if (i > 0 && vectors[i].getLength() != vectors[i - 1].getLength())
                return false;
            return true;
        }
    }

    void setSide(float new_side){
        side = new_side;
        setArea(6.0f * ((pow(side, 2) * sqrt(3) / 4)));
        setPerimeter(6.0f * side);
    }

    void showParameter() {
        std::cout<<"Side: "<<side<<std::endl;
    }

    float getSide() const {
        return side;
    }

private:
    float side;
};

#endif //UNTITLED_SHAPE_H