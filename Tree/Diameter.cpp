#include <iostream>
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

int maxDepth(Tree* node){
    if(node == NULL)
        return 0;
    
    int lDep = maxDepth(node->left);
    int rDep = maxDepth(node->right);
    
    return max(lDep, rDep)+1;
}

int diameter(Tree* node){

    if(node ==  NULL)
        return 0;
    
    int lh = maxDepth(node->left);
    int rh = maxDepth(node->right);
    
    int lDia = diameter(node->left);
    int rDia = diameter(node->right);
    
    return max(lh+rh+1, max(lDia,rDia));
        
}

int main() {
    // your code goes here
    Tree* root = new Tree(20);
    root->left = new Tree(10);
    root->left->left = new Tree(9);
    root->left->right = new Tree(15);
    root->left->right->left = new Tree(11);
    root->left->right->right = new Tree(17);
    
    print_inorder(root);cout<<endl;
    cout<<"Diameter::"<<diameter(root)<<endl;
    
    return 0;
}
