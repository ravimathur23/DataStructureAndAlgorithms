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

bool checkBalanceTree(Tree* node){
    if(node== NULL)
        return true;
    if(node->left && node->right == NULL)
        return false;
    if(node->right && node->left == NULL)
        return false;
    
    bool left = checkBalanceTree(node->left);
    bool right = checkBalanceTree(node->right);

    if(left && right)
        return true;
    else
        return false;
}

int main(){
    Tree *root = get_node(1);
    root->left = get_node(2);
    root->right = get_node(3);
    root->left->left = get_node(4);
    root->left->right = get_node(5);
    root->right->left = get_node(6);
    root->right->right = get_node(7);
    cout<<checkBalanceTree(root)<<endl;
    return 0;
}
