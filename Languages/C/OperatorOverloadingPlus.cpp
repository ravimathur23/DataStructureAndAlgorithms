#include <iostream>
using namespace std;

class Ravi{
	int len;int bdth;
	public:
	void set_len(int len){this->len = len;}
	void set_bdth(int bdth){this->bdth = bdth;}
	int get_len()const{return len;}
	int get_bdth()const{return bdth;}
	
	int area(){return len*bdth;}
	Ravi operator+(const Ravi& ob1){
		Ravi ob2;
		ob2.set_len(this->len+ob1.get_len());
		ob2.set_bdth(this->bdth+ob1.get_bdth());
		return ob2;
	}
	
};

int main() {
	// your code goes here
	Ravi ob1, ob2;
	ob1.set_len(3);ob2.set_len(5);
	ob1.set_bdth(2);ob2.set_bdth(6);
	cout<<ob1.area()<<" "<<ob2.area()<<endl;
	Ravi ob3 = ob1 + ob2;
	cout<<ob3.area()<<endl;
	return 0;
}
