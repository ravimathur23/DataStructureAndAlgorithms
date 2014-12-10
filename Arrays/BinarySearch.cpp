#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int num){
	if(right>=left){
		
		if((right == left) && (arr[left] == num))
			return 1;

		int mid = left + (right-left)/2;
		
		if(arr[mid] == num)
			return 1;
		else if(arr[mid] > num)
			return binarySearch(arr, left, mid-1, num);
		else
			return binarySearch(arr, mid+1, right, num);
	}
	else
		return -1;
}
int main() {
	// your code goes here
	int arr[] = {1,2,5,6,10,15,17,20,24,26,30};
	
	int len = sizeof(arr)/sizeof(arr[0]);
	cout<<"binarySearch = "<<binarySearch(arr, 0, len-1, 15)<<endl;
	
	return 0;
}
