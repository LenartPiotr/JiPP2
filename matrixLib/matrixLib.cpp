#include "matrixLib.h"

int** CopyValues(int** source,int** dest,int rows,int cols){
    for(int x=0; x<cols; x++)
        for(int y=0; y<rows; y++)
            dest[y][x] = source[y][x];
    return dest;
}

int** CreateMatrix(int rows,int cols){
    int** matrix = new int*[rows];
    for(int i=0; i<rows; i++){
        matrix[i] = new int[cols];
        for(int j=0; j<cols; j++) matrix[i][j] = 0;
    }
    return matrix;
}
void DeleteMatrix(int** matrix,int rows){
    for(int i=0; i<rows; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}
int** addMatrix(int** matA,int** matB,int rows,int cols){
    int** result = CreateMatrix(rows, cols);
    for(int x=0; x<cols; x++){
        for(int y=0; y<rows; y++){
            result[y][x] = matA[y][x] + matB[y][x];
        }
    }
    return result;
}

int** subtractMatrix(int** matA,int** matB,int rows,int cols){
    int** result = CreateMatrix(rows, cols);
    for(int x=0; x<cols; x++){
        for(int y=0; y<rows; y++){
            result[y][x] = matA[y][x] - matB[y][x];
        }
    }
    return result;
}

int** multiplyMatrix(int** matA,int** matB,int rowsA,int colsA,int colsB){
    int** result = CreateMatrix(rowsA, colsB);
    for(int x=0; x<colsB; x++){
        for(int y=0; y<rowsA; y++){
            for(int i=0; i<colsA; i++){
                result[y][x] += matA[y][i] * matB[i][x];
            }
        }
    }
    return result;
}

int** multiplyByScalar(int** mat,int rows,int cols,int scalar){
    int** result = CreateMatrix(rows, cols);
    for(int x=0; x<cols; x++){
        for(int y=0; y<rows; y++){
            result[y][x] = scalar * mat[y][x];
        }
    }
    return result;
}

int** transpozeMatrix(int** mat,int rows,int cols){
    int** result = CreateMatrix(cols, rows);
    for(int x=0; x<cols; x++){
        for(int y=0; y<rows; y++){
            result[x][y] = mat[y][x];
        }
    }
    return result;
}

int** powerMatrix(int** mat,int size,unsigned int power){
    if(power == 0) return CreateMatrix(size,size);
    if(power == 1) return CopyValues(mat, CreateMatrix(size,size), size, size);
    int** result = multiplyMatrix(mat, mat, size, size, size);
    for(power-=2; power>0; power--){
        int** result2 = multiplyMatrix(result, mat, size, size, size);
        DeleteMatrix(result, size);
        result = result2;
    }
    return result;
}

int det(int** matrix, int size, int* columns, int startRow){
    if(size == 1) return matrix[startRow][columns[0]];
    int* columnsNext = new int[size - 1];
    int sum = 0;
    int multi = 1;
    for(int i=0; i<size; i++){
        for(int j=0, k=0; j<size-1; j++, k++){
            if(k==i) k++;
            columnsNext[j] = columns[k];
        }
        sum += multi * matrix[startRow][columns[i]] * det(matrix, size - 1, columnsNext, startRow + 1);
        multi *= -1;
    }
    delete[] columnsNext;
    return sum;
}

int determinantMatrix(int** matrix,int size){
    int* columns = new int[size];
    for(int i=0; i<size; i++) columns[i] = i;
    return det(matrix, size, columns, 0);
}

bool matrixIsDiagonal(int** matrix,int size){
    for(int x=0; x<size; x++)
        for(int y=0; y<size; y++)
            if(x!=y && matrix[y][x] != 0)
                return false;
    return true;
}

void swap(int& a,int& b){
    int c = a;
    a = b;
    b = c;
}

int* sortRow(int* tab,int size){
    for(int i=0; i<size; i++)
        for(int j=i+1; j<size; j++)
            if(tab[i] > tab[j])
                swap(tab[i], tab[j]);
    return tab;
}

int** sortRowsInMatrix(int** matrix,int rows,int cols){
    for(int i=0; i<rows; i++)
        sortRow(matrix[i], cols);
    return matrix;
}

/*
double** CreateMatrixDouble(int,int);
void DeleteMatrix(double**,int,int);
double** addMatrix(double**,double**,int,int);
double** subtractMatrix(double**,double**,int,int);
double** multiplyMatrix(double**,double**,int,int,int);
double** multiplyByScalar(double**,int,int,int);
double** transpozeMatrix(double**,int,int);
double** powerMatrix(double**,int,unsigned int);
double determinantMatrix(double**,int);
bool matrixIsDiagonal(double**,int);
void swap(double&,double&);
double* sortRow(double*,int);
double** sortRowsInMatrix(double**,int,int);
 */