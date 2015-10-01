#include <iostream>
#include <string>

using namespace std;

class Name{
	public:
		virtual void print_name() = 0;
};

class Ravi : public Name{
	string name;
	public:
		Ravi(string s):name(s){}
		void print_name(){
			cout<<name<<endl;
		}
};

class Decorator : public Name{
	Name *name;
	public:
		Decorator(Name *n):name(n){}
		void print_name(){
			name->print_name();
		}
};
class Mathur : public Decorator{
	public:
		Mathur(Name *n):Decorator(n){}
		void print_name(){
			Decorator::print_name();
			cout<<"Mathur"<<endl;
		}
};
class Sharma : public Decorator{
	public:
		Sharma(Name *n):Decorator(n){}
		void print_name(){
			Decorator::print_name();
			cout<<"Sharma"<<endl;
		}
};
int main(){
	Name *nam = new Mathur(new Sharma(new Ravi("ravi")));
	nam->print_name();
	return 0;
}
