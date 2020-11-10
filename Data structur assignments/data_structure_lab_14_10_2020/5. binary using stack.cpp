#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next = NULL;
};

class Stack{
    struct Node *header = NULL;
public:
    bool isEmpty(){
        return header==NULL;
    }
    void push(int data){
        struct Node *ptr = new Node;
        ptr->data = data;
        ptr->next = header;
        header = ptr;
    }
    int pop(){
        if(header){
            struct Node *ptr = header;
            header = header->next;
            return ptr->data;
            delete ptr;
        } else
            return 0;
    }
    int peek(){
        if(header)  return header->data;
        else        return 0;
    }
};

string convert(int deci){
    Stack S;
    string s="";
    do{
        S.push(deci%2);
    }while(deci/=2);
    while(!S.isEmpty())
        s+=(char)(S.pop()+48);
    return s;
}

int main(){
    int deci;
    cout<<"Enter the decimal number: ";
    cin>>deci;
    cout<<"\nThe number in binary: "<<convert(deci);
}