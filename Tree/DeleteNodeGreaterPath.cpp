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

Tree* delNodeGreaterPathUtil(Tree* node, int level, int pathSz){
    if(node == NULL)
        return NULL;

    node->left = delNodeGreaterPathUtil(node->left, level+1, pathSz);
    node->right = delNodeGreaterPathUtil(node->right, level+1, pathSz);
    
    if(node->left == NULL && node->right == NULL && level < pathSz)
    {
        delete node;
        return NULL;
    }
    
    return node;
}
void delNodeGreaterPath(Tree* node, int pathSz){
    
    int level  = 1;
    delNodeGreaterPathUtil(node, level, pathSz);
 
    return;
}

void printTree(Tree* node){
    if(node == NULL)
        return;
    
    cout<<node->getData()<<" ";
    printTree(node->left);
    printTree(node->right);
    return;
}

int main(){
    Tree *root = get_node(1);
    root->left = get_node(2);
    root->left->left = get_node(4);
    root->left->right = get_node(5);
    root->left->left->left = get_node(7);
    root->right = get_node(3);
    root->right->right= get_node(6);
    root->right->right->left = get_node(8);
    printTree(root);cout<<endl;
    delNodeGreaterPath(root, 4);
    printTree(root);
    return 0;
}
