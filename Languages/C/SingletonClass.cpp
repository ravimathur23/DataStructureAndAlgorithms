#include<iostream>
#include <String>
using namespace std;

class Singleton{
    Singleton(){};
    Singleton(const Singleton& ob);
    Singleton& operator=(const Singleton& ob);
    static Singleton *instance;
    string str;
public:
    static int countObjectReferences;
    static Singleton* getInstance(){
        countObjectReferences++;
        if(instance == NULL){
            return instance = new Singleton();
        }
        else{
            return instance;
        }
    }
    void setString(const string& str){this->str = str;}
    string getString(){return str;}
};

Singleton* Singleton::instance = NULL;
int Singleton::countObjectReferences = 0;

int main(){
    Singleton::getInstance()->setString("rav");
    cout<<Singleton::getInstance()->getString()<<endl;
    cout<<Singleton::getInstance()->getString()<<" "<<Singleton::countObjectReferences;
    
    return 0;
}
