#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left=NULL, *right=NULL;
    Node(int d){data = d;}
} *root = NULL;

void inorder(Node *n){
    if(n){
        inorder(n->left);
        cout<<n->data<<" ";
        inorder(n->right);
    }
}

void preorder(Node *n){
    if(n){
        cout<<n->data<<" ";
        preorder(n->left);
        preorder(n->right);
    }
}

void postorder(Node *n){
    if(n){
        postorder(n->left);
        postorder(n->right);
        cout<<n->data<<" ";
    }
}

int main(){
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"\nPreorder traversal of binary tree is \n"; 
    preorder(root); 
  
    cout<<"\nInorder traversal of binary tree is \n"; 
    inorder(root);  
  
    cout<<"\nPostorder traversal of binary tree is \n"; 
    postorder(root); 
}