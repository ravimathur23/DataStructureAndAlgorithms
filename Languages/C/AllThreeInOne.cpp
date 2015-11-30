#include <iostream>
#include <map>
using namespace std;

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
    Rav ob1(2);
    Rav ob2(3);
    ob1 = ob2;
    ob1.printVal();
    Rav ob3 = ob1;
    return 0;
}
