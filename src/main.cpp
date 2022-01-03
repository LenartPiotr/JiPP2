#include <iostream>
#include <exception>
#include "csv_lib.h"

using namespace std;

class MyException: public exception {
private:
    char *exceptionText;

public:
    MyException(char * exceptionText): exceptionText(exceptionText) {}

    const char * what() {
        return exceptionText;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
