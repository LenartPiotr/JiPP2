#include <iostream>
#include <conio.h>
#include "matrixLib.h"

using namespace std;

int** EnterMatrix(string txt, int &rows, int &cols){
    int** matrix;
    cout<<txt<<endl;
    if(rows == 0){
        cout<<"Wprowadz ilosc wierszy: ";
        cin>>rows;
        cout<<"Wprowadz ilosc kolumn: ";
        cin>>cols;
    }
    matrix = CreateMatrix(rows, cols);
    cout<<"Wprowadzaj po kolei wartosci macierzy rzedami:\n";
    for(int y=0; y<rows; y++)
        for(int x=0; x<cols; x++){
            cin>>matrix[y][x];
        }
    return matrix;
}

double** EnterMatrixDouble(string txt, int &rows, int &cols){
    double** matrix;
    cout<<txt<<endl;
    if(rows == 0){
        cout<<"Wprowadz ilosc wierszy: ";
        cin>>rows;
        cout<<"Wprowadz ilosc kolumn: ";
        cin>>cols;
    }
    matrix = CreateMatrixDouble(rows, cols);
    cout<<"Wprowadzaj po kolei wartosci macierzy rzedami:\n";
    for(int y=0; y<rows; y++)
        for(int x=0; x<cols; x++){
            cin>>matrix[y][x];
        }
    return matrix;
}

bool IsInt(){
    cout<<"Czy chcesz uzywac macierzy o wartosciach calkowitych?\n"<<
    "[t] - Zmienne calkowite   [n] - Zmienne typu double\n> ";
    string z;
    cin>>z;
    return z[0] == 't' || z[0] == 'T';
}

bool IsSquare(int rows, int cols) {
    if(rows==cols) return true;
    cout<<"Macierz musi byc kwadratowa.\n";
    return false;
}

