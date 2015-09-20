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

void addGreaterValue(Node* curr, int *sum){
	if(curr==NULL)
		return;
	
	addGreaterValue(curr->right, sum);
	*sum = *sum + curr->data;
	curr->data = *sum;
	addGreaterValue(curr->left, sum);
	
	return;
}

int main() {
	// your code goes here
	Node *root = createNode(50);
	insertNode(root,30);
	insertNode(root,20);
	insertNode(root,40);
	insertNode(root,70);
	insertNode(root,60);
	insertNode(root,80);
	
	int sum = 0;
	addGreaterValue(root, &sum);
	inorder(root);
	return 0;
}
