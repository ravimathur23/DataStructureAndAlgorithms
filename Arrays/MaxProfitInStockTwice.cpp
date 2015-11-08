#include<iostream>
using namespace std;

void print_arr(int arr[], int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void maxProfit(int *arr, int n){
    int min_index = 0;
    int max_so_far = 0;
    int sum = 0;
    int count = 1;
    for(int i=1;i<n;i++){
        if(arr[i] > arr[min_index]){
            if(max_so_far < arr[i]-arr[min_index]){
                max_so_far =  arr[i]-arr[min_index];
            }
        }else{
        
            if(count++ > 2)
                break;

            min_index = i;
            sum = sum+max_so_far;
            max_so_far = 0;
        }
    }
    
    if(count > 2)
        cout<<"sum="<<sum<<endl;
    else
        cout<<"sum="<<sum+max_so_far<<endl;
}

int main(){
    int arr[] = {10,22, 35, 11, 5,75,65,80, 3,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    maxProfit(arr, n);
    return 0;
}
