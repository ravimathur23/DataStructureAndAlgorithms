#include <iostream>
#include <queue>
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

void printRootToLeafUtil(Tree* node, queue<Tree*> q){
    if(node == NULL)
        return;
    
    q.push(node);
    printRootToLeafUtil(node->left, q);
    printRootToLeafUtil(node->right, q);
    if(node->left == NULL && node->right == NULL)
    {
        while(!q.empty())
        {
            Tree* tmp = q.front();
            cout<<tmp->get_data()<<" ";
            q.pop();
        }
        cout<<endl;
    }
}
void printRootToLeaf(Tree* node){
    queue<Tree*> q;
    printRootToLeafUtil(node, q);
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
    
    printRootToLeaf(root);
    
    return 0;
}
