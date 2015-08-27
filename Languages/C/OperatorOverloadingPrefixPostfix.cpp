#include <iostream>
using namespace std;

class Test{
	
		int *i;
	
	public:
		Test(int num){
			i = new int();
			*i=num;
		}
		
		~Test(){
			delete i;
		}
	
		Test& operator++(){
			++(*i);
			return *this;
		}
		
		Test* operator++(int){
			Test *tmp = new Test(*i);
			++(*i);
			return tmp;
		}
		
		int get_i(){return *i;}
};
int main() {
	Test *ob1 = new Test(5);
	++(*ob1);
	cout<<ob1->get_i();
	cout<<((*ob1)++)->get_i();
	cout<<ob1->get_i();
	return 0;
}
