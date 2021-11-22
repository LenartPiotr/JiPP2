#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

class Figure{
protected:
    string nazwa;
    string kolor;
public:
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
};

class Circle : public Figure{
    double r;
public:
    Circle(double r):r(r){}
    virtual double getArea(){
        return M_PI*r*r;
    }
    virtual double getPerimeter(){
        return 2*M_PI*r;
    }
};

class Rectangle : public Figure{
    double a,b;
public:
    Rectangle(double a,double b):a(a),b(b){}
    virtual double getArea(){
        return a*b;
    }
    virtual double getPerimeter(){
        return 2*a+2*b;
    }
};

int main() {
    Figure *circle = new Circle(5);
    Figure *rectangle = new Rectangle(5, 18);

    cout << "Circle area: " << circle->getArea() << endl;
    cout << "Rectangle area: " << rectangle->getArea() << endl;
    return 0;
}
