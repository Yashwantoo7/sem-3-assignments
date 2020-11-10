#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node * next;

    Node(int d){
        data=d;
        next=NULL;
    }
};

Node* merge(Node* l1,Node* l2)
{
if(!l1)
return l2;
if(!l2)
return l1;

if(l1->data<l2->data)
{
l1->next=merge(l1->next,l2);
return l1;
}
else
{
l2->next=merge(l1,l2->next);
return l2;
}
}
Node* mergeSort(Node* head) {
// your code here
if(head==NULL || head->next==NULL)
return head;

Node* slow=head;
Node* fast=head->next;

while(fast && fast->next)
{
slow=slow->next;
fast=fast->next->next;
}

Node* newHead=slow->next;
slow->next=NULL;

return merge(mergeSort(head),mergeSort(newHead));

}
int main()
{
    Node* head=new Node(5);
    Node * node=new Node(4);
    Node * t=head;
    t->next=node;
    t=node;
    node=new Node(3);
    t->next=node;
    t=node;
    node=new Node(2);
    t->next=node;
    t=node;
    node=new Node(1);
    t->next=node;
    t=node;


    Node *ptr;
    ptr=mergeSort(head);
    while (ptr){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }

    return 0;
}
