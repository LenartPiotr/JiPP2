#include <vector>
#include <string>

using namespace std;

#ifndef INC_10_1_CSV_LIB_H
#define INC_10_1_CSV_LIB_H

class CSVData{
private:
    vector<vector<string>> data;
    int maxCols;
public:
    CSVData();
    void addRow();
    void addData(int row,const string& dataMsg);
    string getData(int row,int col) const;
    int rows() const;
    int cols() const;
    void print() const;
};

class CSVReader{
public:
    CSVData read(string fileName);
};

class CSVException: public exception {
private:
    string exceptionText;
public:
    CSVException(string exceptionText): exceptionText(exceptionText) {}
    const string what() {
        return exceptionText;
    }
};

#endif //INC_10_1_CSV_LIB_H
