#include <iostream>
using namespace std;

class Tree{
		int data;
	public:
		Tree(int d):data(d){left= NULL; right=NULL;};
		Tree * left; Tree * right;
		int get_data(){return data;}
};
void print_preorder(Tree *node)
{
	if(node == NULL)
		return;
	
	cout<<node->get_data()<<" ";
	print_preorder(node->left);
	print_preorder(node->right);
}
void mirror_tree(Tree *node){
	if(node == NULL)
		return;
	
	Tree *temp;
	temp = node->left;
	node->left = node->right;
	node->right = temp;
	
	mirror_tree(node->left);
	mirror_tree(node->right);
	return;
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
	
	cout<<"\npreoder : ";
	print_preorder(root);cout<<endl;
	mirror_tree(root);
	cout<<"\npreoder : ";
	print_preorder(root);
	return 0;
}
