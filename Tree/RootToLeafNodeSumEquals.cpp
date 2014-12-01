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

void print_sum_equal_or_not(int node_arr[], int numlen, int num){
	int sum =0;
	for (int i=0;i<numlen;i++)
	{
		sum+=node_arr[i];
	}
	
	bool isSumEqual = false;
	if(sum == num)
		isSumEqual = true;
	
	if(isSumEqual)
		cout<<"Root to leaf path sum equals to a given number!"<<endl;
	else
		cout<<"Root to leaf path sum DOES NOT equals to a given number!"<<endl;
			
}
void is_r2l_sum_eq(Tree* node, int node_arr[], int numlen, int num){
	if(node){
		node_arr[numlen++] = node->get_data();
		
		if(node->left == NULL && node->right == NULL)
			print_sum_equal_or_not(node_arr, numlen, num);
		else
		{
			is_r2l_sum_eq(node->left, node_arr, numlen, num);
			is_r2l_sum_eq(node->right, node_arr, numlen, num);
		}
	}
}
void RootToLeafSumEq(Tree *node, int num){
	int node_arr[100];
	is_r2l_sum_eq(node, node_arr, 0, num);
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
	
	print_inorder(root);cout<<endl;
	
	int num = 20+9+8;
	RootToLeafSumEq(root, num);
	return 0;
}

