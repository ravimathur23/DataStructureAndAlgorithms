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
int maxDepth(Tree *node){
    if(node)
    {
        int left_depth = maxDepth(node->left);
        int right_depth = maxDepth(node->right);
        
        if(left_depth > right_depth)
            return left_depth+1;
        else
            return right_depth+1;
    }
    return 0;
}
int diameter(Tree *node){
    return maxDepth(node->left)+1+maxDepth(node->right);
    
}

void print_inorder(Tree *node){
    if(node == NULL)
        return;
    
    print_inorder(node->left);
    cout<<node->get_data()<<" ";
    print_inorder(node->right);
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
