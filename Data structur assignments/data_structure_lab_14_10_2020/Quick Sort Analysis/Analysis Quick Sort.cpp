#include<iostream>
#include<algorithm>
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
    int isEmpty();
    void push(int data);
    int pop();
    int peek();
    
};

int reduction(int[],int,int);
int randomizer(int[],int,int);
int median(int[],int,int);
void simple_quicksort(int[],int);
void random_quicksort(int[],int);
void median_quicksort(int[],int);

int main() {
    int avg,times=100;
    int arr[1000];
    cout<<"**************  Analysis of QUICK SORT using STACK ****************"<<endl<<endl;
    
    cout<<"1. Simple Quick Sort : \n"<<endl;
    
    cout<<"\tA. Already sorted Array :"<<endl;
    for(int i=0;i<1000;i++)
        arr[i]=i+1;
    cout<<"\t\tsize(n)\t time taken (in microseconds)"<<endl;
    for(int i=100; i<=1000;i+=100){
        avg = 0;
        for(int j=0;j<times;j++){
            auto start = high_resolution_clock::now(); 
            simple_quicksort(arr,i);
            auto stop = high_resolution_clock::now(); 
        
            auto duration = duration_cast<microseconds>(stop - start);
            
            avg += duration.count();
        }
        cout<<"\t\t "<<i<<"\t\t\t "<< avg/times<<endl; 
    }
    
    cout<<"\tB. Reverse sorted Array :"<<endl;
    cout<<"\t\tsize(n)\t time taken (in microseconds)"<<endl;
    for(int i=100; i<=1000;i+=100){
        avg = 0;
        for(int j=0;j<times;j++){
            for(int k=0;k<i;k++)
                arr[k]=1000-k;
            auto start = high_resolution_clock::now(); 
            simple_quicksort(arr,i);
            auto stop = high_resolution_clock::now(); 
        
            auto duration = duration_cast<microseconds>(stop - start);
            
            avg += duration.count();
            
        }
        cout<<"\t\t "<<i<<"\t\t\t "<< avg/times<<endl; 
        
    }
    
    
    cout<<"\tC. Unsorted Array :"<<endl;
    cout<<"\t\tsize(n)\t time taken (in microseconds)"<<endl;
    for(int i=100; i<=1000;i+=100){
        avg = 0;
        for(int j=0;j<times;j++){
            for(int k=0; k<i; k++) arr[k] = rand();
            auto start = high_resolution_clock::now(); 
            simple_quicksort(arr,i);
            auto stop = high_resolution_clock::now(); 
        
            auto duration = duration_cast<microseconds>(stop - start);
            
            avg += duration.count();
            
        }
        cout<<"\t\t "<<i<<"\t\t\t "<< avg/times<<endl; 
        
    }
    
    
    cout<<"\n-----------------------------------------------------"<<endl;
    cout<<"2. Random Quick Sort : \n"<<endl;
    cout<<"\tA. Already sorted Array :"<<endl;
    for(int i=0;i<1000;i++){
        arr[i]=i+1;
    }
    cout<<"\t\tsize(n)\t time taken (in microseconds)"<<endl;
    for(int i=100; i<=1000;i+=100){
        avg = 0;
        for(int j=0;j<times;j++){
            auto start = high_resolution_clock::now(); 
            random_quicksort(arr,i);
            auto stop = high_resolution_clock::now(); 
        
            auto duration = duration_cast<microseconds>(stop - start);
            
            avg += duration.count();
            
        }
        cout<<"\t\t "<<i<<"\t\t\t "<< avg/times<<endl; 
        
    }
    cout<<"\tB. Reverse sorted Array :"<<endl;
    cout<<"\t\tsize(n)\t time taken (in microseconds)"<<endl;
    for(int i=100; i<=1000;i+=100){
        
        avg = 0;
        for(int j=0;j<times;j++){
            for(int k=0;k<i;k++)
                arr[k]=1000-k;
            auto start = high_resolution_clock::now(); 
            random_quicksort(arr,i);
            auto stop = high_resolution_clock::now(); 
        
            auto duration = duration_cast<microseconds>(stop - start);
            
            avg += duration.count();
            
        }
        cout<<"\t\t "<<i<<"\t\t\t "<< avg/times<<endl; 
        
    }
    
    cout<<"\tC. Unsorted Array :"<<endl;
    cout<<"\t\tsize(n)\t time taken (in microseconds)"<<endl;
    for(int i=100; i<=1000;i+=100){
        avg = 0;
        for(int j=0;j<times;j++){
            for(int k=0; k<i; k++) arr[k] = rand();
            auto start = high_resolution_clock::now(); 
            random_quicksort(arr,i);
            auto stop = high_resolution_clock::now(); 
        
            auto duration = duration_cast<microseconds>(stop - start);
            
            avg += duration.count();
            
        }
        cout<<"\t\t "<<i<<"\t\t\t "<< avg/times<<endl; 
        
    }
    
    cout<<"\n-----------------------------------------------------"<<endl;
    cout<<"3. Median Quick Sort : \n"<<endl;
    cout<<"\tA. Already sorted Array :"<<endl;
    for(int i=0;i<1000;i++){
        arr[i]=i+1;
    }
    cout<<"\t\tsize(n)\t time taken (in microseconds)"<<endl;
    for(int i=100; i<=1000;i+=100){
        avg = 0;
        for(int j=0;j<times;j++){
            auto start = high_resolution_clock::now(); 
            median_quicksort(arr,i);
            auto stop = high_resolution_clock::now(); 
        
            auto duration = duration_cast<microseconds>(stop - start);
            
            avg += duration.count();
            
        }
        cout<<"\t\t "<<i<<"\t\t\t "<< avg/times<<endl; 
        
    }
    cout<<"\tB. Reverse sorted Array :"<<endl;
    cout<<"\t\tsize(n)\t time taken (in microseconds)"<<endl;
    for(int i=100; i<=1000;i+=100){
        
        avg = 0;
        for(int j=0;j<times;j++){
            for(int k=0;k<i;k++)
                arr[k]=1000-k;
            auto start = high_resolution_clock::now(); 
            median_quicksort(arr,i);
            auto stop = high_resolution_clock::now(); 
        
            auto duration = duration_cast<microseconds>(stop - start);
            
            avg += duration.count();
            
        }
        cout<<"\t\t "<<i<<"\t\t\t "<< avg/times<<endl; 
        
    }
    
    cout<<"\tC. Unsorted Array :"<<endl;
    cout<<"\t\tsize(n)\t time taken (in microseconds)"<<endl;
    for(int i=100; i<=1000;i+=100){
        
        avg = 0;
        for(int j=0;j<times;j++){
            for(int k=0; k<i; k++) arr[k] = rand();
            auto start = high_resolution_clock::now(); 
            median_quicksort(arr,i);
            auto stop = high_resolution_clock::now(); 
        
            auto duration = duration_cast<microseconds>(stop - start);
            
            avg += duration.count();
            
        }
        cout<<"\t\t "<<i<<"\t\t\t "<< avg/times<<endl; 
        
    }
}

