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
			
			delete i;
			i =  new int;
		
			*i = *ob1.i;
			return *this;
		}
		
		friend Test operator+(const Test& ob1, const Test& ob2);
		
		int get_i(){return *i;}
		void change_i(int num){*i = num;}
};

Test operator+(const Test& ob1, const Test& ob2){
	Test ob3;
	ob3.change_i(*ob1.i + *ob2.i);
	return ob3;
}

int main() {
	Test *ob1 = new Test(5);
	++(*ob1);
	cout<<ob1->get_i();
	cout<<((*ob1)++)->get_i();
	cout<<ob1->get_i();
	
	Test ob2;
	ob2 = *ob1;
	cout<<ob2.get_i();
	Test ob3, ob4;
	ob4 = ob3 = ob2;
	ob2.change_i(10);
	cout<<ob3.get_i()<<ob2.get_i()<<ob4.get_i();
	Test ob5 = ob3+ob4;
	cout<<endl<<ob5.get_i();
	return 0;
}
