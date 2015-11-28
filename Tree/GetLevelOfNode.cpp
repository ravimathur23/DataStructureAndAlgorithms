#include <iostream>
using namespace std;

class Tree{
    int data;
public:
    Tree(int d):data(d){left= NULL; right=NULL;};
    Tree * left; Tree * right;
    int get_data(){return data;}
};
void printNodeAtDistance(Tree *node, int num, int level=1){
    if(node == NULL)
        return;
    
    if(node->get_data() == num){
        cout<<level<<endl;
    }
    
    level++;
    printNodeAtDistance(node->left, num, level);
    printNodeAtDistance(node->right, num, level);
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
    
    printNodeAtDistance(root, 21);
    
    return 0;
}
