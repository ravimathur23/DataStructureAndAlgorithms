#include<iostream>
using namespace std;

class Singleton{
    Singleton(){};
    Singleton(const Singleton& ob);
    Singleton& operator=(const Singleton& ob);
    static Singleton *instance;
public:
    static Singleton* getInstance(){
        if(instance == NULL){
            return instance = new Singleton();
        }
        else{
            return instance;
        }
    }
    void printHello(){cout<<"hello"<<endl;}
};

Singleton* Singleton::instance = NULL;

int main(){
    Singleton::getInstance()->printHello();
    return 0;
}
