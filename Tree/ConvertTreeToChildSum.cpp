#include <iostream>
using namespace std;

class Tree{
		int data;
	public:
		Tree(int d):data(d){left= NULL; right=NULL;};
		Tree * left; Tree * right;
		int get_data(){return data;}
		void set_data(int d){data = d;}
};

void convertChildSum(Tree *node){
	if(node){

		int left=0, right=0;
		if(node->left == NULL && node->right == NULL)
			return;

		convertChildSum(node->left);
		convertChildSum(node->right);

		if(node->left)
			left = node->left->get_data();

		if(node->right)
			right = node->right->get_data();
		
		if(node->get_data() != (left+right));
		{
			int delta = node->get_data() - (left+right);
			if(delta > 0)
				node->left->set_data(left + delta);
			else
				node->set_data(node->get_data() - delta);
		}

	}
}

void print_inorder(Tree *node){
	if(node == NULL)
		return;
	
	print_inorder(node->left);
	cout<<node->get_data()<<" ";
	print_inorder(node->right);
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
	
	print_inorder(root);cout<<endl;
	convertChildSum(root);
	print_inorder(root);
	
	return 0;
}
