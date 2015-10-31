#include <iostream>
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
void reverseLL(LL** node){
    LL* tmp = *node;
    LL* prev = NULL;
    LL* next = NULL;
    while(1){
        if(tmp->next ==  NULL)
        {
            if(prev == NULL)
                return;
            else{
                tmp->next = prev;
                *node = tmp;
                return;
            }
        }
        next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
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
    
    printLL(head);cout<<endl;
    reverseLL(&head);
    printLL(head);cout<<endl;
    
    return 0;
}

