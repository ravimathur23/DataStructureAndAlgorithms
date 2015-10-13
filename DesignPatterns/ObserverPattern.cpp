#include <iostream>
#include <vector>
using namespace std;

class Subject{
	int data;
	public:
	vector<class Observer *> views;
	void attach(Observer *ob){
		views.push_back(ob);
	}
	void set_data(int d){
		data  = d;
		notify_all();
	}
	void notify_all();
};

class Observer{
	public:
	Observer(Subject *sub){
		sub->attach(this);
	}
	virtual void set_data(int data) = 0;
	virtual void get_data() = 0;
};

void Subject::notify_all(){
		for(int i=0;i<views.size();i++){
			views[i]->set_data(data);
		}
}

class RavObserver : public Observer{
	int data;
	public:
	RavObserver(Subject *sub):Observer(sub){}
	virtual void set_data(int d){data = d;}
	virtual void get_data(){cout<<"Rav-"<<data<<endl;}
};
class MatObserver : public Observer{
	int data;
	public:
	MatObserver(Subject *sub):Observer(sub){}
	virtual void set_data(int d){data = d;}
	virtual void get_data(){cout<<"Mat-"<<data<<endl;}
};
int main() {
	// your code goes here
	Subject sub;
	Observer *ob1 = new RavObserver(&sub);
	Observer *ob2 = new MatObserver(&sub);
	sub.set_data(12);
	ob1->get_data();
	ob2->get_data();
	return 0;
}
