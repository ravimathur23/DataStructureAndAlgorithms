#include <iostream>
using namespace std;

bool checkDiv(int &num, int div){
		if(num == 0)
			return num;

		while(1){
			
			int lastNum = num;
			
			int rem = num%div;num = num/div;
			
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

int uglyNumber(int nth){
	int counter=1, numSeq=2;
	bool isUglyNum = false;
	
	if(nth == 1)
		return true;
	
	while(1){
		int num = numSeq;
		
		isUglyNum = checkDiv(num, 2);
		
		if(num != 1)
			isUglyNum = checkDiv(num, 3);
		
		if(num != 1)
			isUglyNum = checkDiv(num, 5);
		
		
	//	cout<<"rr"<<isUglyNum<<endl;
		if(isUglyNum){
			++counter;
		}
		
	//	cout<<counter << nth<<endl;
		if(counter ==  nth)
			break;
		
		++numSeq;
	}

	return numSeq;
}

int main() {
	// your code goes here
	int nth = 150;
	
	cout<<"ugly number at "<<nth<<"="<<uglyNumber(nth);
	
	return 0;
}
