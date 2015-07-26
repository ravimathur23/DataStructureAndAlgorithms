#include <iostream>
using namespace std;

bool checkDiv(int &num, int div){
		if(num == 0)
			return num;

		while(1){
			int lastNum = num;
			int rem = num%div;int num = num/div;
			
			if(rem == 0 && num != 1){
				continue;
			}else if(rem == 0 && num == 1)
				return true;
			else{
				num = lastNum;
				return false;
			}
		}
}

bool uglyNumber(int nth){
	int counter=1, numSeq=2;
	bool isUglyNum = false;
	
	if(nth == 1)
		return true;
	
	while(1){
		int num = numSeq;
		isUglyNum = checkDiv(num, 2);
		isUglyNum = checkDiv(num, 3);
		isUglyNum = checkDiv(num, 5);
		
		if(isUglyNum){
			++counter;
		}
		
		if(counter ==  nth)
			break;
		
		++numSeq;
	}

	return isUgleNum;
}

int main() {
	// your code goes here
	int nth = 1;
	
	cout<<"ugle number at "+nth+"="+uglyNumber(nth);
	
	return 0;
}
