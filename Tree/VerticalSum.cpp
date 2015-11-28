#include <iostream>
#include <map>
using namespace std;

class Tree{
    int data;
public:
    Tree(int d):data(d){left= NULL; right=NULL;rightAdj = NULL;}
    Tree * left; Tree * right; Tree* rightAdj;
    int get_data(){return data;}
    void set_data(int n){data = n;}
};

void print_inorder(Tree *node){
    if(node == NULL)
        return;
    
    print_inorder(node->left);
    cout<<node->get_data()<<" ";
    print_inorder(node->right);
}
void printVerticalSumUtil(Tree* node, int hd, map<int, int> &m){
    if(node == NULL)
        return;
    
    if(m.find(hd) == m.end())
        m[hd] = node->get_data();
    else
        m[hd] += node->get_data();
    printVerticalSumUtil(node->left, hd-1, m);
    printVerticalSumUtil(node->right, hd+1, m);
}
void printVerticalSum(Tree* node){
    map<int, int> m;
    printVerticalSumUtil(node, 0, m);
    
    for(map<int, int>::iterator ii=m.begin();ii!=m.end();ii++){
        cout<<ii->first<<" "<<ii->second<<endl;
    }
}

int main() {
 
    Tree* root = new Tree(10);
    root->left = new Tree(-2);
    root->right = new Tree(6);
    root->left->left = new Tree(8);
    root->left->right = new Tree(-4);
    root->right->left = new Tree(7);
    root->right->right = new Tree(5);
    
    printVerticalSum(root);

    return 0;
}
