#include <iostream>
using namespace std;

int checkOddNumOfOccur(int arr[], int len){
	int result = 0;
	
	for(int i=0;i<len;i++)
	{
		result = result ^ arr[i];
	}
	
	return result;
}
int main() {
	// your code goes here
	int arr[] = {1,2,1,2,5,5,7,8,8};
	int len = sizeof(arr) / sizeof(arr[0]);
	
	cout<<"checkOddNumOfOccur: "<<checkOddNumOfOccur(arr, len);
	return 0;
}
