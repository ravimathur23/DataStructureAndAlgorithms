#include <iostream>
#include <string.h>

using namespace std;

//Time complexity = O(m*n)

int max(int a, int b){
	return a>b? a:b;
}
void  lcs(char a[], char b[], int len_a, int len_b){
	
	int L[len_a+1][len_b+1];
	
	for(int i=0;i<=len_a;i++){
		for(int j=0;j<=len_b;j++){
			
			if(i==0 || j==0){
				L[i][j] = 0;
				continue;
			}
				
			if(a[i] == b[j]){
				L[i][j] =  L[i-1][j-1]+1;
			}
			else{
				L[i][j] = max(L[i-1][j], L[i][j-1]);
			}
		}
	}
	
	cout<<"Longest common seq  = "<<L[len_a][len_b];
}

int main() {
	
	char a[] = "AGGTAB";
	char b[] = "GXTXAYB";
	
	int len_a = strlen(a);
	int len_b = strlen(b);
	
	lcs(a,b, len_a, len_b);
	
	return 0;
}
