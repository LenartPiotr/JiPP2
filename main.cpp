#include <iostream>
#include <fstream>
#include <ostream>
#include <stdlib.h>

using namespace std;

template<typename T>
T min2(T a, T b){
    return a<b?a:b;
}

template<typename T>
T max2(T a, T b){
    return a>b?a:b;
}

template<typename T>
void printArray(T *arr, int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

template<typename T>
void printMatrix(T **matrix, int width, int height){
    for(int i=0; i<height; i++){
        printArray(matrix[i], width);
    }
}

template<typename T, int size>
class Array{
private:
    T* arr;
public:
    Array(){
        arr = new T[size];
    }
    ~Array(){
        delete[] arr;
    }
    T& operator[](const int rhs){
        return arr[rhs];
    }
};


template<typename T>
class Vector{
private:
    T* arr;
    int currentSize;
    int allocatedSize;
    void reallocArr(int newSize){
        //arr = (T*)realloc(arr, newSize*sizeof(T));
        T* newArr = new T[newSize];
        int copyCount = min2(newSize,currentSize);
        for(int i=0; i<copyCount; i++){
            newArr[i] = arr[i];
        }
        allocatedSize = newSize;
        delete[] arr;
        arr = newArr;
    }
public:
    Vector(){
        arr = new T[1];
        currentSize = 0;
        allocatedSize = 1;
    }
    Vector(int size){
        arr = new T[size];
        currentSize = size;
        allocatedSize = size;
    }
    ~Vector(){
        delete[] arr;
    }
    void push(T value){
        if(currentSize==allocatedSize){
            reallocArr(currentSize+1);
        }
        arr[currentSize++] = value;
    }
    T pop(){
        if(currentSize>1)
            return arr[--currentSize];
        return arr[0];
    }
    T* getPointer(){
        return arr;
    }
    T& operator[](const int rhs){
        return arr[rhs];
    }
    int size(){return currentSize;}
};

struct Data{
    int nr;
    string from;
    string to;
    string oper;
};
ostream& operator<<(ostream& lhs, const Data &rhs){
    return lhs<<"\""<<rhs.nr<<"\",\""<<rhs.from<<"\",\""<<rhs.to<<"\",\""<<rhs.oper<<"\"\n";
}

Data InterpretLine(string line){
    Data d;
    size_t pos = line.find(',');
    d.nr = atoi(line.substr(1, pos-2).c_str());
    line.erase(0,pos+2);
    pos = line.find('"');
    d.from = line.substr(0, pos);
    line.erase(0, pos+3);
    pos = line.find('"');
    d.to = line.substr(0, pos);
    line.erase(0, pos+3);
    d.oper = line.substr(0, line.length()-1);
    return d;
}

int main() {
    Vector<int> v(2);
    v[0] = 0;
    v[1] = 1;
    printArray(v.getPointer(),v.size());
    v.push(2);
    v.push(3);
    printArray(v.getPointer(), v.size());
    // Zadania z plikami
    ifstream input("data.txt");
    if(!input.good()) {
        cout<<"Blad z plikiem";
        return 1;
    }
    Vector<Data> data;
    string line;
    while(getline(input, line)){
        data.push(InterpretLine(line));
    }
    input.close();
    printArray(data.getPointer(), data.size());
    ofstream o1("data_tram.txt");
    ofstream o2("data_bus.txt");
    if(o1.fail() || o2.fail()){
        cout<<"Nie mozna utworzyc pliku o1 lub o2\n";
        return 2;
    }
    int size = data.size();
    for(int i=0; i<size; i++){
        if(data[i].nr < 100)
            o1<<data[i];
        else
            o2<<data[i];
    }
    o1.close();
    o2.close();
    return 0;
}
