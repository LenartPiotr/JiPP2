#include <iostream>
#include "calc.h"

using namespace std;

double Add(double a,double b){
    return a+b;
}
double Subtract(double a,double b){
    return a-b;
}
double Volume(double a,double b,double h,double H){
    return (a+b)*h/2*H;
}
void Help(){
    cout<<"Simple calculator\n\nDzialania:\n"<<
    "add [a] [b]\n   Dodawanie liczb [a] i [b]\n"<<
    "subtract [a] [b]\n   Odejmowanie liczb [a] i [b]\n"<<
    "volume [a] [b] [c] [d]\n   Obliczanie objetosci graniastoslupa o wysokosci [d]\n"<<
    "   z podstawa trapezu o podstawach [a] i [b] oraz wysokosci [c]\n"<<
    "help\n   Wyswietlenie dokumentacji\n\n";
}