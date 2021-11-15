#ifndef JIPP2_NODE_H
#define JIPP2_NODE_H

class Node {
private:
    double x, y;

public:
    Node();
    Node(double x, double y);
    void display();
    void updateValue(double x, double y);
    friend double pointsDistance(Node,Node);
    friend std::ostream& operator<<(std::ostream& lhs, const Node &rhs);
};

double pointsDistance(Node a, Node b);
std::ostream& operator<<(std::ostream& lhs, const Node &rhs);

#endif //JIPP2_NODE_H