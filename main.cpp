#include <iostream>

using namespace std;

void ZadanieTablice(){
    // Tworzenie tablicy dwuwymiarowej
    int ** tab = new int*[10];
    for(int i=0; i<10; i++){
        tab[i] = new int[10];
    }
    // Tablica utworzona
    // Usuwanie
    for(int i=0; i<10; i++) delete tab[i];
    delete tab;
}

void ZadanieKalkulator(int argc, char *argv[]){
    for(int i = 0; i < argc ; ++i) {
        cout << argv[i] <<endl;
    }
}

int main(int argc, char *argv[]) {
    ZadanieTablice();
    ZadanieKalkulator(argc, argv);
    return 0;
}