int Stack::isEmpty(){
    return header==NULL;
}
void Stack::push(int data){
    struct Node *ptr = new Node;
    ptr->data = data;
    ptr->next = header;
    header = ptr;
}
int Stack::pop(){
    if(header){
        struct Node *ptr = header;
        header = header->next;
        return ptr->data;
        delete ptr;
    } else
        return 0;
}
int Stack::peek(){
    if(header)  return header->data;
    else        return 0;
}

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
int randomizer(int a[], int beg, int end){
    //randomly choosing element and swapping first in partition
    int r = beg + rand() % ( end - beg );
    int temp = a[r];
    a[r] = a[beg];
    a[beg] = temp;
    return reduction(a,beg,end);
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

void simple_quicksort(int a[], int n){
    Stack Lower, Upper;
    if(n > 1){
        Lower.push(0);
        Upper.push(n-1);
    }
    while( ! ( Lower.isEmpty() ) ){
        int beg = Lower.pop();
        int end = Upper.pop();
        int pivot = reduction(a,beg,end);
        
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
void random_quicksort(int a[], int n){
    Stack Lower, Upper;
    if(n > 1){
        Lower.push(0);
        Upper.push(n-1);
    }
    while( ! ( Lower.isEmpty() ) ){
        int beg = Lower.pop();
        int end = Upper.pop();
        int pivot = randomizer(a,beg,end);
        
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
void median_quicksort(int a[], int n){
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