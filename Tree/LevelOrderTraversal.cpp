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
    
    if(node->random)
        cout<<node->random->getData()<<" ";
    else{
            cout<<"NULL  ";
    }
    
    return;
}

void printLevelOrder(Tree* node){
    queue<Tree*> *que = new queue<Tree*>;
    Tree* tmp = node;
    
    while(tmp){
        cout<<tmp->getData()<<" ";
        
        if(tmp->left){
            que->push(tmp->left);
        }
        if(tmp->right){
            que->push(tmp->right);
        }
        
        tmp = que->front();
        que->pop();
    }
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
    
    printLevelOrder(root);
    
    return 0;
}
