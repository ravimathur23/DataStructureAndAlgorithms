#include <iostream>
#include <limits>
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
int findMaxElem(Tree* node) {
    if(node == NULL)
        return 0;
    
    int l = findMaxElem(node->left);
    int r = findMaxElem(node->right);
    
    int maxElem = max(max(l,r), node->getData());
    return maxElem;
}
int main(){
    Tree *root = get_node(10);
    root->left = get_node(2);
    root->right = get_node(10);
    root->left->left = get_node(20);
    root->left->right = get_node(1);
    root->right->right = get_node(-25);
    root->right->right->left = get_node(3);
    root->right->right->right = get_node(4);
    cout<<findMaxElem(root)<<endl;
    return 0;
}
