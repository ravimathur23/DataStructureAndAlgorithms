#include <iostream>
#include <string.h>
using namespace std;

int longestPathUtil(int arr[3][3], int dp[3][3], int i, int j){
	if(i<0 || i>3 || j<0 || j>3){
		return 0;
	}
	
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	
	if(arr[i][j]+1 == arr[i+1][j])
		return dp[i][j] = 1+longestPathUtil(arr, dp, i+1, j);
	
	if(arr[i][j]+1 == arr[i-1][j])
		return dp[i][j] = 1+longestPathUtil(arr, dp, i-1, j);
		
	if(arr[i][j]+1 == arr[i][j+1])
		return dp[i][j] = 1+longestPathUtil(arr, dp, i, j+1);
		
	if(arr[i][j]+1 == arr[i][j-1])
		return dp[i][j] = 1+longestPathUtil(arr, dp, i+1, j-1);
	
	return dp[i][j] = 1;
}
int longestPath(int arr[3][3]){
	int res = 1;
	int dp[3][3];
	memset(dp, -1, sizeof(dp));
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(dp[i][j] == -1){
				longestPathUtil(arr, dp, i, j);
			}
			
			res = max(res, dp[i][j]);
		}
	}
	return res;
}
int main() {
	int arr[3][3] = { 4,5,6,
					  9,8,7,
					  1,2,3};
	cout<<longestPath(arr);
	
	return 0;
}
