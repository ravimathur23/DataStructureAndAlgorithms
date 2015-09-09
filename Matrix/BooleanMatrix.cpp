#include <iostream>
using namespace std;

void print_boolean_mat(int a[][4], int row_sz, int col_sz){
	bool rowFlag = false, colFlag = false;

	for(int i=0;i<col_sz;i++){
		if(a[0][i]==1)
			rowFlag = true;
	}
	
	for(int i=0;i<row_sz;i++){
		if(a[i][0]==1)
			colFlag=true;
	}
	
	for(int i=1;i<row_sz;i++){
		for(int j=1;j<col_sz;j++){
			if(a[i][j]==1){
				a[0][j] = 1;
				a[i][0] = 1;
			}
		}
	}

	for(int i=1;i<row_sz;i++){
		for(int j=1;j<col_sz;j++){
			if(a[0][j]==1 || a[i][0]==1){
					a[i][j] = 1;
			}
		}
	}
	
	for(int i=0;i<row_sz;i++){
		for(int j=0;j<col_sz;j++){
			if(i==0 && rowFlag){
				cout<<1<<" ";
			
			}
			else if(j==0 && colFlag){
				cout<<1<<" ";
			}
			else{
				cout<<a[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}

int main() {
	
	int A[][4] = {0,0,1,0,
		      0,0,0,0,
		      1,0,0,0};
	
	int row_sz = sizeof(A)/sizeof(A[0]);
	int col_sz = sizeof(A[0])/sizeof(int);
	print_boolean_mat(A, row_sz, col_sz );
	
	return 0;
}
