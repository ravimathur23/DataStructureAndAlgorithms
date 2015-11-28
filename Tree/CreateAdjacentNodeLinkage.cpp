#include <iostream>
#include <queue>
using namespace std;

class Tree{
    int data;
public:
    Tree(int d):data(d){left= NULL; right=NULL;rightAdj = NULL;}
    Tree * left; Tree * right; Tree* rightAdj;
    int get_data(){return data;}
};

void printRightAdjacent(Tree* node){
    Tree *level = node;
    while(level!= NULL){
        cout<<level->get_data()<<" ";
        Tree* col = level->rightAdj;
        while(col!= NULL){
            cout<<col->get_data()<<" ";
            col = col->rightAdj;
        }
        level = level->left;
        cout<<endl;
    }
}

void createRightAdjacentLinks(Tree* node){
    queue<Tree*> q;
    q.push(node);
    
    while(1){
        long sz = q.size();
        
        if(q.size() == 0){
            break;
        }

        while(sz!=0){
            Tree* tmp = q.front();
            q.pop();
            
            if(sz>1){
                tmp->rightAdj = q.front();
            }
            
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
            
            sz--;
        }
        
    }
}

int main() {
    // your code goes here
    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);
    root->left->left->left = new Tree(8);
    root->left->left->right = new Tree(9);
    root->right->right->left = new Tree(10);
    root->right->right->right = new Tree(11);
    
    createRightAdjacentLinks(root);
    printRightAdjacent(root);
    return 0;
}
