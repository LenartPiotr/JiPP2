#include <iostream>

using namespace std;

struct bnowy{
    string marka;
    string model;
    int rokProdukcji;
    string kolor;
    double ocena;
};

void Zad1(){
    bnowy samochody[] = {
            {"AUDI","model 01",2000,"szary",9},
            {"BMW","model 58",1998,"czarny",10},
            {"OPEL","model 100",2015,"srebrny",8.5},
            {"BMW","taki model",2020,"bialy",6.75}
    };
    cout<<"Index\tMarka\tModel\t\tRok\tKolor\tOcena\n";
    for(int i=0; i<4; i++){
        cout<<i<<"\t"<<samochody[i].marka<<"\t"<<samochody[i].model<<"\t"<<samochody[i].rokProdukcji<<"\t"<<
            samochody[i].kolor<<"\t"<<samochody[i].ocena<<"\n";
    }
}

int IleTejSamejMarki(bnowy samochody[], int size, string marka){
    int count = 0;
    for(int i=0; i<size; i++){
        if(samochody[i].marka==marka) count++;
    }
    return count;
}

int KtoryRokNajnizszy(bnowy samochody[], int size){
    int min = samochody[0].rokProdukcji;
    int index = 0;
    for(int i=1; i<size; i++){
        if(samochody[i].rokProdukcji<min){
            min=samochody[i].rokProdukcji;
            index = i;
        }
    }
    return index;
}

void Zad3(){
    bnowy samochody[] = {
            {"AUDI","model 01",2000,"szary",9},
            {"BMW","model 58",1998,"czarny",10},
            {"OPEL","model 100",2015,"srebrny",8.5},
            {"BMW","taki model",2020,"bialy",6.75}
    };
    cout<<"Sa "<<IleTejSamejMarki(samochody,4,"BMW")<<" samochody marki BMW\n";
}

void Zad4(){
    bnowy samochody[] = {
            {"AUDI","model 01",2000,"szary",9},
            {"BMW","model 58",1998,"czarny",10},
            {"OPEL","model 100",2015,"srebrny",8.5},
            {"BMW","taki model",2020,"bialy",6.75}
    };
    cout<<"Auto z indeksem "<<KtoryRokNajnizszy(samochody,4)<<" ma najnizszy rok produkcji\n";
}

void Struktury(){
    Zad1();
    Zad3();
    Zad4();
}