#include <iostream>
#include <string>
using namespace std;
int offsetChar(char c){return c-97;}
bool checkUnique(string str){
    if(str.length() > 256)
        return false;

    int checker = 0;
    
    for(int i=0;i<str.length();i++){
        if(checker & (1<<offsetChar(str[i])))
            return false;
        checker |= 1<<offsetChar(str[i]);
        
    }
    return true;
}
int main(){
    string str = "abcdefgh";
    cout<<checkUnique(str)<<endl;
}
