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

void maxWidthUtil(Tree* node, int& maxWid){
    queue<Tree*> qq;
    qq.push(node);
    
    while(1){
        unsigned long sz = qq.size();
        if(sz>maxWid)
            maxWid = sz;
        if(sz == 0)
            break;
        while(sz){
            Tree* treeNode =  qq.front();
            qq.pop();
            cout<<treeNode->get_data()<< " ";
            if(treeNode->left)
                qq.push(treeNode->left);
            if(treeNode->right)
                qq.push(treeNode->right);
            sz--;
        }
        cout<<endl;
    }
}
int maxWidth(Tree* node){
    int maxWid = 0;
    maxWidthUtil(node, maxWid);
    return maxWid;
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
    
    cout<<maxWidth(root)<<endl;
    
    return 0;
}
