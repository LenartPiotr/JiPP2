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
    CSVData read(char* fileName);
};

class CSVException: public exception {
private:
    char *exceptionText;
public:
    CSVException(char * exceptionText): exceptionText(exceptionText) {}
    const char * what() {
        return exceptionText;
    }
};

#endif //INC_10_1_CSV_LIB_H
