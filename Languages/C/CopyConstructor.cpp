#include <iostream>
using namespace std;

class Ravi{
	int *p;
	
	public:
	
	Ravi(){
		cout<<"Ravi"<<endl;
	}
	
	Ravi(int num){
		cout<<"Normal constructor"<<endl;
		p = new int;
		*p = num;
	}

	Ravi(const Ravi& ob){
		cout<<"Copy constructor"<<endl;
		p = new int;
		*p = *ob.p;
	}
	
	~Ravi(){
		cout<<"Destructor"<<endl;
		delete p;
	}
	
	int display() const{
	//	Ravi();
		return *p;
	}
	
};

int getLen(const Ravi ob1){
	return ob1.display();
}

int main() {
	// your code goes here
	Ravi ob1(6);
	cout<<getLen(ob1)<<endl;
	cout<<"end"<<endl;
	return 0;
}
