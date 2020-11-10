#include <iostream>
#include <cmath>
using namespace std;

template<typename T>
class Tree{
public:
    T null = T(); //for null of the generic type of like default
    int h, max_size;
    T *a;
    Tree(int height){
        h = height;
        max_size = pow(2,height+1)-1;
        a = new T[max_size]{null};
    }
    void setRoot(T r){a[0]=r;}
    
    void insertLeft(T parent, T data){
        int i=-1;
        for(;i<max_size && a[++i]!=parent;);
        
        if(i==max_size)
            cout<<"Parent Node Not Found!\n";
        else if(2*i+1 >= max_size)
            cout<<"Could not insert child. OutOfBoundsException!!\n";
        else
            a[2*i+1] = data;
    }
    void insertRight(T parent, T data){
        int i=-1;
        for(;i<max_size && a[++i]!=parent;);
        
        if(i==max_size)
            cout<<"Parent Node Not Found!\n";
        else if(2*i+2 >= max_size)
            cout<<"Could not insert child. OutOfBoundsException!!\n";
        else
            a[2*i+2] = data;
    }
    int search(T data){
        int i=0;
        for(;i<max_size && a[i]!=data;i++);
        return i==max_size ? -1:i;
    }
    void del(T data){
        T last = null;
        int i=max_size-1;
        for(;i>=0;i--)
            if(a[i]!=null){
                last = a[i];
                a[i]=null;
                break;
            }
        if(last==null)
            cout<<"Binary Tree Empty. Nothing to delete!!\n";
        else{
            int index = search(data);
            if(index==-1)
                cout<<"Data to delete Does not exist!!\n";
            else a[search(data)] = last;
        }
    }
    void display(){
        for(int i=0;i<max_size;i++){
            if(a[i]!=null)
                cout<<a[i]<<" ";
            else cout<<"- ";
        }
        cout<<"\n";
    }
};

int main() {
    int h,root;
    cout<<"Enter height of binary tree to create: ";
    cin>>h;
    Tree<int> T(h);
    cout<<"Binary Tree created!\n\nEnter root element to continue: ";
    cin>>root;
    T.setRoot(root);
    int ch;
    while(true){
        cout<<"\n1.Insert\n2.Delete\n3.Display\n4.Exit\n";
        cout<<"Enter option: ";
        cin>>ch;
        if(ch==1){
            int parent,data;
            cout<<"Enter parent: ";
            cin>>parent;
            cout<<"Enter 1 to insert Left child and 2 to insert Right child: ";
            cin>>ch;
            cout<<"Enter child data: ";
            cin>>data;
            if(ch==1)
                T.insertLeft(parent,data);
            else
                T.insertRight(parent,data);
            
        } else if(ch==2){
            int data;
            cout<<"Enter data of node to delete: ";
            cin>>data;
            T.del(data);
        } else if(ch==3)
            T.display();
        else
            break;
    }
    
}