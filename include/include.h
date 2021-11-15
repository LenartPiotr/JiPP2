#ifndef LAB06_INCLUDE_H
#define LAB06_INCLUDE_H

class ImaginaryNumber{
private:
    double v;
public:
    ImaginaryNumber();
    ImaginaryNumber(double x);
    void print() const;
    ImaginaryNumber operator+(const ImaginaryNumber&)const;
    double operator*(const ImaginaryNumber&)const;
};

void ZadVector();

#endif //LAB06_INCLUDE_H
