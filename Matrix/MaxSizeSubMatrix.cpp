#include <iostream>
using namespace std;

int min(int a, int b, int c){
	int min = a;
	
	if(min > b){
		min = b;
	}
	if(min > c){
		min = c;
	}
	
	return min;
}

void print_maxsize_mat(int A[][5], int row_sz, int col_sz){
	
	int B[6][5];
	for(int i=0;i<row_sz;i++){
		for(int j=0;j<col_sz;j++){
			if(i==0 || j==0)
				B[i][j] = A[i][j];
			else{
				if(A[i][j]==1)
				{
					B[i][j] = min(B[i-1][j], B[i-1][j-1], B[i][j-1])+1;	
				}
				else{
					B[i][j]=0;
				}
			}
		}
	}
	
	for(int i=0;i<row_sz;i++){
		for(int j=0;j<col_sz;j++){
			cout<<B[i][j]<<" ";
		}	
		cout<<endl;
	}
}

int main() {
	
	int A[][5] =  {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
	
	int row_sz = sizeof(A)/sizeof(A[0]);
	int col_sz = sizeof(A[0])/sizeof(int);
	
	print_maxsize_mat(A, row_sz, col_sz);
	
	return 0;
}
