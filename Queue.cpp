#include<iostream>
using namespace std;

class queue{
    public:
    int front,rear;
    int capacity,size;
    int *a;
    queue(){}
    queue(int capacity){
        front = rear = -1;
        size = 0;
        this->capacity = capacity;
        a = (int*)malloc(sizeof(capacity));
    }
};

bool isFull(queue* q){
    return (q->size >= q->capacity);
}

bool isEmpty(queue* q){
    return (q->size == 0);
}

int front(queue* q){
    return q->a[q->front];
}

void enqueue(queue* q,int n){
    if(isFull(q)){
        cout<<"Queue is overflowing !!"<<endl;
        return;
    }
    q->rear++;
    q->rear%=q->capacity;
    q->a[q->rear] = n;
    if(q->front == -1)
        q->front = q->rear;
    q->size++;
}

void dequeue(queue* q){
    if(isEmpty(q)){
        cout<<"Queue is underflowing !!"<<endl;
        return;
    }
    if(q->front == q->rear){
        q->front = q->rear = -1; 
        q->size = 0;
        return;
    }
    q->a[q->front] = -1;
    q->front++;
    q->front%=q->capacity;
    q->size--;

}

void display(queue* q){
        cout<<"The elements in queue are:";
        for(int i=0;i<q->capacity;i++)
            cout<<q->a[i]<<" ";

    cout<<endl;
}

int main(){
    int cap;
    cout<<"Enter the size of queue:";
    cin>>cap;
    queue* q = new queue(cap);
    for(int i=0;i<cap;i++){
        int n;
        cout<<"Enter the value:";
        cin>>n;
        enqueue(q,n);
    }
    // Just for fun some operations on queue!!
    display(q);
    cout<<front(q)<<endl;
    dequeue(q);
    cout<<front(q)<<endl;
    dequeue(q);
    cout<<front(q)<<endl;
    display(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    
    
    return 0;
}










