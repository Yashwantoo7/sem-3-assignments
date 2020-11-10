#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

class Node{
public:
    int data;
    Node *left=NULL, *right=NULL;
    Node(int d){data = d;}
};

int height(Node* curr){
    if(!curr)return -1;
    int left = height(curr->left);
    int right = height(curr->right);
    return max(left, right)+1;
}

int countInternal(Node* curr){
    if(!curr)return 0;
    int c = countInternal(curr->left)+countInternal(curr->right);
    return (curr->left || curr->right) ? c+1 : c;
}

int countExternal(Node* curr){
    if(!curr)return 0;
    int c = countExternal(curr->left)+countInternal(curr->right);
    return (curr->left || curr->right) ? c : c+1;
}

int main(){
    /*  The binary tree created is as follows
                1
               / \
              2   3
            /  \   \
           4   5    6
              /    / \
             7    8   9
                 / \
               10  11
    */
    int i = 1;
    Node* root = new Node(i++);
    root->left = new Node(i++);
    root->right = new Node(i++);
    root->left->left = new Node(i++);
    root->left->right = new Node(i++);
    root->right->right = new Node(i++);
    root->left->right->left = new Node(i++);
    root->right->right->left = new Node(i++);
    root->right->right->right = new Node(i++);
    root->right->right->left->left = new Node(i++);
    root->right->right->left->right = new Node(i++);
    
    cout<<"Height of binary tree is "<<height(root)<<"\n\n";
    cout<<"Number of Internal Nodes: "<<countInternal(root)<<"\n\n";
    cout<<"Number of External Nodes: "<<countExternal(root);
}