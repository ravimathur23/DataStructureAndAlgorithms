#include <iostream>
using namespace std;

void insertionSort(int arr[], int len){
	for(int i=1;i<len;i++){
		
		int j = i-1;
		int key = arr[i];
		
		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j--;
		}
	
	arr[j+1] = key;
	}
	
	for(int i=0;i<len;i++)
		cout<<" "<<arr[i]<<" ";
}

int main() {
	// your code goes here
	int arr[] = {1,2,4,20,18,15,13,19,23,12,5,6};
	int len = sizeof(arr)/sizeof(arr[0]);
	
	insertionSort(arr, len);	
	return 0;
}
