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

Tree* lca(Tree* node, int key1, int key2){
    if(node == NULL)
        return NULL;
    
    if(node->getData() == key1 || node->getData() ==  key2){
        return node;
    }
    
    Tree* left = lca(node->left, key1, key2);
    Tree* right = lca(node->right, key1, key2);
    
    if(left && right)
        return node;
    
    return (left != NULL)?left:right;
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

    cout<<lca(root, 7, 12)->getData();
    return 0;
}
