#include <iostream>

using namespace std;

class Vector {
private:
    double x, y;

public:
    Vector() {};
    Vector(double x, double y) : x(x), y(y) {}
    double length() {
        return sqrt(x * x + y * y);
    }
    Vector operator+(const Vector &rhs) const {
        return {x + rhs.x, y + rhs.y};
    }
    Vector &operator+=(const Vector &rhs) {
        this->x = this->x + rhs.x;
        this->y = this->y + rhs.y;
        return *this;
    }
    Vector operator-(const Vector &rhs) const {
        return {x - rhs.x, y - rhs.y};
    }
    Vector &operator-=(const Vector &rhs) {
        this->x = this->x - rhs.x;
        this->y = this->y - rhs.y;
        return *this;
    }
    Vector operator-() const {
        return {-x, -y};
    }
    double operator*(const Vector &rhs) const{
        return x*rhs.x+y*rhs.y;
    }
    Vector operator*(const double &rhs) const{
        return {x*rhs, y*rhs};
    }
    bool operator==(const Vector &rhs) const{
        return x==rhs.x && y==rhs.y;
    }
    void print() const{
        cout<<"("<<x<<", "<<y<<")";
    }
    friend Vector operator*(const double&,const Vector&);
    friend std::ostream& operator<<(std::ostream&,const Vector&);
};

std::ostream& operator<<(std::ostream& lhs, const Vector &rhs){
    return lhs<<"("<<rhs.x<<", "<<rhs.y<<")";
}

Vector operator*(const double &lhs, const Vector &rhs) {
    return {rhs.x*lhs,rhs.y*lhs};
}

void ZadVector() {
    Vector v1(1,2);
    Vector v2(2,3);
    Vector v3 = -(v1 + v2);
    Vector v4(-3,-5);
    cout<<"Wektory:\nv1 = "<<v1<<"\nv2 = "<<v2<<"\nv3 = "<<v3<<"\nv4 = "<<v4<<endl;
    if(v3==v4){
        cout<<"Wektory sa takie same\n";
    }
}