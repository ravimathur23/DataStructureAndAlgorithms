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

void printStack(stack<int> *q){
    while(!q->empty()){
        cout<<q->top()<<" ";
        q->pop();
    }
}

void printAncestorsUtil(Tree* node, int num, stack<int> q){
    if(node == NULL)
        return;
    
    if(num == node->get_data())
        printStack(&q);
    
    q.push(node->get_data());
    printAncestorsUtil(node->left, num, q);
    printAncestorsUtil(node->right, num, q);
}

void printAncestors(Tree* node, int num){
    stack<int> q;
    printAncestorsUtil(node, num, q);
}

int main() {
    // your code goes here
    Tree *root = new Tree(20);
    Tree *left = new Tree(9);
    Tree *right = new Tree(21);
    root->left = left;
    root->right = right;
    
    Tree *left_1 = new Tree(8);
    Tree *right_1 = new Tree(10);
    root->left->left =left_1;
    root->left->right = right_1;
    left_1->left = new Tree(7);
    
    printAncestors(root, 7);
    
    return 0;
}
