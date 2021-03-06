#include <iostream>
#include <map>
using namespace std;
class LL{
    int d;
public:
    LL(int data):d(data){next = NULL;}
    LL* next;
    int getD(){return d;}
};
void printLL(LL* node){
    while(1){
        if(node == NULL)
            return;
        cout<<node->getD()<<" ";
        node = node->next;
    }
}
void removeLoop(LL* head, LL* loop){
    LL* prev = NULL;
    while(1){
        if(head == loop){
            prev->next = NULL;
            return;
        }
        head = head->next;
        prev = loop;
        loop = loop->next;
    }
}
void detectAndRemoveLoop(LL* node){
    LL* first = node;
    LL* second = node;
    int f,s;
    
    if(first->next == NULL){
        cout<<"No Loop detected"<<endl;
    }
    
    while(1){
        f=1; s=2;
        while (f) {
            if(first->next != NULL){
                first = first->next;
                f--;
            }
            else{
                cout<<"No Loop detected";
                return;
            }
        }
        while(s){
            if(second->next != NULL){
                second = second->next;
                s--;
            }
            else{
                cout<<"No Loop detected";
                return;
            }
        }
        if(first == second){
            cout<<"Loop detected";
            removeLoop(node, first);
            return;
        }
    }
}

int main(){
    LL *head = new LL(5);
    head->next = new LL(6);
    head->next->next = new LL(7);
    head->next->next->next = new LL(8);
    head->next->next->next->next  = new LL(9);
    head->next->next->next->next->next  = new LL(10);
    head->next->next->next->next->next->next = new LL(11);
    head->next->next->next->next->next->next->next = head->next->next->next;
    
    detectAndRemoveLoop(head);
    printLL(head);
    
    return 0;
}
