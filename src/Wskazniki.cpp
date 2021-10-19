#include "lib.h"
#include <iostream>
#include <algorithm>

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

void Swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void QuickSort(int **t, int l, int r){
    if(r<=l)return;
    int i=l-1, j=r+1, p=*t[l];
    while(true){
        while(p>*t[++i]);
        while(p<*t[--j]);
        if(i<=j) Swap(t[i],t[j]);
        else break;
    }
    if(j>l) QuickSort(t,l,j);
    if(i<r) QuickSort(t,i,r);
}

void Zad3(int *a,int *b,int *c,int *d){
    int *tab[4]{a,b,c,d};
    QuickSort(tab,0,3);
}

void Zad4(int x, int **w){
    *w = &x;
}

void Wskazniki(){
    cout<<Zad1(1,2)<<endl;
    Zad2();
    int a = 12;
    int b = 3;
    int c = 8;
    int d = 5;
    Zad3(&a, &b, &c, &d);
    cout<<"Po sortowaniu: "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    int *w;
    Zad4(a,&w);
    cout<<*w<<endl;
}