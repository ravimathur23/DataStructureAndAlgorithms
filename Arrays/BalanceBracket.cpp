#include <iostream>
#include <string>
#include <stack>
#include <iterator>
using namespace std;

int main(){
    
    string s = "}{{}}{{{";
    
    stack<char> stk;
    
    for(int i=0;i<s.length();i++){
        if(s[i] == '}' && (stk.empty() == false)){
            if(stk.top() == '{')
                stk.pop();
            else
                stk.push(s[i]);
        }
        else
        {
            stk.push(s[i]);
        }
    }
    
    int left = 0, right = 0;
    while(stk.empty() == false){
        if(stk.top() == '{'){
            left++;
        }
        else if(stk.top() ==  '}')
            right++;
        else{
            //
        }
        stk.pop();
    }
    
    if(left == right){
        cout<<"Reqd = "<<left<<endl;
        return 0;
    }
    int min = 0, max = 0;
    if(left>right){
        min =  right;
        max = left;
    }
    else{
        min = left;
        max = right;
    }
    
    if((max-min)%2 == 0){
        cout<<"Reqd ="<<min+(max/2)<<endl;
    }
    else{
        cout<<"Cannot be balanced"<<endl;
    }
    return 0;
}
