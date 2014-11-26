#include <iostream>
using namespace std;

class Tree{
		int data;
	public:
		Tree(int d):data(d){left= NULL; right=NULL;};
		Tree * left; Tree * right;
		int get_data(){return data;}
};

void print_path(int num[], int numLen){
	for(int i=0;i<numLen;i++){
		cout<<num[i]<<" ";
	}	
	cout<<endl;
}

void print_path_recur(Tree * node, int num[], int numLen){
	if(node == NULL){
		return;
	}
	
	num[numLen++] = node->get_data();
	
	if(node->left == NULL && node->right == NULL){
		print_path(num, numLen);
	}
	else{
		print_path_recur(node->left, num, numLen);
		print_path_recur(node->right, num, numLen);
	}
}

void print_root_to_leaf(Tree * root){
	int num[100];
	print_path_recur(root, num, 0);
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

	print_root_to_leaf(root);
	
	return 0;
}
