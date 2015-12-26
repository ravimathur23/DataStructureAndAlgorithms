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

void getMaxElemInTreeUtil(Tree* node, int &max){
    if(node == NULL)
        return;
    
    if(node->getData() > max)
        max = node->getData();
    getMaxElemInTreeUtil(node->left, max);
    getMaxElemInTreeUtil(node->right, max);
}
int getMaxElemInTree(Tree* node){
    int max = INT_MIN;
    getMaxElemInTreeUtil(node, max);
    return max;
}

int main(){
    Tree *root = get_node(-20);
    root->left = get_node(-9);
    root->left->left = get_node(-5);
    root->left->right = get_node(-12);
    root->left->right->right = get_node(-15);
    root->right = get_node(-49);
    root->right->left = get_node(-5);
    root->right->right= get_node(-52);
    root->right->right->left = get_node(-50);
    
    cout<<getMaxElemInTree(root);
    
    return 0;
}
