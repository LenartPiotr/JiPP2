#include <iostream>
#include "node.h"

#ifndef LAB06_TRIANGLE_H
#define LAB06_TRIANGLE_H

class Triangle{
private:
    Node a,b,c;
    std::string name;
public:
    Triangle();
    Triangle(Node n1,Node n2,Node n3,std::string);
    void display();
    friend std::ostream& operator<<(std::ostream& lhs, const Triangle &rhs);
    double distance(int firstPointIndex, int secondPointIndex);
};

void showTriangleData(Triangle triangle);
void showTriangleData(Triangle &triangle);
void showTriangleData(Triangle *triangle);

std::ostream& operator<<(std::ostream& lhs, const Triangle &rhs);

#endif //LAB06_TRIANGLE_H
