#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *q;
};

void create(struct Queue *q, int size){
    q->size=size;
    q->front=q->rear=-1;
    //create dynamic memory for array of queue
    q->q = (int *)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q, int data){
    //check if empty queue
    if( q->rear == -1){ 
        q->rear=q->front=0; 
        q->q[0] = data; 
    } 
    else if( (q->rear+1)%q->size == q->front )//checking if queue full, (if rear is just behind front => full) 
        printf("Queue is Full"); 
    else{//not full 
        q->rear = (q->rear+1) % q->size;//move rear to next (circularly) 
        q->q[q->rear] = data;//add the element
    }
}

int dequeue(struct Queue *q){
    int data = -1;//if queue empty -1
    if(q->front == -1)//if queue empty
        printf("Queue is Empty");
    else {
        data = q->q[q->front];//get front's data
        q->front = (q->front+1)%q->size;// and move front to next (circularly)
        //now checking if queue became empty.
        //if after deletion front moved one next to rear => front was equal to rear => had single element
        if(q->front == (q->rear+1)%q->size)//now if front is next to rear => empty.
            q->front=q->rear=-1;//for empty resetting position
    }
    return data;
}

int isEmpty(struct Queue *q){
    if(q->rear == -1)
        return 1;
    return 0;
}

void display(struct Queue *q){
    int curr = q->front;
    if( curr != -1){//if not empty
        printf("FRONT -- %d",q->q[curr]);//print first element
        curr = (curr+1)%q->size;// circularly go to next element
        //while curr does not go beyond rear
        while( curr != (q->rear+1)%q->size ){
            printf(" -- %d",q->q[curr]);
            curr = (curr+1)%q->size;
        }
        printf(" -- REAR\n");
    }else
        printf("NULL\n");
}

int main() {
    struct Queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    printf("Queue: ");
    display(&q);
    printf("\nDequeue: %d\nThe queue now is: ",dequeue(&q));
    display(&q);
    printf("Dequeue: %d\nThe queue now is: ",dequeue(&q));
    display(&q);
    printf("Enqueue: 40\nThe queue now is ");
    enqueue(&q,40);
    display(&q);
    printf("Enqueue: 50\nThe queue now is ");
    enqueue(&q,50);
    display(&q);
    printf("Enqueue: 10\nThe queue now is ");
    enqueue(&q,10);
    display(&q);
    printf("Enqueue: 20\nThe queue now is ");
    enqueue(&q,20);
    display(&q);
    printf("\nEnqueue: 30: ");
    enqueue(&q,30);
    printf("\n\nThe queue is now ");
    display(&q);
    printf("Dequeue: %d\nThe queue now is: ",dequeue(&q));
    display(&q);
    printf("Dequeue: %d\nThe queue now is: ",dequeue(&q));
    display(&q);
    printf("Dequeue: %d\nThe queue now is: ",dequeue(&q));
    display(&q);
    printf("Dequeue: %d\nThe queue now is: ",dequeue(&q));
    display(&q);
    printf("Dequeue: %d\nThe queue now is: ",dequeue(&q));
    display(&q);
}