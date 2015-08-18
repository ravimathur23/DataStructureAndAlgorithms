#include <iostream>
using namespace std;

//Time complexity = O(m*n)

int min(int a, int b, int c){
	int min_val = a;
	
	if(b<a)
		min_val = b;
	
	if(min_val > c)
		min_val = c;
	
	return min_val;
}

void minCostPath(int arr[3][3], int row, int col){
	
	int L[3][3];
	
	L[0][0]  = arr[0][0];
	
	for(int i=1;i<3;i++){
		L[i][0] = L[i-1][0] + arr[i][0];
	}
	
	for(int i=1;i<3;i++){
		L[0][i] = L[0][i-1] + arr[0][i];
	}
	
	bool flag = false;
	
	for(int i=1;i<3;i++){
		for(int j=1;j<3;j++){
			L[i][j] = min(L[i-1][j], L[i-1][j-1], L[i][j-1]) + arr[i][j];
			
			if((row-1 == i) && (col-1 == j)){
				flag = true;
				break;
			}
		}
		
		if(flag)
			break;
	}
	
	cout<<"Min Cost Path = "<<L[row-1][col-1];
}

int main() {

	int arr[3][3] = { 1, 2, 3,
					  4, 8, 2,
					  1, 5, 3};
	
	minCostPath(arr, 2, 2);
	minCostPath(arr, 3, 3);
	
	return 0;
}
