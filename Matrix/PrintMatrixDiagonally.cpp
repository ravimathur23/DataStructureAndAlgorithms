#include <iostream>
using namespace std;

void print_mat_diagonally(int A[][4], int row_sz, int col_sz){
	
	for(int i=0;i<row_sz;i++){
		int col=0, row=i;
		
		while(1){
			if(row>=0 && row<row_sz && col>=0 && col<col_sz)
			{	
				cout<<A[row][col]<<" ";
			}
			else{
				break;
			}
			row--;col++;
		}
		cout<<endl;
	}
	
	for(int i=1;i<col_sz;i++){
		int col=i, row=row_sz-1;
		
		while(1){
			if(row>=0 && row<row_sz && col>=0 && col<col_sz)
			{	
				cout<<A[row][col]<<" ";
			}
			else{
				break;
			}
			row--;col++;
		}
		cout<<endl;
	}
}

int main() {
	
	int A[][4] = {1,2,3,4,
			      5,6,7,8,
			      9,10,11,12,
			      13,14,15,16};
	
	int row_sz = sizeof(A)/sizeof(A[0]);
	int col_sz = sizeof(A[0])/sizeof(int);
	
	print_mat_diagonally(A, row_sz, col_sz );
	
	return 0;
}
