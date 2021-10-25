#include <iostream>
#include <math.h>

using namespace std;

class Punkt{
public:
    double x,y;
    Punkt(double X,double Y);
    Punkt();
    double distanceTo(Punkt p);
    void draw();
};

Punkt::Punkt():x(0),y(0) {}
Punkt::Punkt(double X, double Y) :x(X),y(Y) {}
double Punkt::distanceTo(Punkt p){
    return sqrt(pow(x-p.x,2)+pow(y-p.y,2));
}
void Punkt::draw() {
    cout<<"("<<x<<","<<y<<")";
}

class Figura{
public:
    int liczbaWierzcholkow;
    Punkt *wierzcholki;
    Figura(int tabX[],int tabY[],int count);
    ~Figura();
};

Figura::Figura(int tabX[],int tabY[],int count) {
    liczbaWierzcholkow = count;
    wierzcholki = new Punkt[count];
    for(int i=0; i<count; i++){
        wierzcholki[i].x = tabX[i];
        wierzcholki[i].y = tabY[i];
    }
}

Figura::~Figura() {
    delete[] wierzcholki;
}

void Konstruktory(){
    Punkt p1(1,1);
    Punkt p2(3,2);
    cout<<"Odleglosc punktow ";
    p1.draw();
    cout<<" i ";
    p2.draw();
    cout<<" wynosi "<<p1.distanceTo(p2)<<endl;
}