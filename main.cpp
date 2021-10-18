#include <iostream>
#include <cstdlib>
#include <time.h>
#include "lib.h"

using namespace std;

int main() {
    srand(time(NULL));
    cout<<"Przeciazanie funkcji\n";
    PrzeciazanieFunkcji();
    cout<<"\nTablice\n\n";
    Tablice();
    cout<<"\nWskazniki\n\n";
    Wskazniki();
    return 0;
}
