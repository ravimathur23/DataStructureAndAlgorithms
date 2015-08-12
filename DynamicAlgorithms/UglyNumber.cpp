#include <iostream>
using namespace std;

int min(int a, int b, int c){
	int min_val = a;
	
	if(b<a)
		min_val = b;
	
	if(min_val > c)
		min_val = c;
	
	return min_val;
}

void printUglyNum(int uglyNum){
	int Ugly[160];
	
	Ugly[0] = 1; 
	int i2 = 0, i3 = 0, i5 = 0;
	int nxt_mul_2 = 2, nxt_mul_3 = 3, nxt_mul_5 = 5;
	
	for(int i=1;i<uglyNum;i++){
		int curr_ugly_num = min(nxt_mul_2, nxt_mul_3, nxt_mul_5);
		Ugly[i] = curr_ugly_num;
		
		if(curr_ugly_num == nxt_mul_2)
		{
			i2++;
			nxt_mul_2 = Ugly[i2]*2;
		}
		if(curr_ugly_num == nxt_mul_3)
		{
			i3++;
			nxt_mul_3 = Ugly[i3]*3;
		}
		if(curr_ugly_num == nxt_mul_5){
			i5++;
			nxt_mul_5 = Ugly[i5]*5;
		}
	}
	
	for(int i=0;i<150;i++)
		cout<<" "<<Ugly[i]<<" ";
}

int main() {
	int nthUglyNum = 150;
	printUglyNum(nthUglyNum);
	
	return 0;
}
