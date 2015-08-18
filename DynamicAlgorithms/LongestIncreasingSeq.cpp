#include <iostream>
using namespace std;

//Time complexity = O(n*n);

int longestIncreasingSeq(int arr[], int len){
	
	int li[len];
	for(int i=0;i<len;i++)
		li[i] = 1;
	
	for(int i=1;i<len;i++){
		for(int j=0;j<i;j++){
			if( (arr[i]>arr[j]) &&  (li[i] < li[j]+1) ){
				li[i]++;
			}
		}
	}
	
	int max = 0;
	for(int i=0;i<len;i++)
	{
		if(max < li[i])
			max = li[i];
	}
	
	return max;
}

int main() {
	
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	int brr[] = {10, 8, 7,11, 2,4,6};
	
	int len_arr = sizeof(arr)/sizeof(arr[0]);
	int len_brr = sizeof(brr)/sizeof(brr[0]);
	
	cout<<longestIncreasingSeq(arr, len_arr)<<endl;
	cout<<longestIncreasingSeq(brr, len_brr)<<endl;
	return 0;
}
