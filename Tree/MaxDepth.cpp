#include <iostream>
using namespace std;

class Tree{
		int data;
	public:
		Tree(int d):data(d){left= NULL; right=NULL;};
		Tree * left; Tree * right;
		int get_data(){return data;}
};
int max_depth(Tree * node){
	if(node == NULL)
		return 0;
		
	int left_depth = max_depth(node->left);
	int right_depth = max_depth(node->right);
	
	if(left_depth > right_depth)
		return left_depth+1;
	else
		return right_depth+1;
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
	
	cout<<"Max depth="<<max_depth(root);
	return 0;
}
