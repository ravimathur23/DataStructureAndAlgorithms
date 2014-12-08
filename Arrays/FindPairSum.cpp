#include <iostream>
using namespace std;
void checkPair(int arr[], int count, int num){
	bool hashMap[10000] = {0};
	
	for(int i=0;i<count;i++){
		int tmp = num - arr[i];
		
		if((tmp > 0) && (hashMap[tmp]==1))
		{
			cout<<"Found : "<<arr[i]<<" "<<tmp<<endl;
		}
		hashMap[arr[i]] = true;
	}
}
int main() {
	// your code goes here
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	
	checkPair(arr, 15, 8);
	return 0;
}
