#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right){
	int numLeft = mid-left+1;
	int numRight = right-mid;
	int L[numLeft], R[numRight];
	for(int i=0;i<numLeft;i++){
		L[i] = arr[left+i];
	}
	for(int i=0;i<numRight;i++){
		R[i] = arr[mid+1+i];
	}
	
	int i=0, j=0, k=left;
	while(i<numLeft && j<numRight){
		if(L[i]<=R[j]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	while(i<numLeft){
		arr[k] = L[i];
		i++;k++;
	}
	while(j<numRight){
		arr[k] = R[j];
		j++;k++;
	}
}
void mergeSortUtil(int arr[], int left, int right){
	if(left < right){
		int mid = left + (right-left)/2;
		mergeSortUtil(arr, left, mid);
		mergeSortUtil(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
}
void mergeSort(int arr[], int sz){
	mergeSortUtil(arr, 0, sz-1);
}
void printArr(int arr[], int sz){
	for(int i=0;i<sz;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main() {
	int arr[] = {12,11,13,5,6,7,100,9,7};
	int sz = sizeof(arr)/sizeof(int);
	printArr(arr, sz);
	mergeSort(arr, sz);
	printArr(arr, sz);
	return 0;
}
