#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

using namespace std;

class Prostopadloscian{
public:
    int a,b,c;
};

int PoleProstopadloscianu(Prostopadloscian p){
    return p.a*p.b*p.c;
}

class Kula{
public:
    double r;
    double objetosc() const {
        return 4/3.*M_PI*r*r*r;
    }
    double getR(){
        return r;
    }
    void setR(double value){
        r = value;
    }
};

class FunckjaKwadratowa{
    double a,b,c;
public:
    FunckjaKwadratowa(double newA, double newB, double newC){
        a = newA;
        b = newB;
        c = newC;
    }
    void draw() const{
        cout<<"f(x) = "<<a<<" x^2 + "<<b<<" x + "<<c<<"\n";
    }
};

class Student{
public:
    string imie, nazwisko;
    int nrAlbumu, liczbaPytan, poprawneOdpowiedzi;
    void wczytajZKlawiatury(){
        cout<<"Poda imie: ";
        cin>>imie;
        cout<<"Podaj nazwisko: ";
        cin>>nazwisko;
        cout<<"Podaj nr albumu: ";
        cin>>nrAlbumu;
        cout<<"Podaj liczbe pytan: ";
        cin>>liczbaPytan;
        cout<<"Podaj ilosc poprawnych odpowiedzi: ";
        cin>>poprawneOdpowiedzi;
    }
};

Student* WczytajStudenow(int &liczbaStudentow){
    cout<<"Wprowadz liczbe studentow: ";
    cin>>liczbaStudentow;
    Student* studenci = new Student[liczbaStudentow];
    for(int i=0; i<liczbaStudentow; i++) studenci[i].wczytajZKlawiatury();
    return studenci;
}

void LiczIloscPoprawnychOdpowiedzi(Student* s, int liczba){
    int sumaPytan = 0;
    int sumaPopOdp = 0;
    for(int i=0; i<liczba; i++){
        sumaPytan += s[i].liczbaPytan;
        sumaPopOdp += s[i].poprawneOdpowiedzi;
    }
    cout<<"Poprawnych odpowiedzi: "<<sumaPopOdp/(double)sumaPytan*100<<"%\n";
}

void Klasy(){
    Prostopadloscian prostopadloscian = {1,2,3};
    cout<<"Pole prostopadloscianu: "<<PoleProstopadloscianu(prostopadloscian)<<"\n";
    Kula kula = {2};
    cout << "objetosc kuli: " << kula.objetosc() << endl;
    FunckjaKwadratowa func(1,2,3);
    func.draw();
    int liczbaStudentow;
    Student* studenci = WczytajStudenow(liczbaStudentow);
    if(liczbaStudentow != 0)
        LiczIloscPoprawnychOdpowiedzi(studenci, liczbaStudentow);
    delete[] studenci;
}