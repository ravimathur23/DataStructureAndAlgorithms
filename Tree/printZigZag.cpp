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

void printLevelOrderSpiral(Tree* node){
    stack<Tree*> ss1;
    stack<Tree*> ss2;
    ss1.push(node);
    
    while(!ss1.empty() || !ss2.empty()){

        while(!ss1.empty()){
            Tree* tmp = ss1.top();
            ss1.pop();
            cout<<tmp->get_data()<<" ";
            
            if(tmp->right)
                ss2.push(tmp->right);
            if(tmp->left)
                ss2.push(tmp->left);
        }
        
        cout<<endl;
        
        while(!ss2.empty()){
            Tree* tmp = ss2.top();
            ss2.pop();
            cout<<tmp->get_data()<<" ";
            
            if(tmp->left)
                ss1.push(tmp->left);
            if(tmp->right)
                ss1.push(tmp->right);
        }
        
        cout<<endl;
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
    
    printLevelOrderSpiral(root);
    
    return 0;
}
