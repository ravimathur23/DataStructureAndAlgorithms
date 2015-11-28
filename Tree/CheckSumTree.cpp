#include <iostream>
#include <stack>
using namespace std;

class Tree{
    int data;
public:
    Tree(int d):data(d){left= NULL; right=NULL;};
    Tree * left; Tree * right;
    int get_data(){return data;}
};

int sum(Tree* node){
    if(node == NULL)
        return 0;
    else
        return sum(node->left)+node->get_data()+sum(node->right);
}
bool isSumTree(Tree* node){
    if(node == NULL || (node->left == NULL && node->right == NULL))
        return true;
    
    int leftSum = sum(node->left);
    int rightSum = sum(node->right);
    
    if(leftSum+rightSum == node->get_data() && isSumTree(node->left) && isSumTree(node->right))
        return true;
    else
        return false;
    
}
int main() {
    // your code goes here
    Tree* root = new Tree(26);
    root->left = new Tree(10);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(6);
    root->right->left = new Tree(3);
    
    cout<<(isSumTree(root)==1?"true":"false")<<endl;
    
    return 0;
}
