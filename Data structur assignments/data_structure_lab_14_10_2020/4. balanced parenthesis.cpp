#include <iostream>
using namespace std;

struct Node{
    char data;
    struct Node *next = NULL;
};

class Stack{
    struct Node *header = NULL;
public:
    bool isEmpty(){
        return header==NULL;
    }
    void push(char data){
        struct Node *ptr = new Node;
        ptr->data = data;
        ptr->next = header;
        header = ptr;
    }
    
    char pop(){
        if(header){
            struct Node *ptr = header;
            header = header->next;
            return ptr->data;
            delete ptr;
        } else
            return '\0';
    }
    
    char peek(){
        if(header)
            return header->data;
        else
            return '\0';
    }
};

int open(char o){
    if( o=='(' ) return 1;
    if( o=='{' ) return 2;
    if( o=='[' ) return 3;
    return 0;
}

int close(char c){
    if( c==')' ) return 1;
    if( c=='}' ) return 2;
    if( c==']' ) return 3;
    return 0;
}

bool isBalanced(string ex){
    Stack S;
    char symbol, temp;
    for(int i=0; i< ex.length(); i++){
        symbol = ex[i];
        
        switch(symbol){
            case '(': case '{': case '[':
                S.push(symbol);
                break;
            case ')': case '}': case ']':
                if( S.isEmpty() ) return false;
                temp = S.pop();
                if( open(temp) != close(symbol) ) return false;
        }
    }
    if( S.isEmpty() ) return true;
    return false;
}

int main() {
    string ex;
    cout<<"Enter the expession: ";
    cin>>ex;
    bool b = isBalanced(ex);
    if( b ) cout<<"\nThe expression has BALANCED parenthesis";
    else cout<<"\nThe expression has UNBALANCED parenthesis";
}