#include <iostream>
#include <cstdlib>
#include "lib.h"

using namespace std;

int Losowa(int a,int b){
    return rand() % (b-a+1) + a;
}

int Max(int *t,int n){
    int m = t[0];
    for(int i=1; i<n; i++) if(t[i]>m) m = t[i];
    return m;
}

void Reverse(int *t, int n){
    for(int i=0; i<n/2; i++){
        t[i] ^= t[n-i-1] ^= t[i] ^= t[n-i-1];
    }
}

void Tablice(){
    int *tab = new int[20];
    for(int i=0; i<20; i++){
        tab[i] = Losowa(1,100);
        cout<<tab[i]<<" ";
    }
    cout<<"\nNajwieksza wartosc: "<<Max(tab,20)<<endl;
    Reverse(tab, 20);
    cout<<"Odwracanie tablicy\n";
    for(int i=0; i<20; i++){
        cout<<tab[i]<<" ";
    }
    cout<<"\n";
    delete tab;
}