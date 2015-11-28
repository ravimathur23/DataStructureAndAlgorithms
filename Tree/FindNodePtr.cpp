#include <iostream>
#include <queue>
using namespace std;

class Tree{
    int data;
public:
    Tree(int d):data(d){left= NULL; right=NULL;rightAdj = NULL;}
    Tree * left; Tree * right; Tree* rightAdj;
    int get_data(){return data;}
};

void returnNodePtrUtil(Tree* node, int num, Tree** resNode){
    if(node == NULL)
        return;
    
    if(node->get_data() ==  num){
        *resNode = node;
    }
    returnNodePtrUtil(node->left, num, resNode);
    returnNodePtrUtil(node->right, num, resNode);
}
Tree* returnNodePtr(Tree* node, int num){
    Tree* resNode  = NULL;
    returnNodePtrUtil(node,  num, &resNode );
    return resNode;
}

int main() {
    // your code goes here
    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);
    root->left->left->left = new Tree(8);
    root->left->left->right = new Tree(9);
    root->right->right->left = new Tree(10);
    root->right->right->right = new Tree(11);
    
    cout<<(returnNodePtr(root, 10))->get_data()<<endl;

    return 0;
}
