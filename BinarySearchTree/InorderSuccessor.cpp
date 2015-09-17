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

Node* search(Node* curr, int key){
	if(curr == NULL || curr->data == key)
		return curr;
		
	if(key > curr->data){
		search(curr->right, key);
	}
	else
		search(curr->left, key);
}

Node* find_left_most_right_subtree(Node* curr){
	if(curr->left == NULL)
		return curr;
	
	return find_left_most_right_subtree(curr->left);
}

Node* findSuccessor(Node* curr, Node* n){
	if(n == NULL)
		return NULL;

	if(n->right !=  NULL){
		return find_left_most_right_subtree(n->right);
	}
	else
	{
		Node * suc = NULL;
		while(curr != NULL){
			if(curr->data > n->data){
				suc = curr;
				curr = curr->left;
			}
			else if(curr->data < n->data){
				curr=  curr->right;
			}
			else{
				break;	
			}
		}
		return suc;
	}
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
	
	Node * node = findSuccessor(root, search(root, 20));
	if(node){
		cout<<node->data;
	}
	else{
		cout<<"NULL";
	}
	
	return 0;
}
