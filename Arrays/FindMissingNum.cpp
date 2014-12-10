#include <iostream>
using namespace std;

int findMissingNum(int arr[], int len){
	int sumArr = 0, totalSum = 0;
	int i=0;
	
	for(;i<len;i++)
	{
		
		sumArr += arr[i];
		totalSum += (i+1);
	}
	
    i++;
	totalSum += i;
	return totalSum - sumArr;
}	
int main() {
	// your code goes here
	int arr[] = {4,8,3,1,5,10,7,9,6};
	
	int len = sizeof(arr)/sizeof(arr[0]);
	cout<<"findMissingNum = "<<findMissingNum(arr, len)<<endl;
	
	return 0;
}
