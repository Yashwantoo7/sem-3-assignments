#include <iostream>
#include "binaryTree.cpp"

using namespace std;

void x();

class BTA{
    int n;
    int *tree;
public:
    BTA(int s){
        n=s;
        int *ar= new int [n];
        for(int i=0;i<n;i++){
            ar[i]=0;
        }
        tree=ar;
    }

    void root(int key){
        if(*(tree)!=0)
            cout<<"Tree already had root"<<endl;
        else
            *(tree)=key;
    }

    void setLeft(int key,int parent){
        if(*tree==0)
            cout<<"first create root"<<endl;
        else{
            if(*(tree+parent)==0)
                cout<<"Can't set child at "<<
                (parent*2)+1<<" no parent found"<<endl;
            else{

                *(tree+(parent*2)+1)=key;
            }
        }
    }

        void setRight(int key,int parent){
        if(*tree==0)
            cout<<"first create root"<<endl;
        else{
            if(*(tree+parent)==0)
                cout<<"Can't set child at "<<
                (parent*2)+2<<" no parent found"<<endl;
            else{
                *(tree+(parent*2)+2)=key;
            }
        }
    }

    void printTree(){
        for(int i=0;i<n;i++){
            cout<<*(tree+i)<<" | ";
        }
        cout<<endl;
    }

};

int main()
{

    BTA Tree(10);
    Tree.root(5);
    Tree.printTree();
    Tree.setLeft(6,0);
    Tree.setRight(89,0);
    Tree.setLeft(76,1);
    Tree.setRight(23,2);
    Tree.printTree();
    return 0;
}
