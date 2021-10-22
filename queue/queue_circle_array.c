//
//
//
#include <malloc.h>
#include <stdio.h>
#include <mem.h>

*ps;
char *items[];
int n=10,head=0,tail=0;

void enQueue( char data[] ){
    //队列满了
    if((tail + 1) % n == head) { printf("queue is full!!\n"); return;}
    items[tail] = data;
    tail++;
}

char *deQueue(char *items[]){
    //空队列
    if (head == tail) {printf("queue is empty !!\n");return NULL;}
    char *data = items[head];

    //可以一直循环
    head = (head + 1) % n;

    return data;
}

char *fmtstr(int n){
    char *buf;
    buf = (char *) malloc(20);
    sprintf(buf,"%d word",n);
    return buf;
}

main(){

    for (int i=0;i<11;i++){
        enQueue(fmtstr(i));
    }


    for(int i=0;i<11;i++){
        printf("%s\n",items[i]);
    }

    printf("\n");

    for(int i=0;i<8;i++){
        ps=deQueue(items);
        printf("%s\n",ps);
    }

}