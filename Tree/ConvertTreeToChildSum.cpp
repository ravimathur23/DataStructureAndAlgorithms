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
    void set_data(int d){data = d;}
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

void convertSumChildPropTree(Tree* node){
    if(node == NULL)
        return;
    
    convertSumChildPropTree(node->left);
    convertSumChildPropTree(node->right);
    
    int leftData, rightData;
    if(node->left)
        leftData = node->left->get_data();
    else
        leftData = 0;
    
    if(node->right)
        rightData = node->right->get_data();
    else
        rightData = 0;
 
    if(node->left == NULL && node->right == NULL){
        
    }
    else if(node->get_data() != leftData+rightData){
        node->set_data(leftData + rightData);
    }
    else{
        
    }
}

int main() {
    // your code goes here
    Tree* root = new Tree(74);
    root->left = new Tree(28);
    root->right = new Tree(46);
    root->left->left = new Tree(13);
    root->left->right = new Tree(12);
    root->left->left->left = new Tree(7);
    root->left->left->right = new Tree(9);
    root->right->left = new Tree(21);
    root->right->right = new Tree(25);
    root->right->right->left = new Tree(24);
    
    cout<<((checkSumChildProperty(root))?"true\n":"false\n");
    convertSumChildPropTree(root);
    print_inorder(root);
    return 0;
}
