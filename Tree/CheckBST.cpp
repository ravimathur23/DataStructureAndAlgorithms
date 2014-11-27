#include <iostream>
using namespace std;

class Tree{
		int data;
	public:
		Tree(int d):data(d){left= NULL; right=NULL;};
		Tree * left; Tree * right;
		int get_data(){return data;}
};

bool checkBST(Tree *node){
	static Tree *prev_node = NULL;
	
	if(node){
		if(!checkBST(node->left))
			return false;
		
		if(prev_node != NULL && node->get_data() <= prev_node->get_data())
			return false;
			
		prev_node = node;
		
		if(!checkBST(node->right))
			return false;
	}
	return true;
}

int main() {
	// your code goes here
	Tree *root = new Tree(20);
	Tree *left = new Tree(9);
	Tree *right = new Tree(21);
	root->left = left;
	root->right = right;
	
	Tree *left_1 = new Tree(8);
	Tree *right_1 = new Tree(10);
	root->left->left =left_1;
	root->left->right = right_1;
	
	cout<<"CheckBST="<<checkBST(root);
	return 0;
}
