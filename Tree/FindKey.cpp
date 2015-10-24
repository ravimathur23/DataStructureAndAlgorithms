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
bool findKey(Tree* node, int key) {
    if(node == NULL)
        return false;
    bool l = findKey(node->left, key);
    bool r = findKey(node->right, key);
    return (l || r || (node->getData() == key));
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
    cout<<findKey(root, -25)<<endl;
    return 0;
}
