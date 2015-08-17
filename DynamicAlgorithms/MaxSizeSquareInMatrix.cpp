#include <iostream>
using namespace std;

//Time complexity = O(m*n)
//Space complexity = O(m*n)

int min(int a, int b, int c){
	int min_val = a;
	
	if(b<a)
		min_val = b;
	
	if(min_val > c)
		min_val = c;
	
	return min_val;
}

void findMaxSize(int a[4][5], int &row, int &col){
	int b[4][5];
	int max = 0;
	
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++)
		{
			if(i==0 || j==0)
			{
				b[i][j] = a[i][j];
				continue;
			}
			
			if(a[i][j] == 0){
				b[i][j] = 0;
			}
			else
			{
				int min_num = min(b[i-1][j], b[i-1][j-1], b[i][j-1]);
				b[i][j] = ++min_num;
			}
			
			if(max < b[i][j]){
				max = b[i][j];
				row = i; col = j;
			}
		}
	}
}

int main() {
	int a[4][5] = { {1,1,0,1,1},
					{0,1,1,1,1},
					{0,1,1,1,1},
					{1,1,1,1,1}};
	int row = 0, col = 0;
	findMaxSize(a, row, col);
	cout<<"Sqr matrix ending at : "<<row<<" "<<col;
	return 0;
}
