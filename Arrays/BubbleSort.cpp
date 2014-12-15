#include <iostream>
using namespace std;
void bubbleSort(int arr[], int len){
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len-1;j++){
			if(arr[j]>arr[j+1]){
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
	
	for(int i=0;i<len;i++)
		cout<<" "<<arr[i]<<" ";
	
}
int main() {
	// your code goes here
	int arr[] = {1,2,4,20,18,15,13,19,23,12,5,6};
	int len = sizeof(arr)/sizeof(arr[0]);
	
	bubbleSort(arr, len);
	return 0;
}
