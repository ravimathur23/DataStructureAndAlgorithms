#include <iostream>
#include <limits>
#include <queue>
#include <map>
using namespace std;

class Tree{
    int data;
public:
    Tree(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
    int getData(){return data;}
    int hd;
    Tree *left, *right;
};

Tree* get_node(int d){
    Tree *node = new Tree(d);
    return node;
}

void printTree(Tree* node){
    if(node == NULL)
        return;
    
    cout<<node->getData()<<" ";
    printTree(node->left);
    printTree(node->right);
    return;
}

void printTopView(Tree* node){
    queue<Tree* > *q = new queue<Tree*>;
    q->push(node);
    node->hd = 0;
    map<int, int> m ;
    while(q->size()){
        Tree* tmp = q->front();
        q->pop();
        if(m.count(tmp->hd)){
        }else{
        m[tmp->hd] = tmp->getData();
        }
        if(tmp->left) {
            q->push(tmp->left);
            tmp->left->hd = tmp->hd-1;
        }
        if(tmp->right){
            q->push(tmp->right);
            tmp->right->hd = tmp->hd+1;
        }
    }
    
    for(map<int,int>::iterator ii=m.begin();ii!=m.end();ii++)
    {
        cout<<ii->first<<" "<<ii->second<<endl;
    }
}

int main(){
    Tree *root = get_node(1);
    root->left = get_node(2);
    root->right = get_node(3);
    root->left->right = get_node(4);
    root->left->right->right = get_node(5);
    root->left->right->right->right = get_node(6);
    
    printTopView(root);
    return 0;
}
