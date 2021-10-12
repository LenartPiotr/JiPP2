#include <iostream>
#include <cstdlib>
#include "calc.h"

using namespace std;

int main(int argc, char *argv[]) {
    if(argc < 2){
        cout<<"Uzyj "<<argv[0]<<" help\n";
        return 0;
    }
    string arg1(argv[1]);
    if(arg1 == "add"){
        if(argc < 4){
            cout<<"Zle uzycie funkcji add\n\n";
            Help();
            return 0;
        }
        cout<<Add(atof(argv[2]), atof(argv[3]))<<endl;
    }else if(arg1 == "subtract"){
        if(argc < 4){
            cout<<"Zle uzycie funkcji subtract\n\n";
            Help();
            return 0;
        }
        cout<<Subtract(atof(argv[2]), atof(argv[3]))<<endl;
    }else if(arg1 == "volume"){
        if(argc < 6){
            cout<<"Zle uzycie funkcji volume\n\n";
            Help();
            return 0;
        }
        cout<<Volume(atof(argv[2]), atof(argv[3]), atof(argv[4]), atof(argv[5]))<<endl;
    }else if(arg1 == "help"){
        Help();
    }else{
        cout<<"Nieznane polecenie "<<arg1<<"\n\n";
        Help();
    }
    return 0;
}
