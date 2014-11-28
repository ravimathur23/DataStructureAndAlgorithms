#include <iostream>
using namespace std;

class Tree{
		int data;
	public:
		Tree(int d):data(d){left= NULL; right=NULL;};
		Tree * left; Tree * right;
		int get_data(){return data;}
};

bool checkChildSum(Tree *node){
	
	if(node){
		if(!checkChildSum(node->left))
			return false;
	
	if(node->left==NULL || node->right==NULL)
		return true;
	else if(node->get_data() == (node->left->get_data()+node->right->get_data()))
		return true;
	else
		return false;
		
		
	return (!checkChildSum(node->right));
	}
	
	return true;
}

int main() {
	// your code goes here
	Tree *root = new Tree(20);
	Tree *left = new Tree(8);
	Tree *right = new Tree(12);
	root->left = left;
	root->right = right;
	root->right->right = new Tree(25);	
	Tree *left_1 = new Tree(3);
	Tree *right_1 = new Tree(6);
	root->left->left =left_1;
	root->left->right = right_1;
	
	cout<<checkChildSum(root)<<endl;
	
	return 0;
}
