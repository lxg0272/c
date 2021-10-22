//
// Created by tdcengineer on 2021/9/30.
//


#include <stdio.h>
#include <malloc.h>
#include "graph.h"
int visited[5]={0}; //初始化数组记录已访问顶点
int prev[5]={-1};//初始化数组记录访问路径
//队列-------------------------------------------------------------------
void initQueue(LinkQueue *q){
    //初始化空队列
    //创建头节点,队尾指针指向该节点
    q->front  = (QNode*)malloc(sizeof(QNode));
    q->rear = q->front;
    if( !q->front) {return;} //创建失败
    q->front->next = NULL; //头节点next指针为空
}

void EnQueue(LinkQueue *q,int e){
    QNode *p;
    p = (QNode *)malloc(sizeof(QNode)); //创建一个队列元素节点
    p->data = e;
    p->next = NULL;
    //将节点插入队尾
    q->rear->next = p;
    //修改队尾指针
    q->rear = p;
}

int DeQueue(LinkQueue *q,int *e){
    //如果队列不为空,删除队头,用e返回其值
    if(q->front == q->rear) return -1;//空队列
    QNode *p = q->front->next; //p指向队列的第一个元素
    *e = p->data; //队首元素赋值给e
    q->front->next = p->next; //删除头节点
    if(q->rear == p) q->rear = q->front; //如果此时队列为空,修改队尾指针
    free(p);
    return 0;
}

//图------------------------------------------------------------------------------

void CreateGraph(int n, VNode G[]){
    int i,e;
    ArcNode *p,*q;
    printf("Input the infomation of vertex\n");
    for(i=0;i<n;i++){
        scanf("%d",&G[i].data);
        G[i].firstArc = NULL;
    }

    for(i=0;i<n;i++){
        printf("node %d is %d\n",i,G[i].data);
    }

    for(i=0;i<n;i++){
        printf("Create the edges for %dth vertex\n",i);
        scanf("%d",&e);
        while (e!=-1){
            p = (ArcNode *) malloc(sizeof(ArcNode)); //创建一条边
            p->next = NULL;
            p->adjvex = e; //将该边指向的顶点信息赋值给adjvex
            if(G[i].firstArc == NULL) {
                G[i].firstArc = p;
                printf("new node value is %d\n",G[i].data);
                q=p;//尾指针移动到最后
            } //i节点的第一条边
            else q->next = p;    //下一条边
            q = p;//尾指针移动到最后
            printf("tail value is %d\n",q->adjvex);
            scanf("%d",&e);
        }
    }

}

int FirstAdj(VNode G[],int v){//返回第一邻接点在数组中的下标
    if(G[v].firstArc !=NULL) return G[v].firstArc->adjvex;
}

int NextAdj(VNode G[],int v){//返回下一个邻接点在数组中的下标
    ArcNode *p;
    p = G[v].firstArc;
    while (p!=NULL){
        if(visited[p->adjvex]) p=p->next; //遍历单节点存储的链表
        else return p->adjvex;
    }
    return -1;
}

//深度优先
void DFS(VNode G[],int v){
    int w;
    printf("%d ",G[v]); //访问当前顶点,打印该顶点的数据信息
    visited[v] = 1;     //设置该点状态为已访问
    w = FirstAdj(G,v);  //找到顶点v的第一个邻接点,如果无返回-1
    while (w !=-1){
        if(visited[w]==0){
            DFS(G,w); //递归进行深度优先搜索
        }
        //深度优先遍历完一条线路
        w =  NextAdj(G,v); //继续找顶点v的下一个邻接点,如无返回-1
    }

}




//void BFS(VNode G[],int v){
//    int w;
//    visit(v); //访问顶点v
//    visited[v]=1; //修改顶点状态为已访问
//    EnQueue(q,v); //顶点v入队
//
//    while (!emptyQ(q)){
//        DeQueue(&q,&v);  //出队列,元素由v返回
//        w = FirstAdj(G,v); //找到顶点v的第一个邻接点,如果无邻接点,返回-1
//        while (w!=-1){
//            if(visited[w] == 0){
//                visit(w);
//                EnQueue(q,w); //顶点w入队
//                visited[w] = 1;
//            }
//            w = NextAdj(G,v);//找到顶点v的下个邻接点,如无返回-1
//        }
//    }
//}

void printPath(int prev[], int v, int t){ //递归打印s->t的路径
    if(prev[t] != -1 && t!=v){
        printPath(prev,v,prev[t]);
    }
    printf("%d->",t);

}

void BFS(VNode G[],int v,int t){
    if(v==t) {printf("result founded.\n");return;}
    visited[v]=1; //修改顶点状态为已访问
    LinkQueue *lqueue = (LinkQueue*)malloc(sizeof(LinkQueue)); //创建一个队列,用于存储需要分批遍历的顶点
    EnQueue(lqueue,v); //顶点v入队

    int q,w,flag;//邻接点,出队顶点,结束标识
    while (flag != -1){
        flag = DeQueue(&lqueue,&w);  //出队列,元素由w返回
        //开始遍历出队顶点的所有邻接点
        q = FirstAdj(G,v); //找到顶点v的第一个邻接点,如果无邻接点,返回-1
        while (q!=-1){
            if(visited[q] == 0){
                prev[q] = w;
                if(q == t){
                    printPath(prev,v,t);
                }
                EnQueue(lqueue,q); //顶点q入队
                visited[q] = 1;
            }
            q = NextAdj(G,v);//找到顶点v的下个邻接点,如无返回-1
        }
    }
}


main(){

//    VNode G[5];
//    CreateGraph(5,G);
//    printf("%d\n",G[0].firstArc->next->adjvex);
//    DFS(G,0);

    LinkQueue *lqueue = (LinkQueue*)malloc(sizeof(LinkQueue));
    initQueue(lqueue);
    EnQueue(lqueue,1);
    EnQueue(lqueue,2);
    int b;
    DeQueue(lqueue,&b);
    printf("%d",b);
    DeQueue(lqueue,&b);
    printf("%d",b);

}