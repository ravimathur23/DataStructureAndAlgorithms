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
int findMaxUtil(Tree* node, int& res){
    if(node== NULL)
        return 0;
    
    int l = findMaxUtil(node->left, res);
    int r = findMaxUtil(node->right, res);
    int single_max = max(max(l,r)+node->getData(), node->getData());
    int max_top = max(single_max, l+r+node->getData());
    res = max(res, max_top);
    return single_max;
}
int findMax(Tree* root){
    int res = INT_MIN;
    findMaxUtil(root, res);
    return res;
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
    cout<<findMax(root)<<endl;;
    
    return 0;
}
