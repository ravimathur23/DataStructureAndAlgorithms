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

bool printAncestor(Tree* node, int key){
    if(node == NULL)
        return false;
    
    if(node->getData() ==  key)
        return true;
    
    if(printAncestor((node->left), key) || printAncestor(node->right, key)){
        cout<<node->getData()<<" ";
        return true;
    }
    return false;
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
    
    printAncestor(root, 9);

    
    return 0;
}
