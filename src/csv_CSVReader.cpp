#include "csv_lib.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

CSVData CSVReader::read(char *fileName) {
    CSVData data;
    ifstream file(fileName);
    if (file.bad())
    {
        throw CSVException("could not open file");
    }
    std::regex csvLineRegExp(
        "(?:,|\n|^)(\"(?:(?:\"\")*[^\"]*)*\"|[^\",\n]*|(?:\n|$))");
    int i = 0;
    while (!file.eof()) {
        string line;
        std::getline(file, line);
        auto field =
            std::sregex_iterator(line.begin(), line.end(), csvLineRegExp);
        if (field->empty()) {
            return data;
        }
        static int columns = field->length(1);
        if (columns != field->length(1)) {
            throw CSVException("wrong file format");
        }
        data.addRow();
        for (auto it = field; it != std::sregex_iterator(); it++) {
            // std::cout << it->str(1) << ";";
            data.addData(i, it->str(1));
        }
        i++;
    }
    // int currentRow = 0;
    // data.addRow();
    // char buffer[1024];
    // int index = 0;
    // char sign;
    // bool inQuotation = false;
    // bool prevWasQuoteMark = false;
    // if(file.is_open()){
    //     while(!file.eof()){
    //         file.get(sign);
    //         if(file.eof()) break;
    //         if(sign == ','){
    //             if(inQuotation){
    //                 buffer[index++] = sign;
    //             }else{
    //                 buffer[index] = '\0';
    //                 string s(buffer);
    //                 data.addData(currentRow, s);
    //                 index = 0;
    //             }
    //             prevWasQuoteMark = false;
    //         }else if(sign == '\n') {
    //             if(inQuotation) throw CSVException("wrong file format");
    //             buffer[index] = '\0';
    //             index = 0;
    //             string s(buffer);
    //             data.addData(currentRow, s);
    //             data.addRow();
    //             currentRow++;
    //             prevWasQuoteMark = false;
    //         }else if(sign == '"'){
    //             if(prevWasQuoteMark){
    //                 buffer[index++] = '"';
    //             }
    //             prevWasQuoteMark = !prevWasQuoteMark;
    //             inQuotation = !inQuotation;
    //         }else{
    //             buffer[index++] = sign;
    //             prevWasQuoteMark = false;
    //         }
    //     }
    //     buffer[index] = '\0';
    //     string s(buffer);
    //     data.addData(currentRow, s);
    // }else throw CSVException("Cannot open file");
    return data;
}
