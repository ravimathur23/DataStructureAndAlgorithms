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
void leftRotate(int *arr, int d, int start, int end){
    d = d+start;
    reverse(arr, start, d-1);
    reverse(arr, d, end);
    reverse(arr, start, end);
}
void rightRotate(int *arr, int d, int start, int end){
    reverse(arr, end-d+1, end);
    reverse(arr, start, end-d);
    reverse(arr, start, end);
}
void move(int *arr, int from, int to){
    if(from == to){
        return;
    }
    else if(from > to){
        rightRotate(arr, 1, to, from);
    }
    else{
        leftRotate(arr, 1, from, to);
    }
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    print_arr(arr, n);
    move(arr, 8, 1);
    print_arr(arr, n);
    move(arr,1,8);
    print_arr(arr, n);
    return 0;
}
