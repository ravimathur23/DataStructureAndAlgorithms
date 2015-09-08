#include <iostream>
using namespace std;

void print_spiral(int A[][6], int row, int col){
	
	int top = 0, bottom = row-1, right = col-1, left = 0;
	
	while(1){
		for(int i=left;i<=right;i++){
			cout<<A[top][i]<<" ";
		}
		top++;
		if(top>bottom || left>right)
			break;
		cout<<endl;
		
		for(int i=top;i<=bottom;i++){
			cout<<A[i][right]<<" ";
		}
		right--;
		if(top>bottom || left>right)
			break;
		cout<<endl;
		
		for(int i=right;i>=left;i--){
			cout<<A[bottom][i]<<" ";
		}
		bottom--;
		if(top>bottom || left>right)
			break;
		cout<<endl;
		
		for(int i=bottom;i>=top;i--){
			cout<<A[i][left]<<" ";
		}
		left++;
		if(top>bottom || left>right)
			break;
		cout<<endl;
	}
	
	return ;
}

int main() {
	int A[][6] = {1,2,3, 4, 5, 6,
				  7,8,9,10,11,12,
				  13,14,15,16,17,18,
				  18,19,20,21,22,23,
				  24,25,26,27,28,29};
				  
	
	int row_len = sizeof(A)/sizeof(A[0]);
	int col_len = sizeof(A[0])/sizeof(int);
	
	print_spiral(A, row_len, col_len);
	
	cout<<endl<<endl;
	
	int a[][6] = { {1,  2,  3,  4,  5,  6},
        		{7,  8,  9,  10, 11, 12},
        		{13, 14, 15, 16, 17, 18}};
	row_len = sizeof(a)/sizeof(a[0]);
	col_len = sizeof(a[0])/sizeof(int);
	
	print_spiral(a, row_len, col_len);
	return 0;
}
