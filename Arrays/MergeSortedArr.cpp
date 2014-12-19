#include <iostream>
using namespace std;

void print_arr(int arr[], int sz){
	for(int i=0;i<sz;i++)
		cout<<" "<<arr[i]<<" ";
}
void merge(int M[], int N[], int szMplusN, int szN){
	//pushing M data to right end
	int k = szMplusN-1;
	for(int i=szMplusN-1;i>=0;i--){
		if(M[i] != -1){
			M[k] = M[i];
			k--;
		}
	}
	
	int l = 0;
	int m = szN;
	for(int n=0;n<szMplusN;n++){
		if(N[l] < M[m]){
			M[n] = N[l];
			l++;
		}
		else
		{
			M[n] = M[m];
			m++;
		}
	}
	print_arr(M, szMplusN);
}
int main() {
	// your code goes here
	int MplusN[] = {2,-1,5,-1,10,12,13,-1};
	int N[] = {5,8,15};
	int szMplusN = sizeof(MplusN)/sizeof(MplusN[0]);
	int szN = sizeof(N)/sizeof(N[0]);
	
	merge(MplusN, N, szMplusN, szN);
	return 0;
}
