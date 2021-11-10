#include <iostream>
#include <math.h>

using namespace std;

class Vector{
private:
    double x,y;
public:
    Vector():x(0),y(0){}
    Vector(double x,double y):x(x),y(y){}
    double length(){return sqrt(x*x+y*y);}
    void print(){
        cout<<"("<<x<<", "<<y<<")";
    }

    Vector operator+(const Vector &rhs) const{
        return {x+rhs.x, y+rhs.y};
    }
    Vector &operator+=(const Vector &rhs){
        this->x = this->x + rhs.x;
        this->y = this->y + rhs.y;
        return *this;
    }
};