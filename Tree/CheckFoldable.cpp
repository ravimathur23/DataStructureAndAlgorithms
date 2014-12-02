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
void mirror(Tree *node){
	if(node == NULL)
		return;
	
	Tree *tmp = NULL;
	tmp = node->left;
	node->left = node->right;
	node->right = tmp;
		
	mirror(node->left);
	mirror(node->right);
}
bool check_recur_fold(Tree *left, Tree *right){
	if(left == NULL && right == NULL)
		return true;
	
	if(left!=NULL && right!=NULL && check_recur_fold(left->left, right->left) && check_recur_fold(left->right, right->right))
		return true;
	else
		return false;
}
bool checkFoldable(Tree *node){
	if(node == NULL)
		return true;
	
	mirror(node->left);
	
	bool ret_value = check_recur_fold(node->left, node->right);
	
	mirror(node->left);
	
	return ret_value;
	
}

int main() {
	Tree *root = new Tree(20);
	root->left = new Tree(10);
	root->left->left = new Tree(9);
	root->left->left->right = new Tree(6);
	root->right = new Tree(21);
	root->right->right =  new Tree(22);
	root->right->right->left = new Tree(23);
	
	cout<<"inorder : ";
	print_inorder(root);
	cout<<"\ncheckFoldable="<<checkFoldable(root);
	
	return 0;
}
