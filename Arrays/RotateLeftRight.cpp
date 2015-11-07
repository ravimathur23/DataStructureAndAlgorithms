#include<iostream>
using namespace std;

void print_arr(int arr[], int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void reverse(int *arr, int start, int end){
    int sz = (end-start+1)/2;
    for(int i=0;i<sz;i++){
        int tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++;end--;
    }
}
void leftRotate(int *arr, int d, int n){
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr, 0, n-1);
}
void rightRotate(int *arr, int d, int n){
    reverse(arr, n-d, n-1);
    reverse(arr, 0, n-d-1);
    reverse(arr, 0, n-1);
}
int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    print_arr(arr, n);
    reverse(arr, 0, n-1);
    print_arr(arr, n);
    reverse(arr, 0, n-1);
    print_arr(arr, n);
    leftRotate(arr, 2, n);
    print_arr(arr, n);
    rightRotate(arr, 2, n);
    print_arr(arr, n);
    return 0;
}
