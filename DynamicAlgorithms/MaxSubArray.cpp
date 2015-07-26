#include <iostream>
using namespace std;


int maxSubArray(int a[], int len){
	int max_so_far = 0, tmp_max = 0, neg=0;
	bool isArrNeg = true;
	
	for(int i=0;i<len;i++){
		
		tmp_max += a[i];
		
		if(tmp_max<0){
			neg+=tmp_max;
			tmp_max=0;
		}
			
		if(tmp_max>max_so_far){
			max_so_far = tmp_max;
			isArrNeg = false;
		}
	}
	
	if(isArrNeg)
		return neg;
	else
		return max_so_far;
}

int main() {
	// your code goes here
	int a[] = {3,-1,2,4,-5,10,-5,7};
	int b[] = {-1, -3, -5, -6, -8, -10,-1,-1};
	int c[] = {1,2,3,4,5,6,7,8};
	int len = sizeof(a)/sizeof(a[0]);
	cout<<"Sum of max sub array = "<<maxSubArray(a, len)<<endl;
	cout<<"Sum of max sub array = "<<maxSubArray(b, len)<<endl;
	cout<<"Sum of max sub array = "<<maxSubArray(c, len)<<endl;
	return 0;
}
