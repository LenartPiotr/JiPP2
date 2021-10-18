#include <math.h>
#include <iostream>
#include "lib.h"

using namespace std;

double PoleTrojkata(double a, double h){
    return a*h/2;
}
double PoleTrojkata(double a, double b, double alfa){
    return a*b*sin(alfa)/2;
}
double PoleTrojkata(double a,double b,double c,double R){
    return a*b*c/(4*R);
}
double PoleTrojkata(int a,int b,int c){
    double p = (a+b+c)/2.;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

void PrzeciazanieFunkcji(){
    cout<<PoleTrojkata(2,3)<<endl<<PoleTrojkata(2,3,4)<<endl;
}
