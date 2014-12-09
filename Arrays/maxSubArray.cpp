#include <iostream>
using namespace std;

int maxSubArr(int arr[], int len){

		int max_so_far = 0, max_ending_here = 0;
		for(int i=0;i<len;i++){
			max_ending_here += arr[i];
			if(max_ending_here > 0)
			{
				if(max_so_far < max_ending_here)
					max_so_far = max_ending_here;
			}
			else
			{	
				max_ending_here = 0;
			}
		}

		return max_so_far;
}

int main() {
	// your code goes here
	int arr[] = {1,2,-1,2,-5};
	int len = sizeof(arr) / sizeof(arr[0]);
	
	cout<<"maxSubArr: "<<maxSubArr(arr, len);
	return 0;
}
