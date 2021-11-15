#include <iostream>
#include "node.h"
#include "include.h"
#include "triangle.h"

using namespace std;

int main() {
    // Funkcje zaprzyjaźnione
    Node n1, n2;
    n1.updateValue(1,1);
    n2.updateValue(4,5);
    cout<<"n1: "; n1.display();
    cout<<"n2: "; n2.display();
    cout<<"Dystans n1 do n2 = "<<pointsDistance(n1,n2)<<endl;
    // Operatory
    ZadVector();

    Node a, b(5,8), c(1, 16);
    Triangle triangle(a, b, c, "First Triangle");

    triangle.display();
    cout << triangle << endl;
    cout << "Distance between first and second point is " << triangle.distance(0,1) << endl;

    // showTriangleData(triangle); // błąd
    showTriangleData(&triangle);
    return 0;
}
