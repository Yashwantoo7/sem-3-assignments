#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node * right;

    Node()
    {
        data=0;
        left=NULL;
        right=NULL;
    }
};

class BT
{
public:
    Node * root ;
    BT()
    {
        root=NULL;
    }

    void insert(Node* node)
    {
        if(root==NULL)
            root=node;
        else
        {
            queue<Node*>q;
            q.push(root);
            while(!q.empty())
            {
                Node * temp=q.front();
                q.pop();
                if(temp->left==NULL)
                {
                    temp->left=node;
                    return;
                }
                else
                {
                    q.push(temp->left);
                }
                if(temp->right==NULL)
                {
                    temp->right=node;
                    return ;
                }
                else
                {
                    q.push(temp->right);
                }
            }
        }
    }
    void printTree(){
        queue<pair<Node *,pair<int,int > > > q;
        int tabs=5;
        bool level=0;
        q.push(make_pair(root,make_pair(level,tabs)));
        int currLevel=0;
        while(!q.empty()){
            pair<Node*,pair<int,int>> temp=q.front();
            pair<int,int> para=temp.second;
            q.pop();

            if(para.first!=currLevel)
                cout<<endl;
            currLevel=para.first;
            for(int i=0;i<para.second;i++){
                cout<<'\t';
            }
            cout<<temp.first->data;

            if(temp.first->left!=NULL){
                q.push(make_pair(temp.first->left,make_pair(para.first+1,para.second-1)));
                if (temp.first->right!=NULL){
                q.push(make_pair(temp.first->right,make_pair(para.first+1,2)));
                    }
            }
            else if(temp.first->right!=NULL){
                q.push(make_pair(temp.first->right,make_pair(para.first+1,para.second+1)));
            }

        }
    }
};
int main(){

    BT obj;
    Node * node=new  Node();
    node->data=5;
    obj.root=node;

    node=new Node;
    node->data=10;

    obj.root->left=node;
    Node * l=obj.root->left;

    node=new Node;
    node->data=20;

    obj.root->right=node;
    Node *r=obj.root->right;

    obj.printTree();

return 0;}
