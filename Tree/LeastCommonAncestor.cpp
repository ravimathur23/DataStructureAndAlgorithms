#include <iostream>
using namespace std;

class Tree{
		int data;
	public:
		Tree(int d):data(d){left= NULL; right=NULL;};
		Tree * left; Tree * right;
		int get_data(){return data;}
};

Tree* lca(Tree * node, int dat1, int dat2){
	if(node == NULL){
		return NULL;
	}	
	
	if(node->get_data() > dat1 && node->get_data() > dat2){
		return lca(node->left, dat1, dat2);
	}
	else if(node->get_data() < dat1 && node->get_data() < dat2){
		return lca(node->right, dat1, dat2);
	}
	
	return node; 
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
	
	cout<<lca(root, 8, 10)->get_data()<<endl;
	cout<<lca(root, 20, 21)->get_data()<<endl;

	return 0;
}
