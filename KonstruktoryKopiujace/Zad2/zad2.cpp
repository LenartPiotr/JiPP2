#include <iostream>
using namespace std;

class Pojazd{
    string nrRej;
    string nazwa;
    int iloscMiejsc;
    string *osoby;
    string marka;
    string typ;
    static int najnowszaWersjaOprogramowania;
    static int zainstalowanaWersjaOprogramowania;
public:
    Pojazd(string nrRej,string nazwa,int iloscMiejsc,string marka,string typ)
        :nrRej(nrRej),nazwa(nazwa),iloscMiejsc(iloscMiejsc),marka(marka),typ(typ){
        osoby = new string[iloscMiejsc];
        for(int i=0; i<iloscMiejsc; i++) osoby[i] = "puste";
    }
    Pojazd(Pojazd &p){
        nrRej = p.nrRej;
        nazwa = p.nazwa;
        iloscMiejsc = p.iloscMiejsc;
        marka = p.marka;
        typ = p.typ;
        osoby = new string[iloscMiejsc];
        for(int i=0; i<iloscMiejsc; i++){
            osoby[i] = p.osoby[i];
        }
    }
    ~Pojazd(){
        delete[] osoby;
    }
    void print(){
        cout<<"Nr rej: "<<nrRej<<"\nNazwa: "<<nazwa<<"\nIlosc miejsc: "<<iloscMiejsc<<
            "\nMarka: "<<marka<<"\nTyp: "<<typ<<"\nOsoby w aucie:\n";
        for(int i=0; i<iloscMiejsc; i++){
            cout<<" * Miejsce "<<i+1<<": "<<osoby[i]<<endl;
        }
    }
    void zmienInformacjeOOsobie(int miejsce, string info){
        osoby[miejsce] = info;
    }

    string getNazwa(){return nazwa;}
    string getNrRej(){return nrRej;}
    string getMarka(){return marka;}
    string getTyp(){return typ;}
    void setNazwa(string nazwa){ this->nazwa=nazwa;}
    void setNrRej(string nrRej){ this->nrRej=nrRej;}

    static void printVersion(){
        cout<<"Zainstalowana wersja oprogramowania: "<<zainstalowanaWersjaOprogramowania<<endl;
    }
    static void updateVersion(){
        zainstalowanaWersjaOprogramowania = najnowszaWersjaOprogramowania;
    }
    static void opublikujNoweOprogramowanie(int wersja){
        najnowszaWersjaOprogramowania = wersja;
    }
};

int Pojazd::najnowszaWersjaOprogramowania = 5;
int Pojazd::zainstalowanaWersjaOprogramowania = 4;

void Zad2(){
    Pojazd p1("KN 12345","nazwa1",2,"marka1","typ1");
    p1.zmienInformacjeOOsobie(0, "Jan Kowalski");
    Pojazd p2 = p1;
    p2.zmienInformacjeOOsobie(1, "Mateusz Nowak");
    p2.setNrRej("KN 12346");
    cout<<"Pojazd1\n";
    p1.print();
    cout<<"Pojazd2\n";
    p2.print();
    Pojazd::printVersion();
    cout<<"Aktualizacja\n";
    Pojazd::updateVersion();
    Pojazd::printVersion();
    cout<<"Nowa wersja oprogramowania\n";
    Pojazd::opublikujNoweOprogramowanie(10);
    cout<<"Aktualizacja\n";
    Pojazd::updateVersion();
    Pojazd::printVersion();
}