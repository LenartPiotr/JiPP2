#include "csv_lib.h"
#include <fstream>

CSVData CSVReader::read(char *fileName) {
    CSVData data;
    ifstream file(fileName);
    int currentRow = 0;
    data.addRow();
    char buffer[1024];
    int index = 0;
    char sign;
    bool inQuotation = false;
    bool prevWasQuoteMark = false;
    if(file.is_open()){
        while(!file.eof()){
            file.get(sign);
            if(file.eof()) break;
            if(sign == ','){
                if(inQuotation){
                    buffer[index++] = sign;
                }else{
                    buffer[index] = '\0';
                    string s(buffer);
                    data.addData(currentRow, s);
                    index = 0;
                }
                prevWasQuoteMark = false;
            }else if(sign == '\n') {
                if(inQuotation) throw CSVException("wrong file format");
                buffer[index] = '\0';
                index = 0;
                string s(buffer);
                data.addData(currentRow, s);
                data.addRow();
                currentRow++;
                prevWasQuoteMark = false;
            }else if(sign == '"'){
                if(prevWasQuoteMark){
                    buffer[index++] = '"';
                }
                prevWasQuoteMark = !prevWasQuoteMark;
                inQuotation = !inQuotation;
            }else{
                buffer[index++] = sign;
                prevWasQuoteMark = false;
            }
        }
        buffer[index] = '\0';
        string s(buffer);
        data.addData(currentRow, s);
    }else throw CSVException("Cannot open file");
    return data;
}
