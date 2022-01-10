#include <iostream>

using namespace std;

class SampleClass{
public:
    SampleClass(){
        cout<<"Constructor\n";
    }
    ~SampleClass(){
        cout<<"Destructor\n";
    }
};

template<typename T>
class my_shared_ptr{
private:
    int *count;
    T *value;
public:
    my_shared_ptr(T* obj){
        value = obj;
        count = new int(1);
    }
    my_shared_ptr(const my_shared_ptr<T> &obj){
        count = obj.count;
        value = obj.value;
        (*count)++;
    }
    void operator=(T* obj){
        value = obj;
        count = new int(1);
    }
    int use_count(){
        return *count;
    }
    T* operator*(){
        return value;
    }
    ~my_shared_ptr(){
        (*count)--;
        if(*count == 0){
            delete count;
            delete value;
        }
    }
};

int main() {
    int a = 10;
    float b = 10.5;
    float c = a + b; // Konwersja niejawna
    int d = a + (int)b; // Konwersja jawna
    int poleKwadratu = (int)b * (int)b;
    {
        my_shared_ptr<SampleClass> ptr = new SampleClass();
        cout<<ptr.use_count()<<endl;
        {
            my_shared_ptr<SampleClass> ptr2 = ptr;
            cout<<ptr.use_count()<<endl;
            cout<<ptr2.use_count()<<endl;
        }
        cout<<ptr.use_count()<<endl;
    }
    return 0;
}
