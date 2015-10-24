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
    
    cout<<node->getData()<<" ";
    printTree(node->left);
    printTree(node->right);
    return;
}

int sumLeftLeafNode(Tree* node){
    if(node== NULL)
        return 0;
    
    int left = sumLeftLeafNode(node->left);
    int right = sumLeftLeafNode(node->right);
   
    if(node->left && node->left->left == NULL && node->left->right == NULL){
        return node->left->getData()+left+right;
    }
    return left+right;
}

int main(){
    Tree *root = get_node(20);
    root->left = get_node(9);
    root->left->left = get_node(5);
    root->left->right = get_node(12);
    root->left->right->right = get_node(15);
    root->right = get_node(49);
    root->right->left = get_node(23);
    root->right->right= get_node(52);
    root->right->right->left = get_node(50);
    cout<<sumLeftLeafNode(root)<<endl;
    return 0;
}
