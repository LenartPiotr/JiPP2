class ExampleClass{
private:
    double p1;
    double *p2;

public:
    ExampleClass() {
        p2 = new double;
    }

    ExampleClass(ExampleClass& exampleClass) {
        p1 = exampleClass.p1;
        p2 = new double;
        *p2 = *exampleClass.p2;
    }

    ~ExampleClass() {
        delete p2;
    }
    double getP1() const {
        return p1;
    }
    double getP2() const{
        return *p2;
    }
    void setP1(const double value){
        p1 = value;
    }
    void setP2(const double value){
        *p2 = value;
    }
};

void ConstStaticZad1(){
    //
}