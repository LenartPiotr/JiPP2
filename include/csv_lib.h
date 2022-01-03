#ifndef INC_10_1_CSV_LIB_H
#define INC_10_1_CSV_LIB_H

#include <vector>

using namespace std;

class CSVData{
private:
    vector<vector<string>> data;
    int maxCols;
public:
    CSVData();
    void addRow();
    void addData(int row,string data);
    string getData(int row,int col);
    int rows();
    int cols();
};

class CSVReader{
public:
    CSVData read(char* fileName);
};

#endif //INC_10_1_CSV_LIB_H
