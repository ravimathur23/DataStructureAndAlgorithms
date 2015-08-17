#include <iostream>
using namespace std;

// Time complexity = O(n)

void fibonacci(int n){
	int a = 0, b = 1;
	int tmp = 0;
	
	cout<<a<<" "<<b<<" ";
	
	for(int i=2;i<n;i++){
		tmp = b + a;
		cout<<tmp<<" ";
		a = b; b = tmp; 
	}
}	

int main() {
	int n = 20;
	
	fibonacci(n);
	
	return 0;
}
