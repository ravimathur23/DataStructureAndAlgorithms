#include <iostream>
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

Node* find_left_most_right_subtree(Node* curr){
	if(curr->left == NULL)
		return curr;
	
	return find_left_most_right_subtree(curr->left);
}
Node* find_right_most_left_subtree(Node* curr){
	if(curr->right == NULL)
		return curr;
		
	return find_right_most_left_subtree(curr->right); 
}

void findPreSuc(Node* curr, Node*& pre, Node*& suc, int key){
	if(curr == NULL)
		return;
	
	if(curr->data == key){
		if(curr->right != NULL){
			suc = find_left_most_right_subtree(curr->right);
		}
		else if(curr->left != NULL){
			pre = find_right_most_left_subtree(curr->left);
		}
	}
	
	if(curr->data > key){
		suc = curr;
		findPreSuc(curr->left, pre, suc, key);
	}
	else if(curr->data < key){
		pre = curr;
		findPreSuc(curr->right, pre, suc, key);
	}
	
	return;
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
	insertNode(root,10);
	
	Node* pre = NULL, *suc = NULL;
	findPreSuc(root, pre, suc, 1);
		
	
	cout<<(pre ? pre->data : -1)<<" "<<(suc ? suc->data : -1);
	return 0;
}
