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

bool checkLeavesAtSameLevel(Tree* node, int level, int *leafLevel){
    if(node == NULL)
        return true;
    
    if(node->left == NULL && node->right == NULL){
        if(leafLevel == NULL){
            leafLevel = new int(level);
            return true;
        }
        
        return (*leafLevel == level);
    }
    
    return checkLeavesAtSameLevel(node->left, level+1, leafLevel) &&
    checkLeavesAtSameLevel(node->right, level+1, leafLevel);
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

    int level = 1;
    int leafLevel = 0;
    cout<<checkLeavesAtSameLevel(root, level, &leafLevel);
    
    return 0;
}
