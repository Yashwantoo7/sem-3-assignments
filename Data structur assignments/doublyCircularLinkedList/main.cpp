#include <iostream>

using namespace std;

class Node{
public:
    int data;
    int key;
    Node * next,*prev;
    Node(){
        data=0;
        key=0;
        next=NULL;
        prev=NULL;
        }

    Node (int k,int d){
        data=d;
        key=k;
        }
};

class CDL{
public:
    Node * head;
    CDL(){
    head=NULL;
    }
    CDL(Node *n){
        head=n;
    }

    //insert node;
    void appendNode(Node *n){
        Node* temp=head;
        if(temp==NULL){
            head=n;
            n->next=head;
            n->prev=NULL;
            return;
        }
        else{
            while(temp->next!=head){
                temp=temp->next;
            }
                temp->next=n;
                n->prev=temp;
                n->next=head;
                return;
        }
    }

    void display(){
        Node * temp=head;
        while(temp->next!=head){
            cout<<"("<<temp->key<<","<<temp->data<<")<===>";
            temp=temp->next;
        }
        cout<<"("<<temp->key<<","<<temp->data<<")<===>";
    }
};



int main()
{
    CDL cdl;
    Node *n=new Node(1,10);
    cdl.appendNode(n);

    n=new Node(2,20);
    cdl.appendNode(n);

    n=new Node(3,30);
    cdl.appendNode(n);

    n=new Node(4,40);
    cdl.appendNode(n);

    cdl.display();
    return 0;
}
