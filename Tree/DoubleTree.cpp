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

void double_tree(Tree * node){
	if(node == NULL)
		return;
		
	Tree * temp = node->left;
	node->left = new Tree(node->get_data());
	node->left->left = temp;
	
	double_tree(node->left->left);
	double_tree(node->right);
}
int main() {
	// your code goes here
	Tree *root = new Tree(20);
	Tree *left = new Tree(9);
	Tree *right = new Tree(21);
	root->left = left;
	root->right = right;
	root->right->right = new Tree(23);
	root->right->right->right = new Tree(25);
	
	Tree *left_1 = new Tree(8);
	Tree *right_1 = new Tree(10);
	root->left->left =left_1;
	root->left->right = right_1;
	
	print_inorder(root);cout<<endl;
	double_tree(root);
	print_inorder(root);cout<<endl;
	return 0;
}

