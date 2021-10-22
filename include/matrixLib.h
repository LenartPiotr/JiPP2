#ifndef LAB02_PROJEKT_MATRIXLIB_H
#define LAB02_PROJEKT_MATRIXLIB_H

int** CreateMatrix(int,int);
void DeleteMatrix(int**,int);
int** addMatrix(int**,int**,int,int);
int** subtractMatrix(int**,int**,int,int);
int** multiplyMatrix(int**,int**,int,int,int);
int** multiplyByScalar(int**,int,int,int);
int** transpozeMatrix(int**,int,int);
int** powerMatrix(int**,int,unsigned int);
int determinantMatrix(int**,int);
bool matrixIsDiagonal(int**,int);
void swap(int&,int&);
int* sortRow(int*,int);
int** sortRowsInMatrix(int**,int,int);

double** CreateMatrixDouble(int,int);
void DeleteMatrix(double**,int);
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

#endif //LAB02_PROJEKT_MATRIXLIB_H
