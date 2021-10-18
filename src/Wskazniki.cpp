#include "lib.h"
#include <iostream>

using namespace std;

double Zad1(int a,int b){
    int *ptrA = &a;
    int *ptrB = &b;
    return (*ptrA+*ptrB)/2.;
}

void Zad2(){
    int *tab = new int[10];
    cout<<"Wprowadz elementy tablicy: ";
    for(int i=0; i<10; i++){
        cin>>tab[i];
    }
    cout<<"Wartosci wieksze od 0: ";
    for(int i=0; i<10; i++){
        if(*(tab+i)>0) cout<<*(tab+i)<<" ";
    }
    cout<<endl;
}

void Zad3(){
    //
}

void Wskazniki(){
    cout<<Zad1(1,2)<<endl;
    Zad2();
}