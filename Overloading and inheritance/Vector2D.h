#ifndef Vector2D_H
#define Vector2D_H

#include <iostream>
#include <cmath>

class Point2D {
public:

    Point2D() {
        this->x = 0;
        this->y = 0;
    }

    Point2D(float x, float y) : x(x), y(y) {
        this->x = x;
        this->y = y;
    }

    void setDefault() {
        this->x = 1;
        this->y = 1;
    }

    void setParams(float x, float y) {
        setX(x);
        setY(y);
    }

    float distance(Point2D sp = Point2D(0, 0)) {
        // Oblcizenia zgodnie ze wzorem |AB| = ((xa - xb)^2 + (ya - yb)^2)^0.5
        return pow(pow((this->x - sp.x), 2) + pow(this->y - sp.y, 2), 0.5);
    }

    Point2D operator=(const Point2D &obj) {
        this->setParams(obj.x, obj.y);
        return *this;
    }

    friend Point2D operator+(const Point2D &obj1, const Point2D &obj2) {
        return Point2D(obj1.x + obj2.x, obj1.y + obj2.y);
    }

    friend Point2D operator-(const Point2D &obj1, const Point2D &obj2) {
        return Point2D(obj1.x - obj2.x, obj1.y - obj2.y);
    }

    void operator+=(const Point2D &obj) {
        this->x += obj.x;
        this->y += obj.y;
    }

    void operator-=(const Point2D &obj) {
        this->x -= obj.x;
        this->y -= obj.y;
    }

    friend bool operator==(const Point2D &obj1, const Point2D &obj2) {
        return obj1.x == obj2.x && obj1.y == obj2.y;
    }

    friend bool operator!=(const Point2D &obj1, const Point2D &obj2) {
        return !(obj1 == obj2);
    }

    void operator*(float constVal) {
        this->x *= constVal;
        this->y *= constVal;
    }

    void operator/(float constVal) {
        this->x /= constVal;
        this->y /= constVal;
    }

    void operator*=(float constVal) {
        *this * constVal;
    }

    void operator/=(float constVal) {
        *this / constVal;
    }

    friend std::ostream &operator<<(std::ostream &out, const Point2D &obj) {
        return out<<"X: "<<obj.x<<" Y: "<<obj.y<<"\n";
    }

    Point2D(const Point2D &p) {
        x = p.x;
        y = p.y;
    }

    float getX() const {
        return this->x;
    }

    float getY() const {
        return this->y;
    }

protected:
    void setX(float x) {
        this->x = x;
    }

    void setY(float y) {
        this->y = y;
    }

private:
    float x, y;
};

class Vector2D : public Point2D {
public:
    Vector2D() {
        this->A = Point2D(0, 0);
        this->B = Point2D(1, 1);
    }

    Vector2D(Point2D A, Point2D B) : A(A), B(B) {
        this->A = A;
        this->B = B;
    }

    Vector2D(const Vector2D &v) {
        A = v.A;
        B = v.B;
    }

    void setDefault() {
        this->A = Point2D(0, 0);
        this->B = Point2D(1, 1);
    }

    void setPoints(Point2D A, Point2D B) {
        setA(A);
        setB(B);
    }

    float getLength() {
        return this->A.distance(this->B);
    }

    Point2D getA() const {
        return this->A;
    }

    Point2D getB() const {
        return this->B;
    }

    Vector2D operator=(const Vector2D &obj) {
        this->setPoints(obj.A, obj.B);
        return *this;
    }

    friend Vector2D operator+(const Vector2D &obj1, const Vector2D &obj2) {
        return Vector2D(obj1.A + obj2.A, obj1.B + obj2.B);
    }

    friend Vector2D operator-(const Vector2D &obj1, const Vector2D &obj2) {
        return Vector2D(obj1.A - obj2.A, obj1.B - obj2.B);
    }

    void operator+=(const Vector2D &obj) {
        this->A += obj.A;
        this->B += obj.B;
    }

    void operator-=(const Vector2D &obj) {
        this->A -= obj.A;
        this->B -= obj.B;
    }

    friend bool operator==(const Vector2D &obj1, const Vector2D &obj2) {
        return obj1.A == obj2.A && obj1.B == obj2.B;
    }

    friend bool operator!=(const Vector2D &obj1, const Vector2D &obj2) {
        return !(obj1 == obj2);
    }

    void operator*(float constVal) {
        this->A *= constVal;
        this->B *= constVal;
    }

    void operator/(float constVal) {
        this->A /= constVal;
        this->B /= constVal;
    }

    void operator*=(float constVal) {
        *this * constVal;
    }

    void operator/=(float constVal) {
        *this / constVal;
    }

    friend std::ostream &operator<<(std::ostream &out, const Vector2D &obj) {
        return out<<"A = ("<<obj.A.getX()<<","<<obj.A.getY()<<") | B = ( "<<obj.B.getX()<< ","<<obj.B.getY()<<")"<<"\n";
    }

protected:
    void setA(Point2D A) {
        this->A = A;
    }

    void setB(Point2D B) {
        this->B = B;
    }

private:
    Point2D A, B;
};

#endif

