#include <iostream>
#include <stdlib.h>

using namespace std;

class ClassOfUniverse{
private:
    void MakeInfiniteRecursion();
public:
    int *universe;
    ClassOfUniverse();
    ~ClassOfUniverse();
    void Pause();
};

void ClassOfUniverse::MakeInfiniteRecursion() {
    MakeInfiniteRecursion();
    cout<<"Wait what?";
}

ClassOfUniverse::ClassOfUniverse() {
    cout<<"Houston, we have a problem!\nWe were not called\n";
    universe = new int[1024];
}

ClassOfUniverse::~ClassOfUniverse() {
    cout<<"RUNNING PROTOCOL: DESTROY UNIVERSE\n";
    cout<<"Goodbye world\n";
    delete[] universe;
}

void ClassOfUniverse::Pause() {
    cout<<"Houston, we can't stop time!\n";
    system("PAUSE");
    cout<<"Houston, are you there?\n";
}

void Destruktory(){
    ClassOfUniverse ourUniverse;
    ourUniverse.Pause();
}