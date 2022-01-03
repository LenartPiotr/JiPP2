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
    if(file.is_open()){
        while(!file.eof()){
            file>>sign;
            if(sign == ','){
                buffer[index] = '\0';
                string s(buffer);
                data.addData(currentRow, s);
                index = 0;
            }else if(sign == '\n') {
                buffer[index] = '\0';
                index = 0;
                string s(buffer);
                data.addData(currentRow, s);
                data.addRow();
                currentRow++;
            } else{
                buffer[index++] = sign;
            }
        }
    }else throw CSVException("Cannot open file");
    return data;
}
