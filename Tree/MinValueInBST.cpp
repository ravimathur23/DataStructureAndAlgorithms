#include <iostream>
using namespace std;

class Tree{
		int data;
	public:
		Tree(int d):data(d){left= NULL; right=NULL;};
		Tree * left; Tree * right;
		int get_data(){return data;}
};

int min_value_in_bst(Tree *node){
	if(node->left == NULL)
	{
		return node->get_data();
	}
	
	min_value_in_bst(node->left);
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
	
	cout<<"Min value in BST::"<<min_value_in_bst(root);
	
	return 0;
}
