#include <iostream>
#include <limits>
#include <queue>
#include <map>
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

void printBetweenLevels(Tree* node, int low, int high){
    queue<Tree*> q;
    q.push(node);
    int level = 1;
    while(1){
        unsigned long sz = q.size();
        if(sz == 0)
            break;
        while(sz){
            Tree* tmp = q.front();
            if(level>=low && high>=level){
                cout<<tmp->getData()<<" ";
            }
            q.pop();
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
            sz--;
        }
        level++;cout<<endl;
    }
}

int main(){
    Tree *root = get_node(1);
    root->left = get_node(2);
    root->right = get_node(3);
    root->left->right = get_node(4);
    root->left->right->right = get_node(5);
    root->left->right->right->right = get_node(6);
    
    printBetweenLevels(root, 2,4);
    return 0;
}
