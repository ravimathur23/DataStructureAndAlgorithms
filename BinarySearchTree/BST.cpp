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
Node* deleteNode(Node* curr, int key){
	if(curr == NULL)
		return curr;
	
	if(curr->data > key){
		curr->left = deleteNode(curr->left, key);
	}
	else if(curr->data < key){
		curr->right = deleteNode(curr->right, key);
	}
	else{
		if(	curr->left == NULL)
		{
			Node* tmp = curr->right;
			delete curr;
			return tmp;
		}
		else if(curr->right == NULL){
			Node* tmp = curr->left;
			delete curr;
			return tmp;
		}
		else{
			Node* tmp = find_left_most_right_subtree(curr->right);
			curr->data = tmp->data;
			curr->right = deleteNode(curr->right, tmp->data);
		}
	}
	return curr;
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
	
	if(search(root, 70)){
		cout<<"found"<<endl;
	}
	else{
		cout<<"Sorry did not find!"<<endl;
	}
	
	inorder(root);
	deleteNode(root, 50);
	cout<<endl;
	inorder(root);
	deleteNode(root, 30);
	cout<<endl;
	inorder(root);
	deleteNode(root, 70);
	cout<<endl;
	inorder(root);
	return 0;
}
