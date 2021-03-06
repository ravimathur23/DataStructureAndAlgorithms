#include <iostream>
#include <climits>
using namespace std;

class Node{
	public:
		int data;
		Node * left, *right;
		Node(int d){data = d; ;left=NULL;right=NULL;} 
};

Node* createNode(int d){
	Node * node = new Node(d);
	return node;
}

Node* insertNode(Node *curr, int d){
	if(curr == NULL){
		return createNode(d);
	}
	
	if( d > curr->data){
		curr->right = insertNode(curr->right, d);
	}
	else
	{
		curr->left = insertNode(curr->left, d);
	}
	return curr;
}

void inorder(Node *curr){
	if(curr == NULL)
		return;
		
	inorder(curr->left);
	cout<<curr->data<<" ";
	inorder(curr->right);
}

int isBST(Node* curr, int min= INT_MIN, int max=INT_MAX){
	if(curr == NULL)
		return 1;
	
	if(curr->data < min || curr->data > max)
		return 0;
	
	return (isBST(curr->left, min, (curr->data)-1) && isBST(curr->right, (curr->data)+1, max)); 
}

int main() {
	// your code goes here
	Node *root = createNode(50);
	insertNode(root,80);
	insertNode(root,20);
	insertNode(root,40);
	insertNode(root,60);
	insertNode(root,30);
	insertNode(root,70);
	
	cout<<"isBST="<<isBST(root);
	return 0;
}
