#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Tree{
    int data;
public:
    Tree(int d):data(d){left= NULL; right=NULL;};
    Tree * left; Tree * right;
    int get_data(){return data;}
};

void print_inorder(Tree *node){
    if(node == NULL)
        return;
    
    print_inorder(node->left);
    cout<<node->get_data()<<" ";
    print_inorder(node->right);
}

int checkSumChildProperty(Tree* node){
    if(node == NULL || (node->left == NULL && node->right == NULL))
        return true;
    else{
        int leftData, rightData;
        if(node->left)
            leftData = node->left->get_data();
        else
            leftData = 0;
        
        if(node->right)
            rightData = node->right->get_data();
        else
            rightData = 0;
        
        return ((node->get_data() == leftData+ rightData) && checkSumChildProperty(node->left) && checkSumChildProperty(node->right));
    }
}

int main() {
    // your code goes here
    Tree* root = new Tree(74);
    root->left = new Tree(28);
    root->right = new Tree(46);
    root->left->left = new Tree(16);
    root->left->right = new Tree(12);
    root->left->left->left = new Tree(7);
    root->left->left->right = new Tree(9);
    root->right->left = new Tree(21);
    root->right->right = new Tree(25);
    root->right->right->left = new Tree(25);
    
    cout<<((checkSumChildProperty(root))?"true\n":"false\n");
    
    return 0;
}
