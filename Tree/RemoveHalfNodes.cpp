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
    }
    int getData(){return data;}
    Tree *left, *right;
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

Tree* removeHalfNode(Tree* node){
    if(node==NULL){
        return NULL;
    }
    
    node->left = removeHalfNode(node->left);
    node->right = removeHalfNode(node->right);
  
    if((node->left && node->right == NULL)){
        Tree* tmp= node->left;
        delete node;
        return tmp;
    }
    else if(node->right && (node->left == NULL)){
        Tree* tmp = node->right;
        delete node;
        return tmp;
        
    }
    else{
        //
    }
    
    return node;
}

int main(){
    Tree *root = get_node(2);
    root->left = get_node(7);
    root->left->right = get_node(6);
    root->left->right->left = get_node(1);
    root->left->right->right = get_node(11);
    root->right = get_node(5);
    root->right->right = get_node(9);
    root->right->right->left = get_node(4);
   
    printTree(root);cout<<endl;
    removeHalfNode(root);
    
    printTree(root);
    return 0;
}
