#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node *left=NULL, *right=NULL;
    Node(int d){data = d;}
};

bool isComplete(Node* root){
    if(!root)return true;
    queue<Node *> q;
    q.push(root);
    Node * temp;
    bool flag = false ;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->left){
            if(flag)return false;
            q.push(temp->left);
        } else flag = true;
        if(temp->right){
            if(flag)return false;
            q.push(temp->right);
        } else flag = true;
    }
    return true;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"The binary is "<< (isComplete(root) ? "":"NOT") <<"a complete binary tree.\n";
    cout<<"\nInserting new node \n";
    root->left->right->left = new Node(8);
    cout<<"\nThe binary NOW is "<< (isComplete(root) ? "":"NOT ") <<"a complete binary tree.";
}