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

int convertToSumTree(Tree* node){
    if(node == NULL)
        return 0;
       
    int old_val = node->getData();
    
    // Recursively call for left and right subtrees and store the sum as
    // new value of this node
    node->setData(convertToSumTree(node->left) + convertToSumTree(node->right));
    
    // Return the sum of values of nodes in left and right subtrees and
    // old_value of this node
    return node->getData() + old_val;
}

int main(){
    Tree *root = get_node(1);
    root->left = get_node(2);
    root->left->left = get_node(4);
    root->left->right = get_node(5);
    root->left->right->left = get_node(7);
    root->left->right->right = get_node(8);
    root->right = get_node(3);
    root->right->right = get_node(6);
    root->right->right->left = get_node(9);
    
    printTree(root);
    cout<<endl;
    
    convertToSumTree(root);
    printTree(root);
    
    return 0;
}
