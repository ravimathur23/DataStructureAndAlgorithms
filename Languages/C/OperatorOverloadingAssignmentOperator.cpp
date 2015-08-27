#include <iostream>
using namespace std;

class Test{
	
		int *i;
	
	public:
		Test(){
			i = new int();
			*i=0;
		}
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
		
		Test& operator=(const Test& ob1){
			if(this == &ob1)
				return *this;
			
			*i = *ob1.i;
			return *this;
		}
		
		int get_i(){return *i;}
		void change_i(int num){*i = num;}
};
int main() {
	Test *ob1 = new Test(5);
	++(*ob1);
	cout<<ob1->get_i();
	cout<<((*ob1)++)->get_i();
	cout<<ob1->get_i();
	
	Test ob2;
	ob2 = *ob1;
	cout<<ob2.get_i();
	Test ob3;
	ob3 = ob2;
	ob2.change_i(10);
	cout<<ob3.get_i()<<ob2.get_i();
	return 0;
}
