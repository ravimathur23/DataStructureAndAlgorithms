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

void printBoundaryLeft(Tree* node){
    if(node){
        
        if(node->left){
            cout<<node->getData()<<" ";
            printBoundaryLeft(node->left);
        }
        else if(node->right){
            cout<<node->getData()<<" ";
            printBoundaryLeft(node->right);
        }
        else{
        }
    }
}
void printBoundaryRight(Tree* node){
    if(node){
        if(node->right){
            printBoundaryRight(node->right);
            cout<<node->getData()<<" ";
        }
        else if(node->left){
            printBoundaryRight(node->left);
            cout<<node->getData()<<" ";
        }
        else{
        }
    }
}
void printLeaf(Tree* node){
    if(node == NULL)
        return;
    
    if(node->left == NULL && node->right == NULL)
        cout<<node->getData()<<" ";
    printLeaf(node->left);
    printLeaf(node->right);
}
void printBoundary(Tree* node){
    if(node != NULL){
        cout<<node->getData()<<" ";
        printBoundaryLeft(node->left);
        printLeaf(node->left);
        printLeaf(node->right);
        printBoundaryRight(node->right);
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
    printBoundary(root);
    
    return 0;
}
