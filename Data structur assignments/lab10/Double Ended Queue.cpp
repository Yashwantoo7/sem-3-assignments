#include<iostream>
using namespace std;
//DEQue using singly LL
template<typename T>
class DEQue{
    T null = T();//default value or null value to return in case no data found
    struct Node {
        T data;
        Node *next;
    }*front=NULL, *rear=NULL;
public:
    void insertFront(T data){
        Node *ptr = new Node{data, NULL};
        if( isEmpty() ){
            front = rear = ptr;
        } else {
            ptr->next = front;
            front = ptr;
        }
    }
    void insertLast(T data){
        Node *ptr = new Node{data, NULL};
        if( isEmpty() ){
            front = rear = ptr;
        } else {
            rear->next = ptr;
            rear = ptr;
        }
    }
    T deleteFront(){
        if( !isEmpty() ){
            T data = front->data;
            Node *ptr = front;
            front = front->next;
            delete ptr;//delete occupied space
            return data;
        }
        cout<<"Queue is Empty"<<endl;
        return null;
    }
    T deleteLast(){//have to traverse to reach node before REAR
        if( !isEmpty() ){
            T data = rear->data;
            Node *ptr = front;
            if(front == rear){
                //if only one element was there
                delete rear;
                front = rear = NULL;
                return data;
            }
            while(ptr->next != rear)
                ptr=ptr->next;
            rear = ptr;
            ptr = ptr->next;
            rear->next = NULL;
            delete ptr;
            return data;
        }
        cout<<"Queue is Empty"<<endl;
        return null;
    }
    T getFront(){
        if( isEmpty() ){
            cout<<"QUeue is Empty"<<endl;
            return null;
        }
        return front->data;
    }
    T getRear(){
        if( isEmpty() ){
            cout<<"Queue is Empty"<<endl;
            return null;
        }
        return rear->data;
    }
    void display(){
        if( !isEmpty() ){
            Node *ptr = front;
            cout<<"FRONT -- "<<ptr->data;
            ptr = ptr->next;
            while( ptr ){
                cout<<" -- "<<ptr->data;
                ptr = ptr->next;
            }
            cout<<" -- REAR\n";
        } else cout<<"NULL\n";
    }
    bool isEmpty(){
        return front==NULL;
    }
};

int main(){
    DEQue<int> Q;
    Q.insertLast(10);
    Q.insertLast(20);
    Q.insertLast(30);
    Q.insertLast(40);
    Q.display();
    cout<<"\nGetting Front: "<<Q.getFront()<<endl;
    cout<<"Deleting Rear: "<<Q.deleteLast()<<endl;
    cout<<"\nThe Queue: ";
    Q.display();
}