#include <iostream>
#include <map>
using namespace std;

template<class T>
class SmartPtr{
    T* ptr;
public:
    SmartPtr(T* x):ptr(x){
        cout<<"ctor"<<endl;
    }
    ~SmartPtr(){
        delete ptr;
        cout<<"dtor"<<endl;
    }
    T* operator->()const{
        cout<<"->"<<endl;
        return ptr;
    }
    T& operator*()const{
        cout<<"*"<<endl;
        return *ptr;
    }
};
class Rav{
    int *p;
public:
    Rav(int i){p = new int(i);cout<<"ctor ";}
    Rav(const Rav& ob1){
        if(this == &ob1)
            return;
        if(p == NULL)
            cout<<"rav"<<endl;
        p = new int(*ob1.p);cout<<"copy_ctor ";
    }
    Rav& operator=(const Rav& ob1){
        cout<<"assignment_operator ";
        if(this == &ob1){
            return *this;
        }
        delete p;
        p = new int(*ob1.p);
        return *this;
    }
    ~Rav(){delete p;cout<<"dest ";}
    void printVal(){cout<<"*p="<<*p<<endl;}
};
int main(){
    SmartPtr<Rav> ob1(new Rav(10));
    ob1->printVal();
    (*ob1).printVal();
    return 0;
}
