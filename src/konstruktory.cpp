#include <iostream>
#include <math.h>

using namespace std;

class Punkt{
public:
    double x,y;
    Punkt(double X,double Y);
    double DistanceTo(Punkt p) const;
};

Punkt::Punkt(double X, double Y) :x(X),y(Y) {}
double Punkt::DistanceTo(Punkt p) const {
    return sqrt(pow(x-p.x,2)+pow(y-p.y,2));
}

void Konstruktory(){
    //
}