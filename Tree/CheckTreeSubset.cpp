#include <iostream>
using namespace std;

class Tree{
    int data;
public:
    Tree(int d):data(d){left= NULL; right=NULL;};
    Tree * left; Tree * right;
    int get_data(){return data;}
};
bool checkTreeIdentical(Tree* root1, Tree* root2){
    
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    
    if(root1 !=NULL && root2 != NULL)
        return ( (root1->get_data() == root2->get_data())
                && checkTreeIdentical(root1->left, root2->left)
                && checkTreeIdentical(root1->right, root2->right) );
    
    return false;
}



bool checkTreeSubSet(Tree* root_a, Tree* root_b){
    if(root_b== NULL)
        return true;
    
    if(root_a == NULL)
        return false;
    
    if(checkTreeIdentical(root_a, root_b))
        return true;
    
    return checkTreeSubSet(root_a->left, root_b) || checkTreeSubSet(root_a->right, root_b);
}

int main() {
    // your code goes here
    Tree *root_a = new Tree(30);
    Tree *root = new Tree(20);
    root_a->left = root;
    Tree *left = new Tree(9);
    Tree *right = new Tree(21);
    root->left = left;
    root->right = right;
    
    Tree *left_1 = new Tree(8);
    Tree *right_1 = new Tree(10);
    root->left->left =left_1;
    root->left->right = right_1;
    
    Tree *root1 = new Tree(20);
    {
        Tree *left = new Tree(9);
        Tree *right = new Tree(21);
        root1->left = left;
        root1->right = right;
        
        Tree *left_1 = new Tree(8);
        Tree *right_1 = new Tree(10);
        root1->left->left =left_1;
        root1->left->right = right_1;
    }

    cout<<"Tree Identical : "<<checkTreeSubSet(root_a, root1)<<endl;
    
    return 0;
}
