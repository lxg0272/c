//
// Created by tdcengineer on 2021/9/9.
//

#include <malloc.h>
#include <stdio.h>


typedef struct node{
    int data;
    struct node *next;
} node ;

int head,tail=0;
node *hnode,*tnode;

//创建链式队列
node *initQueue(){
    //创建头节点
    node *queue = (node *) malloc(sizeof(node));
    //初始化头节点
    (*queue).next=NULL;
    return queue;
}

node *enQueue(node *rear,int data){

    //1.用节点包裹入队元素
    node *enElem = (node *) malloc(sizeof(node));
    enElem->data = data;
    enElem->next = NULL;
    //2.tail的next指针指向新节点
    (*rear).next = enElem;
    //3.tail指针指向新节点
    rear = enElem;
    return rear;

}

void *deQueue(node *top,node *rear){
    if(top->next==NULL){
        printf("empty queue!!\n");
//        return rear;
    }
    //1.头节点next指针指向下下个节点
    node *p=top->next;
    printf("%d\n",p->data);//数据出队
    top->next=p->next;
    //
    if(rear==p){
        rear=top;
    }
    free(p);
//    return rear;

}

main(){
    node *queue,*head,*tail;
    queue=head=tail=initQueue();//创建头节点
    //
    tail=enQueue(tail,1);
    tail=enQueue(tail,2);
    tail=enQueue(tail,3);
    tail=enQueue(tail,4);
    //
    deQueue(head,tail);
    deQueue(head,tail);
    deQueue(head,tail);
    deQueue(head,tail);
    deQueue(head,tail);

}
