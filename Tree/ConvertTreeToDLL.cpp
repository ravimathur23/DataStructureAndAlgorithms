#include <iostream>
#include <limits>
#include <queue>
using namespace std;

class Tree{
    int data;
public:
    Tree(int d){
        data = d;
        left = NULL;
        right = NULL;
        random = NULL;
    }
    int getData(){return data;}
    void setData(int d){data=d;}
    Tree *left, *right, *random;
};

Tree* get_node(int d){
    Tree *node = new Tree(d);
    return node;
}

void printTree(Tree* node){
    if(node == NULL)
        return;
    
    printTree(node->left);
    printTree(node->right);
    
    cout<<node->getData()<<" ";
    
    return;
}

int depthOfOddLevel(Tree* node, int level){
    if(node == NULL)
        return 0;
    
    if(node->left == NULL && node->right == NULL && level%2){
        return level;
    }
    
    return max(depthOfOddLevel(node->left, level+1), depthOfOddLevel(node->right, level+1));

}

void convertToDLL(Tree* node, Tree** head, Tree** prev){
	if(node == NULL)
		return;

	convertToDLL(node->left, head, prev);
	
	if(*prev == NULL){
		*head = node;
	}
	else{
		node->left = *prev;
		(*prev)->right = node;
	}
	*prev = node;
	
	convertToDLL(node->right, head, prev);
	return;
}

void printDLL(Tree* dllHead){
	while(dllHead){
		cout<<dllHead->getData()<<" ";
		dllHead = dllHead->right;
	}	
}

int main(){
    Tree* root = new Tree(74);
    root->left = new Tree(28);
    root->right = new Tree(46);
    root->left->left = new Tree(16);
    root->left->right = new Tree(12);
    root->left->left->left = new Tree(7);
    root->left->left->left->right = new Tree(10);
    root->left->left->right = new Tree(9);
    root->right->left = new Tree(21);
    root->right->right = new Tree(25);
    root->right->right->left = new Tree(25);
    
    printTree(root);
    cout<<endl;
	
	Tree* dllHead = NULL;
	Tree* prev = NULL;
	convertToDLL(root, &dllHead, &prev);
	printDLL(dllHead);
    return 0;
}
