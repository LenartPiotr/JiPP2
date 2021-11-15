#include <iostream>
#include "include.h"

using namespace std;

ImaginaryNumber::ImaginaryNumber():v(0){}
ImaginaryNumber::ImaginaryNumber(double x):v(x){}
void ImaginaryNumber::print() const {
    cout<<v<<"i";
}
ImaginaryNumber ImaginaryNumber::operator+(const ImaginaryNumber &rhs)const{
    return {v+rhs.v};
}
double ImaginaryNumber::operator*(const ImaginaryNumber &rhs)const{
    return -(v*rhs.v);
}