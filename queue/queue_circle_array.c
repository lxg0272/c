//
//
//
#include <malloc.h>
#include <stdio.h>
#include <mem.h>

//*ps;
//char *items[];
//int n=10,head=0,tail=0;
//
//void enQueue( char data[] ){
//    //队列满了
//    if((tail + 1) % n == head) { printf("queue is full!!\n"); return;}
//    items[tail] = data;
//    tail++;
//}
//
//char *deQueue(char *items[]){
//    //空队列
//    if (head == tail) {printf("queue is empty !!\n");return NULL;}
//    char *data = items[head];
//
//    //可以一直循环
//    head = (head + 1) % n;
//
//    return data;
//}
//
//char *fmtstr(int n){
//    char *buf;
//    buf = (char *) malloc(20);
//    sprintf(buf,"%d word",n);
//    return buf;
//}
//
//main(){
//
//    for (int i=0;i<11;i++){
//        enQueue(fmtstr(i));
//    }
//
//
//    for(int i=0;i<11;i++){
//        printf("%s\n",items[i]);
//    }
//
//    printf("\n");
//
//    for(int i=0;i<8;i++){
//        ps=deQueue(items);
//        printf("%s\n",ps);
//    }
//
//}

#define maxsize 6

typedef struct Queue{
    int *base;//队列首地址
    int front,rear;
}*Queue;

Queue InitQueue(){
    Queue q;
    q->base=(int *)malloc(sizeof(int)*maxsize);
    q->front=0;
    q->rear=0;
    return q;
}

int QueueisFull(Queue q){
    return ((q->rear+1)%maxsize == q->front);
}

int QueueisEmpty(Queue q){
    return (q->rear == q->front);
}

void Enqueue(Queue q,int data){
    q->base[q->rear] = data;
    q->rear = (q->rear+1)%maxsize;
}

int Dequeue(Queue q){
    int r = q->base[q->front];
    q->front = (q->front+1)%maxsize;
    return r;
}