void ShowMatrix(int** matrix, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void ShowMatrix(double** matrix, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Help(){
    cout<<"Matrix calculator\n\nDzialania:\n"<<
    "addMatrix  -  Dodawanie macierzy\n"<<
    "subtractMatrix  -  Odejmowanie macierzy\n"<<
    "multiplyMatrix  -  Mnozenie macierzy\n"<<
    "multiplyByScalar  -  Mnozenie macierzy przez skalar\n"<<
    "transpozeMatrix  -  Transpozycja macierzy\n"<<
    "powerMatrix  -  Potegowanie macierzy\n"<<
    "determinantMatrix  -  Wyznacznik macierzy\n"<<
    "matrixIsDiagonal  -  Sprawdzanie czy macierz jest diagonalna\n"<<
    "sortRowsInMatrix  -  Sortowanie macierzy\n"<<
    "help - Dokumentacja\n";
}

int main(int argc, char *argv[]) {
    if(argc <= 1){
        Help();
        return 0;
    }
    string arg1(argv[1]);
    if(arg1 == "addMatrix"){
        if(IsInt()){
            int rows = 0, cols;
            int** matrixA = EnterMatrix("Wprowadz macierz A", rows, cols);
            int** matrixB = EnterMatrix("Wprowadz macierz B", rows, cols);
            int** result = addMatrix(matrixA, matrixB, rows, cols);
            ShowMatrix(result, rows, cols);
            DeleteMatrix(matrixA, rows);
            DeleteMatrix(matrixB, rows);
            DeleteMatrix(result, rows);
        }else{
            int rows = 0, cols;
            double** matrixA = EnterMatrixDouble("Wprowadz macierz A", rows, cols);
            double** matrixB = EnterMatrixDouble("Wprowadz macierz B", rows, cols);
            double** result = addMatrix(matrixA, matrixB, rows, cols);
            ShowMatrix(result, rows, cols);
            DeleteMatrix(matrixA, rows);
            DeleteMatrix(matrixB, rows);
            DeleteMatrix(result, rows);
        }
    }else
    if(arg1 == "subtractMatrix"){
        if(IsInt()){
            int rows = 0, cols;
            int** matrixA = EnterMatrix("Wprowadz macierz A", rows, cols);
            int** matrixB = EnterMatrix("Wprowadz macierz B", rows, cols);
            int** result = subtractMatrix(matrixA, matrixB, rows, cols);
            ShowMatrix(result, rows, cols);
            DeleteMatrix(matrixA, rows);
            DeleteMatrix(matrixB, rows);
            DeleteMatrix(result, rows);
        }else{
            int rows = 0, cols;
            double** matrixA = EnterMatrixDouble("Wprowadz macierz A", rows, cols);
            double** matrixB = EnterMatrixDouble("Wprowadz macierz B", rows, cols);
            double** result = subtractMatrix(matrixA, matrixB, rows, cols);
            ShowMatrix(result, rows, cols);
            DeleteMatrix(matrixA, rows);
            DeleteMatrix(matrixB, rows);
            DeleteMatrix(result, rows);
        }
    }else
    if(arg1 == "multiplyMatrix"){
        if(IsInt()){
            int rows = 0, cols, rows2 = 0, cols2;
            int** matrixA = EnterMatrix("Wprowadz macierz A", rows, cols);
            int** matrixB = EnterMatrix("Wprowadz macierz B", rows2, cols2);
            int** result = multiplyMatrix(matrixA, matrixB, rows, cols, cols2);
            ShowMatrix(result, rows, cols2);
            DeleteMatrix(matrixA, rows);
            DeleteMatrix(matrixB, rows2);
            DeleteMatrix(result, rows);
        }else{
            int rows = 0, cols, rows2 = 0, cols2;
            double** matrixA = EnterMatrixDouble("Wprowadz macierz A", rows, cols);
            double** matrixB = EnterMatrixDouble("Wprowadz macierz B", rows2, cols2);
            double** result = multiplyMatrix(matrixA, matrixB, rows, cols, cols2);
            ShowMatrix(result, rows, cols2);
            DeleteMatrix(matrixA, rows);
            DeleteMatrix(matrixB, rows2);
            DeleteMatrix(result, rows);
        }
    }else
    if(arg1 == "multiplyByScalar"){
        if(IsInt()){
            int rows = 0, cols, scalar;
            int** matrixA = EnterMatrix("Wprowadz macierz A", rows, cols);
            cout<<"Wprowadz skalar: ";
            cin>>scalar;
            int** result = multiplyByScalar(matrixA, rows, cols, scalar);
            ShowMatrix(result, rows, cols);
            DeleteMatrix(matrixA, rows);
            DeleteMatrix(result, rows);
        }else{
            int rows = 0, cols;
            double scalar;
            double** matrixA = EnterMatrixDouble("Wprowadz macierz A", rows, cols);
            cout<<"Wprowadz skalar: ";
            cin>>scalar;
            double** result = multiplyByScalar(matrixA, rows, cols, scalar);
            ShowMatrix(result, rows, cols);
            DeleteMatrix(matrixA, rows);
            DeleteMatrix(result, rows);
        }
    }else
    if(arg1 == "transpozeMatrix"){
        if(IsInt()){
            int rows = 0, cols;
            int** matrixA = EnterMatrix("Wprowadz macierz A", rows, cols);
            int** result = transpozeMatrix(matrixA, rows, cols);
            ShowMatrix(result, cols, rows);
            DeleteMatrix(matrixA, rows);
            DeleteMatrix(result, cols);
        }else{
            int rows = 0, cols;
            double** matrixA = EnterMatrixDouble("Wprowadz macierz A", rows, cols);
            double** result = transpozeMatrix(matrixA, rows, cols);
            ShowMatrix(result, cols, rows);
            DeleteMatrix(matrixA, rows);
            DeleteMatrix(result, cols);
        }
    }else
    if(arg1 == "powerMatrix"){
        if(IsInt()){
            int rows = 0, cols;
            unsigned int power;
            int** matrixA = EnterMatrix("Wprowadz kwadratowa macierz A", rows, cols);
            if(!IsSquare(rows, cols)) { DeleteMatrix(matrixA,rows); return 0; }
            cout<<"Wprowadz potege: ";
            cin>>power;
            int** result = powerMatrix(matrixA, rows, power);
            ShowMatrix(result, rows, cols);
            DeleteMatrix(matrixA, rows);
            DeleteMatrix(result, rows);
        }else{
            int rows = 0, cols;
            unsigned int power;
            double** matrixA = EnterMatrixDouble("Wprowadz kwadratowa macierz A", rows, cols);
            if(!IsSquare(rows, cols)) { DeleteMatrix(matrixA,rows); return 0; }
            cout<<"Wprowadz potege: ";
            cin>>power;
            double** result = powerMatrix(matrixA, rows, power);
            ShowMatrix(result, rows, cols);
            DeleteMatrix(matrixA, rows);
            DeleteMatrix(result, rows);
        }
    }else
    if(arg1 == "determinantMatrix"){
        if(IsInt()){
            int rows = 0, cols;
            int** matrixA = EnterMatrix("Wprowadz kwadratowa macierz A", rows, cols);
            if(!IsSquare(rows, cols)) { DeleteMatrix(matrixA,rows); return 0; }
            int result = determinantMatrix(matrixA, rows);
            cout<<"Wyznacznik = "<<result<<endl;
            DeleteMatrix(matrixA, rows);
        }else{
            int rows = 0, cols;
            double** matrixA = EnterMatrixDouble("Wprowadz kwadratowa macierz A", rows, cols);
            if(!IsSquare(rows, cols)) { DeleteMatrix(matrixA,rows); return 0; }
            double result = determinantMatrix(matrixA, rows);
            cout<<"Wyznacznik = "<<result<<endl;
            DeleteMatrix(matrixA, rows);
        }
    }else
    if(arg1 == "matrixIsDiagonal"){
        if(IsInt()){
            int rows = 0, cols;
            int** matrixA = EnterMatrix("Wprowadz kwadratowa macierz A", rows, cols);
            if(!IsSquare(rows, cols)) { DeleteMatrix(matrixA,rows); return 0; }
            bool result = matrixIsDiagonal(matrixA, rows);
            cout<<"Macierz "<<(result?"jest":"nie jest")<<" diagonalna\n";
            DeleteMatrix(matrixA, rows);
        }else{
            int rows = 0, cols;
            double** matrixA = EnterMatrixDouble("Wprowadz kwadratowa macierz A", rows, cols);
            if(!IsSquare(rows, cols)) { DeleteMatrix(matrixA,rows); return 0; }
            bool result = matrixIsDiagonal(matrixA, rows);
            cout<<"Macierz "<<(result?"jest":"nie jest")<<" diagonalna\n";
            DeleteMatrix(matrixA, rows);
        }
    }else
    if(arg1 == "sortRowsInMatrix"){
        if(IsInt()){
            int rows = 0, cols;
            int** matrixA = EnterMatrix("Wprowadz macierz A", rows, cols);
            int** result = sortRowsInMatrix(matrixA, rows, cols);
            ShowMatrix(result, rows, cols);
            DeleteMatrix(matrixA, rows);
        }else{
            int rows = 0, cols;
            double** matrixA = EnterMatrixDouble("Wprowadz macierz A", rows, cols);
            double** result = sortRowsInMatrix(matrixA, rows, cols);
            ShowMatrix(result, rows, cols);
            DeleteMatrix(matrixA, rows);
        }
    }else{
        Help();
    }
    return 0;
}
