#include <iostream>
#include<chrono>
using namespace std;
using namespace std::chrono; 

struct Node{
    int data;
    struct Node *next = NULL;
};

class Stack{
    struct Node *header = NULL;
public:
    int isEmpty(){
        return header==NULL;
    }
    void push(int data){
        struct Node *ptr = new Node;
        ptr->data = data;
        ptr->next = header;
        header = ptr;
    }
    int pop(){
        if(header){
            struct Node *ptr = header;
            header = header->next;
            return ptr->data;
            delete ptr;
        } else
            return 0;
    }
    int peek(){
        if(header)  return header->data;
        else        return 0;
    }
};

int reduction(int a[], int beg, int end){
    int left = beg, right = end, pivot = beg;
    
right_left:
    while(a[pivot] < a[right] && pivot!=right)
        right--;
    if( pivot == right) return pivot;
    if( a[pivot] > a[right]){
        int temp = a[pivot];
        a[pivot] = a[right];
        a[right] = temp;
        pivot = right;
        goto left_right;
    }
left_right:
    while(a[pivot] >= a[left] && pivot!=left)
        left++;
    if( pivot == left) return pivot;
    if( a[pivot] < a[left]){
        int temp = a[pivot];
        a[pivot] = a[left];
        a[left] = temp;
        pivot = left;
        goto right_left;
    }
    return 0;
}

int median(int a[], int beg, int end){
    //find median of first last and middle element and swap with first
    //this would effectively create two sublists with complexity of NlogN
    if( end - beg > 1 ){
        int mid = (beg + end)/2;
    
        int median = a[mid] > a[beg] ? a[mid] < a[end] ? mid : a[beg] > a[end] ? beg : end : a[mid] > a[end] ? mid : a[beg] < a[end] ? beg : end;
    
        if(median != beg){
            int temp = a[median];
            a[median] = a[beg];
            a[beg] = temp;
        }
    }
    return reduction(a,beg,end);
}

void quicksort(int a[], int n){
    Stack Lower, Upper;
    if(n > 1){
        Lower.push(0);
        Upper.push(n-1);
    }
    while( ! ( Lower.isEmpty() ) ){
        int beg = Lower.pop();
        int end = Upper.pop();
        int pivot = median(a,beg,end);
        
        if( beg < pivot-1 ){
            Lower.push(beg);
            Upper.push(pivot-1);
        }
        if( end > pivot+1 ){
            Lower.push(pivot+1);
            Upper.push(end);
        }
    }
}

int main() {
    int n;
    cout<<"\nEnter number of elements: ";
    cin>>n;
    cout<<"Enter elements: \n";
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    quicksort(a,n);
    cout<<"\nSorted elements: ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl<<endl;
}