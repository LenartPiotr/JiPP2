#include <iostream>
#include <exception>
#include "csv_lib.h"

using namespace std;

int main() {
    CSVData data;
    CSVReader reader;
    try{
        data = reader.read("data.csv");
        data.print();
        cout<<"\nRows: "<<data.rows()<<"\nCols: "<<data.cols()<<"\n";
    }catch (CSVException exception){
        cout<<"ERROR: "<<exception.what();
    }
    return 0;
}
