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

LL* mergeSortedLL(LL* head1, LL* head2){
    LL* result = NULL;
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    
    if(head1->getD() < head2->getD()){
        result = head1;
        result->next = mergeSortedLL(head1->next, head2);
    }else{
        result = head2;
        result->next = mergeSortedLL(head1, head2->next);
    }
    
    
    
    return result;
}

int main(){
    LL *head1 = new LL(5);
    head1->next = new LL(7);
    head1->next->next = new LL(10);
    head1->next->next->next = new LL(11);
    head1->next->next->next->next  = new LL(15);
    head1->next->next->next->next->next  = new LL(18);
    head1->next->next->next->next->next->next = new LL(20);
    
    LL *head2 = new LL(2);
    head2->next = new LL(4);
    head2->next->next = new LL(6);
    head2->next->next->next = new LL(10);
    head2->next->next->next->next = new LL(15);
    head2->next->next->next->next->next = new LL(16);
    head2->next->next->next->next->next->next = new LL(25);
    
    LL* result = mergeSortedLL(head1, head2);
    printLL(result);

    return 0;
}

