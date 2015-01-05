#include <iostream>
#include <string.h>
using namespace std;

void findStr(char str[], char pat[]){
	int str_len = strlen(str);
	int pat_len = strlen(pat);
	int tot = 0;
	for(int i=0;i<(str_len-pat_len+1);i++){
		for(int j=0;j<pat_len;j++){
			if(str[i+j] != pat[j])
			{
				break;
			}
			
			if(j == pat_len-1){
				cout<<"Matched at : "<<i<<endl;
				tot++;
			}
		}
	}
	cout<<"Total matches : "<<tot<<endl;
}
int main() {
	// your code goes here
	char str[] = "abcskjsjkdabcckdjsdjaaaabbbabc";
	char pat[] = "abc";
	
	findStr(str, pat);
	
	return 0;
}
