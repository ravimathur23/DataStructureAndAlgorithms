#include <iostream>
using namespace std;

void selectionSort(int arr[], int len){
	for(int i=0;i<len;i++)
	{
		for(int j=i;j<len;j++){
			if(arr[i]>arr[j]){
			    int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}

	cout<<" "<<arr[i]<<" ";
	}
	cout<<endl;
}
int main() {
	// your code goes here
	int arr[] = {1,30,26,24,10,7,7,6,3,1,1};
	
	int len = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr, len);
	
	return 0;
}
