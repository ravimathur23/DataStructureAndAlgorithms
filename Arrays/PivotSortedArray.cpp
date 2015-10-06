#include <iostream>
using namespace std;

void print_array(int arr[], int sz){
	for(int i=0;i<sz;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void reverse(int arr[], int start, int end){
	
	int tmp;
	while(start <= end){
		tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		start++;end--;
	}
}
void reverseBy(int arr[], int sz, int d){
	reverse(arr, 0, d-1);
	reverse(arr, d, sz-1);
	reverse(arr, 0, sz-1);
	print_array(arr, sz);
}

int main() {
	// your code goes here
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int sz = sizeof(arr)/sizeof(arr[0]);
	int d = 3;
	print_array(arr, sz);
	reverseBy(arr, sz, d);
	
	return 0;
}
