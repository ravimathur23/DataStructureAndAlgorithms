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

void printDistFromLeafUtil(Tree* node, queue<Tree*> q, int k){
    if(node == NULL)
        return;
    
    q.push(node);
    printDistFromLeafUtil(node->left, q, k);
    printDistFromLeafUtil(node->right, q, k);
    if(node->left == NULL && node->right == NULL)
    {
        int sz = q.size();
        sz -= k;
        while(sz)
        {
            
            Tree* tmp = q.front();
            cout<<tmp->getData()<<" ";
            q.pop();
            sz--;
        }
        cout<<endl;
    }
}
void printDistFromLeaf(Tree* node, int k){
    queue<Tree*> q;
    printDistFromLeafUtil(node, q, k);
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

    printDistFromLeaf(root, 1);
    return 0;
}
