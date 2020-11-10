#include<iostream>
#include<queue>
using namespace std;

template<typename T = int>
class Tree{
public:
    T null = T();
    struct Node{
        T data;
        Node *left,*right;
        Node(T x){
            data = x;
            left=right=NULL;
        }
    } *root = NULL;
    
    void insert(T data){
        Node *temp, *New = new Node(data);
        if(!root){
            root = New;
            return;
        }
        queue<Node *> q;
        q.push(root);
        while(1){
            temp = q.front();
            q.pop();
            if(temp->left && temp->right){
                q.push(temp->left);
                q.push(temp->right);
            } else if(!temp->left){
                temp->left = New;
                return;
            } else {
                temp->right = New;
                return;
            }
        }
    }
    
    void del(T data){
        if(!root)return;
        if(root->left==NULL && root->right==NULL)
            if(root->data == data){
                delete root;
            } else {
                cout<<"Data does Not exist to delete!\n";
                return;
            }
        queue<Node *> q;
        q.push(root);
        
        Node *temp, *del = NULL;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            if(temp->data == data) {
                del = temp;
                while(!q.empty())q.pop();
            }
            if(temp->left)      q.push(temp->left);
            if(temp->right)     q.push(temp->right);
        }
        
        Node* &last = temp;
        // this last is storing the right most leaf under the node that is found
        if(del){//if to be deleted was found
            data = last->data;
            deleteLast(del,last);
            if(del != last) del->data = data;
        } else cout<<"Data to be deleted does not exit!!\n";
    }
    
    void deleteLast(Node *r1, Node *last){
        if(root == last){
            delete root;
            root=NULL;
            return;
        }
        Node *temp;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            temp = q.front();
            q.pop();
            
            if(temp->right){
                if(temp->right==last){
                    temp->right=NULL;
                    delete last;
                    return;
                }
                q.push(temp->right);
            }
            if(temp->left){
                if(temp->left==last){
                    temp->left=NULL;
                    delete last;
                    return;
                }
                q.push(temp->left);
            }
        }
    }
    void preorder(Node *curr){
        if(curr){
            cout<<curr->data<<" ";
            preorder(curr->left);
            preorder(curr->right);
        }
    }
};

int main(){
    Tree T;
    cout<<"Inserting in level order(left to right)\nTree in preorder: ";
    T.insert(1);
    T.insert(2);
    T.insert(3);
    T.insert(4);
    T.insert(5);
    T.insert(6);
    T.insert(7);
    T.preorder(T.root);
    cout<<"\n\nDeleting element 2\n";
    T.del(2);
    cout<<"\nThe tree Now is: ";
    T.preorder(T.root);
    cout<<"\n\nDeleting element 2\n";
    T.del(6);
    cout<<"\nThe tree Now is: ";
    T.preorder(T.root);
}