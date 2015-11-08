#include<iostream>
#include<limits.h>
using namespace std;

void print_arr(int arr[], int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void max_pair(int *arr, int n){
    int firstMax = max(arr[1], arr[0]);
    int secondMax = min(arr[1], arr[0]);
    
    for(int i=2;i<n;i++){
        if(arr[i]>firstMax){
            secondMax = firstMax;
            firstMax = arr[i];
        }
        if(arr[i] > secondMax && arr[i] < firstMax){
            secondMax = arr[i];
        }
    }
    
    cout<<"Pair Sum="<<firstMax+secondMax<<endl;
}

int main(){
    int arr[] = {10,22, 35, 11, 5,75,65,80, 3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    max_pair(arr, n);
    return 0;
}
