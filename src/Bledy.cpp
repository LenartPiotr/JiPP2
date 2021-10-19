#include <iostream>
#include "lib.h"

using namespace std;

int Dziel(int a,int b){
    if(b==0) throw "Nie dziel przez 0";
    return a/b;
}

int Konwertuj(string s){
    long long num=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]>='0' && s[i]<='9'){
            num*=10;
            num+=s[i]-'0';
            if(num>=INT_MAX) throw "Wprowadzona liczba jest za duza";
        }else if(s[i] != '-' || i != 0) throw "Wprowadzony ciag zawiera nieprawidlowe znaki";
    }
    return s[0]=='-'?-(int)num:(int)num;
}

void Bledy(){
    try {
        cout<<Dziel(4,2)<<"\n";
        cout<<Dziel(15,3)<<"\n";
        cout<<Dziel(2,0)<<"\n";
        cout<<Dziel(1,1);
    }catch(const char *s){
        cout<<"ERROR: "<<s<<endl;
    }
    cout<<"Wprowadz liczbe: ";
    string num;
    cin>>num;
    try {
        cout<<"Liczba: "<<Konwertuj(num)<<endl;
    }catch (const char *s){
        cout<<"ERROR: "<<s<<endl;
    }
}