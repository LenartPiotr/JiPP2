#include "csv_lib.h"

CSVData::CSVData() {
    maxCols = 0;
}

void CSVData::addRow() {
    data.push_back(vector<string>());
}

void CSVData::addData(int row, const string& dataMsg) {
    if(row>=0 && row<data.size()){
        data[row].push_back(dataMsg);
        if(data[row].size() > maxCols)
            maxCols = data[row].size();
    }else{
        throw CSVException("Invalid row index");
    }
}

string CSVData::getData(int row, int col) const {
    if(row>=0 && row<data.size()){
        if(col < 0 || col >= maxCols){
            throw CSVException("Invalid col index");
        }
        if(col >= data[row].size()){
            return "";
        }
        return data[row][col];
    }else{
        throw CSVException("Invalid row index");
    }
}

int CSVData::rows() const {
    return data.size();
}

int CSVData::cols() const {
    return maxCols;
}

