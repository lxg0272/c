#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>


int n=0,head=0,tail=0;
//item是一个指针数组,有10个元素,每个元素都是一个指针,指向char
char *items[10];


main() {
    char *ps,*read_ps;
    char *arrqueue(int);
    int enqueue(char item[],char *item_ps[]);
    char *dequeue();

    //函数返回类型char,(*变量名)表示*后面的变量是定义的指针变量,()表示指针变量所指的是一个函数
    //表示pf是一个指向函数入口的指针变量,函数返回值是char
    char (*pf)();
    //函数入口地址(函数名)赋予指针变量
    pf=arrqueue;
    //
    ps=(*pf)(10);

    enqueue("first word\n",items);
    enqueue("2 word\n",items);
    enqueue("3 word\n",items);
    enqueue("4 word\n",items);
    enqueue("5 word\n",items);
    enqueue("6 word\n",items);
    enqueue("7 word\n",items);
    enqueue("8 word\n",items);
    enqueue("9 word\n",items);
    enqueue("10 word\n",items);
    for (int i=0;i<10;i++){
        printf("%s",items[i]);
    }
    printf("\n");

    printf("%s",dequeue());
    printf("%s\n",dequeue());

    enqueue("11 word\n",items);
    for (int i=0;i<10;i++){
        printf("%s",items[i]);
    }

}

//函数名前加*表示函数是之指针型函数,char表示返回值的指针指向的数据类型
char *arrqueue(int capacity){
    n=capacity;
    //c是一个指针数组,有n个元素,每个元素都是一个指针,指向char(也可指向char数组)
    char *c[capacity];
    return c;
}

int enqueue(char item[],char *item_ps[]){
    if (tail == 10) {
//        return -1;
        //head=0 &&tail=10 表示队列被占满了
        if (head == 0) return -1;
        //数据搬移
        for(int i=head;i<tail;i++){
            items[i-head] = items[i];
        }
        //搬移之后更新head和tail
        printf("before move tail is %d\n",tail);
        tail -= head;
        head = 0;
        printf("after move tail is %d\n",tail);
    }
    item_ps[tail] = item;
    tail++;
    return 1;
}

char *dequeue(){
    if(head == tail) return NULL;
    char *ret = items[head];
    head++;
    return ret;
}
