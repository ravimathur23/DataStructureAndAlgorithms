#include <iostream>
#include <string>
using namespace std;
int get_sum(string str, int start, int end){
	int cnt = end - start;
	int sum = 0;
	for(int i=0;i<cnt;i++){
		sum+=str[i];
	}
	return sum;
}
int main() {
	// your code goes here
	string str = "abcdcbad";
	int len = str.length();
	int len_half = (len %2 == 0) ? len/2 : len/2+1;
	
	if(get_sum(str, 0, len_half) ==  get_sum(str, len_half, len)){
		cout<<"true";	
	}
	else{
		cout<<"false";
	}
	return 0;
}
