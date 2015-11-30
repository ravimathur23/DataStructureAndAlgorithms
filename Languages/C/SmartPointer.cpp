#include <iostream>
#include <map>
using namespace std;

template<class T>
class SmartPtr{
    T* ptr;
public:
    SmartPtr(T x){
        ptr = new T();
        *ptr = x;
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
int main(){
    SmartPtr<int> ob1(10);
    cout<<*ob1<<endl;
    return 0;
}
