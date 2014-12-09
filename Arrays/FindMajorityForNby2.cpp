#include <iostream>
using namespace std;

int findMajority(int arr[], int count){
	int hashMap[100] = {0};
	for(int i=0;i<count;i++){
		hashMap[arr[i]]++;
	}
	
	int max = 0;
	
	for(int i=0;i<99;i++){
		if(hashMap[i]>max){
			max = i;			
			}
		}
	}
	
	if(hashMap[i]>count/2)
		return max;
	else
		return -1;
}
int main() {
	// your code goes here
	int arr[] = {1,2,11,2,11,11,7,8,9,11,11,11,11,15,15};
	
	cout<<"findMajority "<<findMajority(arr, 15);
	return 0;
}
