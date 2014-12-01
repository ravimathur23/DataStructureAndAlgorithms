#include <iostream>
using namespace std;

class Tree{
		int data;
	public:
		Tree(int d):data(d){left= NULL; right=NULL;};
		Tree * left; Tree * right;
		int get_data(){return data;}
};
void print_inorder(Tree *node){
	if(node == NULL)
		return;
	
	print_inorder(node->left);
	cout<<node->get_data()<<" ";
	print_inorder(node->right);
}

int treeHeight(Tree *node){
	if(node == NULL)
		return 0;
		
	int left=treeHeight(node->left);
	int right=treeHeight(node->right);
	
	if(left>right)
		return left+1;
	else
		return right+1;
}
bool checkHeightBalanced(Tree *node){
	if(node == NULL)
		return true;
		
	int left_h = treeHeight(node->left);
	int right_h = treeHeight(node->right);
	
	if((abs(left_h - right_h) < 2) && checkHeightBalanced(node->left) && checkHeightBalanced(node->right))
		return true;
	else
		return false;
}
int main() {
	// your code goes here
	Tree *root = new Tree(20);
	Tree *left = new Tree(9);
	Tree *right = new Tree(21);
	root->left = left;
	root->right = right;
	root->right->right = new Tree(23);
	//root->right->right->right = new Tree(25);
	
	Tree *left_1 = new Tree(8);
	Tree *right_1 = new Tree(10);
	root->left->left =left_1;
	root->left->right = right_1;
	
	
	print_inorder(root);
	
	
	cout<<checkHeightBalanced(root);
	
	return 0;
}
