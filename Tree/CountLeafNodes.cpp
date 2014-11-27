#include <iostream>
using namespace std;

class Tree{
		int data;
	public:
		Tree(int d):data(d){left= NULL; right=NULL;};
		Tree * left; Tree * right;
		int get_data(){return data;}
};
int countLeafNode(Tree *node){
	if(node == NULL)
		return 0;
		
		if(node->left == NULL && node->right == NULL)
			return 1;
			
		return countLeafNode(node->left) + countLeafNode(node->right);
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
	
	cout<<countLeafNode(root);
	
	return 0;
}
