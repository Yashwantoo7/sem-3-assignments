#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node*left=NULL,*right=NULL;
    Node(int d){data = d;}
};

Node* insert(Node* n, int data){
    if(!n){
        n = new Node(data);
        return n;
    }
    if(data < n->data)
        n->left = insert(n->left, data);
    else if(data > n->data)
        n->right = insert(n->right, data);
    return n;
}

int height(Node* curr){
    if(!curr) return -1;
    return max(height(curr->left), height(curr->right))+1;
}

Node* prevInorder(Node *n){
    while(n && n->right)n=n->right;
    return n;
}

Node* nextInorder(Node *n){
    while(n && n->left)n=n->left;
    return n;
}

Node* del(Node* curr, int data){
    if(!curr)return NULL;
    if(!(curr->left || curr->right)){
        delete curr;
        return NULL;
    }
    if(data < curr->data)
        curr->left = del(curr->left, data);
    else if(data > curr->data)
        curr->right = del(curr->right, data);
    else{
        Node * temp;
        if(height(curr->left) < height(curr->right) ){
            temp = nextInorder(curr->right);
            curr->data = temp->data;
            curr->right = del(curr->right, temp->data);
        } else {
            temp = prevInorder(curr->left);
            curr->data = temp->data;
            curr->left = del(curr->left, temp->data);
        }
    }
    return curr;
}

void inorder(Node *curr){
    if(curr){
        inorder(curr->left);
        cout<<curr->data<<" ";
        inorder(curr->right);
    }
}

int main(){
    /*
             25
           /   \
         10     35
          \    /  \
          15  30  40
         /      \
        12      32
    */
    Node* root = new Node(25);
    insert(root,10);
    insert(root,15);
    insert(root,35);
    insert(root,30);
    insert(root,12);
    insert(root,40);
    insert(root,32);
    cout<<"Inorder: ";
    inorder(root);
    
    cout<<"\n\nDeleting 25 from the binary tree\n";
    root = del(root,25);
    /*
             15
           /   \
         10     35
          \    /  \
          12  30  40
                \
                32
    */
    cout<<"\nThe tree now inorder is: ";
    inorder(root);
    
    cout<<"\n\nNow Deleting 35 from the binary tree\n";
    root = del(root,35);
    /*
             15
           /   \
         10     32
          \    /  \
          12  30  40
    */
    cout<<"\nThe tree now inorder is: ";
    inorder(root);
}