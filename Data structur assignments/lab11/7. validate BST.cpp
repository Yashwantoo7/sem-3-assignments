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

void inorder(Node *curr){
    if(curr){
        inorder(curr->left);
        cout<<curr->data<<" ";
        inorder(curr->right);
    }
}

bool isBST(Node* curr){
    if(!curr)return true;
    if(curr->left)
        if(curr->data <= curr->left->data)return false;
    if(curr->right)
        if(curr->data >= curr->right->data)return false;
    return isBST(curr->left) && isBST(curr->right);
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
    
    cout<<"\n\nThe binary tree is"<<(isBST(root)?"":" NOT")<<" a binary search tree.\n";
    
    cout<<"\nInserting an element 50 at left most position.\nInorder Now is : ";
    root->left->left = new Node(50);
    inorder(root);
    /*
             25
           /   \
         10     35
        / \    /  \
      50  15  30  40
         /      \
        12      32
    */
    cout<<"\n\nThe binary tree now is"<<(isBST(root)?"":" NOT")<<" a binary search tree.\n";
    
}