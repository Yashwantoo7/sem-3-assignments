//doing a little bit peculiar thing here
//the single pointers actually store a mtrix
//but accessing them in ROW MAJOR ORDER

#include<iostream>
using namespace std;

#define FRONT(r) p[r*2+0]//front of queue in r row
#define REAR(r) p[r*2+1] //rear of queue in r row
#define A(i,j) a[i*m+j]  //accessing element using RMO

template<typename T>
class PriorityQueue {
    int n,m, *p;//for front and rear pointers of queue
    T *a; //pointer for accessing the matrix
public:
    PriorityQueue(int N, int M){
        n=N;
        m=M;
        p = new int[n*2]; //2 columns n row
        a = new int[n*m]; //n by m matrix
        for(int i=0;i<n;i++)
            for(int j=0;j<2;j++)
                p[i*2+j] = -1; 
    }
    void insert(T data, int pri){
        int r = n-pri;
        if( FRONT(r) == -1 ){
            FRONT(r) = REAR(r) = 0;
            A(r,0) = data;
        } else if( (REAR(r)+1)%m == FRONT(r) )
            cout<<"Priority Level Full"<<endl;
        else {
            REAR(r) = (REAR(r)+1)%m;
            A(r,REAR(r)) = data;
        }
    }
    T getHighestPriority(){
        T data = T();
        int pri = 0;
        for(; pri<n; pri++){
            if( FRONT(pri) != -1 )
                break;
        }
        if(pri == n){
            cout<<"Priority Queue Empty"<<endl;
            return data;
        }
        return A(pri, FRONT(pri));
    }
    T deleteHighestPriority(){
        T data = T();
        int pri = 0;
        for(; pri<n; pri++){
            if( FRONT(pri) != -1 )
                break;
        }
        if(pri == n){
            cout<<"Priority Queue Empty"<<endl;
            return data;
        }
        data = A(pri, FRONT(pri));
        FRONT(pri) = (FRONT(pri)+1)%m;
        
        if( FRONT(pri) == (REAR(pri)+1)%m )
            FRONT(pri) = REAR(pri) = -1;
        return data;
    }
    bool isEmpty(){
        int pri = 0;
        for(; pri<n; pri++)
            if(FRONT(pri) != -1)
                break;
        return pri == n ? true : false;
    }
    bool isEmpty(int pri){
        return FRONT(n-pri) == -1 ? true : false;
    }
    void display(){
        for(int pri = 0; pri<n; pri++){
            if( FRONT(pri) != -1 ){
                cout<<"Priority "<<n-pri<<": ";
                int i = FRONT(pri);
                cout<<A(pri, i);
                i = (i+1)%m;
                while( i != (REAR(pri)+1)%m ){
                    cout<<" -- "<<A(pri, i);
                    i = (i+1)%m;
                }
                cout<<endl;
            }
        }
    }
};

int main(){
    PriorityQueue<int> Q(10,5);
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