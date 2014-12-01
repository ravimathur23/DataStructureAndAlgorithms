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
	if(node== NULL)
		return 0;
	
	int lh= treeHeight(node->left);
	int rh = treeHeight(node->right);
	
	if(lh>rh)
	    return lh+1;
	else
	    return rh+1;
}
void maxwidthrecur(Tree *node, int* node_arr, int level){
	if(node){
	    
		node_arr[level++]++;
		maxwidthrecur(node->left, node_arr, level);
		maxwidthrecur(node->right, node_arr, level);
	}
}
int maxwidth(Tree *node)
{
 	int height = treeHeight(node);
	
	int node_arr[100]={}, numlen=0;
	
	maxwidthrecur(node, node_arr, numlen);
	
	int max = node_arr[0];
	
	for(int i=0;i<height;i++){
		if(max < node_arr[i])
			max = node_arr[i];
	}
	return max;	
}
int main() {
	// your code goes here
	Tree *root = new Tree(20);
	Tree *left = new Tree(9);
	Tree *right = new Tree(22);
	root->left = left;
	root->right = right;
	root->right->right = new Tree(25);
	root->right->left = new Tree(21);
	
	Tree *left_1 = new Tree(8);
	Tree *right_1 = new Tree(10);
	root->left->left =left_1;
	root->left->left->left = new Tree(7);
	root->left->right = right_1;
	
	cout<<"inorder : ";
	print_inorder(root);
	cout<<endl<<"MaxWidth="<<maxwidth(root)<<endl;
	return 0;
}
