#include <iostream>
using namespace std;

class Tree{
		int data;
	public:
		Tree(int d):data(d){left= NULL; right=NULL;};
		Tree * left; Tree * right;
		int get_data(){return data;}
};
void print_array(int node_arr[], int level){
	for (int i=0; i < level; i++)
	{
		cout<<node_arr[i]<<" ";
	}
}
void print_recur_ancestors(Tree *node, int num, int node_arr[], int level=0){
	if(node == NULL)
		return;
		
	node_arr[level++] = node->get_data();
	
	if(node->get_data() == num)
		print_array(node_arr, level);
		
	print_recur_ancestors(node->left, num, node_arr, level);
	print_recur_ancestors(node->right, num, node_arr, level);
}

void printAncestors(Tree *node, int num){
	int node_arr[100] = {};
	print_recur_ancestors(node, num, node_arr);
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
	
	printAncestors(root, 21);
	return 0;
}
