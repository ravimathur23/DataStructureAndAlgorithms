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
void print_inorder(Tree *node){
    if(node == NULL)
        return;
    
    print_inorder(node->left);
    cout<<node->get_data()<<" ";
    print_inorder(node->right);
}

void ThreadedTreeTraversal(Tree* node){
    Tree* pre = NULL;
    Tree* current = node;
    while(current){
        if(current->left == NULL)
        {
            cout<<current->get_data()<<" ";
            current = current->right;
        }
        else{
            pre = current->left;
            while(pre->right != NULL && pre->right != current){
                pre = pre->right;
            }
            if(pre->right == NULL){
                pre->right = current;
                current = current->left;
            }
            else{
                pre->right = NULL;
                cout<<current->get_data()<<" ";
                current = current->right;
            }
        }
    }
}

int main() {
    // your code goes here
    Tree* root = new Tree(20);
    root->left = new Tree(10);
    root->right = new Tree(24);
    root->left->left = new Tree(8);
    root->left->right = new Tree(12);
    root->left->left->left = new Tree(7);
    root->left->left->right = new Tree(9);
    root->right->left = new Tree(21);
    root->right->right = new Tree(27);
    root->right->right->left = new Tree(25);
    
    cout<<"inorder : ";
    print_inorder(root);
    cout<<endl;
    ThreadedTreeTraversal(root);
    cout<<endl;
    print_inorder(root);
    return 0;
}
