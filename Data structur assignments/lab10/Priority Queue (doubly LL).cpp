#include<iostream>
#include<climits>
using namespace std;

template<typename T>
class PriorityQueue {
    struct DNode{
        int p;//priority
        T data;
        DNode* prev, *next;
    }*header=NULL;
public:
    bool isEmpty(){
        return header ? false : true;
    }
    void insert(T data, int p){
        DNode *New = new DNode{p,data,NULL,NULL}, *ptr = header;
        if(header){
            if( New->p > header->p ){
                header->prev = New;
                New->next = header;
                header = New;
            } else {
                while( ptr->next && ptr->next->p >= New->p )
                    ptr=ptr->next;
                if(ptr->next){
                    New->next = ptr->next;
                    New->prev = ptr;
                    ptr->next = New;
                    New->next->prev = New;
                } else {
                    ptr->next = New;
                    New->prev = ptr;
                }
            }
        } else
            header = New;
    }
    T getHighestPriority(){
        return header ? header->data : T();
    }
    T deleteHighestPriority(){
        if( isEmpty() ){
            cout<<"Priority Queue Empty"<<endl;
            return T();
        }
        DNode *p = header;
        header = header->next;
        if(header != NULL)
            header->prev=NULL;
        T data = p->data;
        delete p;
        return data;
    }
    void display(){
        if(header){
            int pri = INT_MAX;
            DNode *p = header;
            while(p){
                if( p->p < pri){
                    pri = p->p;
                    cout<<"\nPriority "<<pri<<": ";
                    cout<<p->data;
                } else {
                    cout<<" -- "<<p->data;
                }
                p=p->next;
            }
            cout<<endl;
        } else 
            cout<<"Priority Queue Empty"<<endl;
    }
};
int main(){
    PriorityQueue<int> Q;
    Q.insert(4,6);
    Q.insert(6,4);
    Q.insert(5,6);
    Q.insert(2,6);
    Q.insert(3,10);
    Q.display();
    cout<<"\nDeleting Highest Priority: "<<Q.deleteHighestPriority()<<endl;
    cout<<"\nThe Priority Queue is now: \n";
    Q.display();
    cout<<"\nDeleting Highest Priority: "<<Q.deleteHighestPriority()<<endl;
    cout<<"\nEnter data and priority to insert: ";
    int x, pri;
    cin>>x>>pri;
    Q.insert(x,pri);
    cout<<"\nThe Priority Queue is now: \n";
    Q.display();
}