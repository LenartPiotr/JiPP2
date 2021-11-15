#include <iostream>
#include "node.h"
#include "triangle.h"

using namespace std;

Triangle::Triangle(){}
Triangle::Triangle(Node n1,Node n2,Node n3,std::string name):a(n1),b(n2),c(n3),name(name){}
void Triangle::display(){
    cout<<"Triangle "<<name<<" "<<a<<" "<<b<<" "<<c<<"\n";
}
std::ostream& operator<<(std::ostream& lhs, const Triangle &rhs){
    return lhs<<"Triangle "<<rhs.name<<" "<<rhs.a<<" "<<rhs.b<<" "<<rhs.c;
}
double Triangle::distance(int firstPointIndex, int secondPointIndex){
    Node tab[3] = {a,b,c};
    return pointsDistance(tab[firstPointIndex], tab[secondPointIndex]);
}

void showTriangleData(Triangle triangle){
    triangle.display();
}
void showTriangleData(Triangle &triangle){
    triangle.display();
}
void showTriangleData(Triangle *triangle){
    triangle->display();
}