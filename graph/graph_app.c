//
// Created by tdcengineer on 2021/9/28.
//

#include <stdio.h>
#include <malloc.h>

int v=10;//顶点个数

typedef struct Edge{
    int adjvex;//指向点
    struct Edge *next_edge; //指向下一个边的指针
} Edge;

typedef struct Vertex{
    char data; //顶点内容
    struct Edge *first_edge //顶点的第一个边
} Vertex;

int getPos(Vertex nodeList[],char value){
    for(int i=0;i<v;i++){
        if (nodeList[i].data == value){ return i;}
    }
    return -1;
}

void link_last(Edge *list,Edge *edge){

    Edge *p = list;
    printf("start node is %d\n",p->adjvex);
    while(p->next_edge !=NULL){
        p = list->next_edge;

    }
    printf("end node is %d\n",p->adjvex);
    p->next_edge = edge;
}


void addEdge(Vertex *adjList,char v1,char v2){//无向图一条边存2次

    Edge *e1,*e2;
    int p1 = getPos(adjList,v1);
    int p2 = getPos(adjList,v2);


    //存储A->B
    e1 = (Edge *) malloc(sizeof(Edge));
    e1->adjvex = p2;
    e1->next_edge=NULL;

    if (adjList[p1].first_edge == NULL) {
        adjList[p1].first_edge = e1;

    } else{
        link_last(adjList[p1].first_edge,e1);
    }



    //存储B->A
    e2 = (Edge *)malloc(sizeof(Edge));
    e2->adjvex = p1;
    e2->next_edge = NULL;

    if(adjList[p2].first_edge == NULL){
        adjList[p2].first_edge = e2;
    } else{
        link_last(adjList[p2].first_edge,e2);
    }


}


//void bfs(Vertex *adjList,int s,int t){
//    if (s==t) return;
//    int visited[t],prev[t];
//    Vertex queue[v];
//    queue[0]=s
//    visited[s] = 1;
//    for(int i=0;i<v;i++){ prev[i]=-1; }
//
//
//
//}



//对列
typedef struct qNode {
    Vertex *point;
    struct qNode *next;
} qNode;

qNode *queue(){
    //创建一个头节点
    qNode *q = (qNode*)malloc(sizeof(qNode));
    //初始化头节点
    q->next=NULL;
    return q;
}

void add(qNode *rear,Vertex *vex){
    //创建队列新节点,包裹顶点
    qNode *q = (qNode*)malloc(sizeof(qNode));
    q->point = vex;
    q->next = NULL;
    printf("inner value %c\n",vex->data);
    printf("inner value %c\n",q->point->data);
    rear->next=q;
    rear = q;
    printf("inner value %c\n",rear->next->point->data);
}


//深度优先
int found = 0;

void dfs(int s,int t){
    found = 0;
    int visited[v];
    int prev[v];
    for(int i=0;i<v;i++){ prev[i] = -1; }


}

void recurDfs(Vertex *adjList,Vertex *vex,char t, int *visited,int *prev){
    //获取顶点所在列表位置下标
    int w=getPos(adjList,vex->data);
    if(found == 1) return;
    visited[w] = 1; //记录下标已访问过
    if(vex->data==t){ //找到,退出
        found=1;
        return;
    }
    Edge *p = vex->first_edge;
    while (p->next_edge !=NULL){
        int q = p->adjvex; //adjlist内顶点下标
        if(visited[q]==0){
            p=p->next_edge;

            prev[q] = w;
            recurDfs(adjList,)
        }

    }
}




main(){

    Vertex adj[v];  //邻接表存放顶点
    char vex[] = {'A','B','C','D'};
    char edges[][2] = {{'A', 'C'},
                       {'A', 'D'},
                       {'B', 'C'}};
    for(int i=0;i<=3;i++){
        adj[i].data=vex[i];
        adj[i].first_edge=NULL;
    }

    qNode *Queue = queue();
    add(Queue,&adj[0]);
//    add(q,&adj[1]);
    printf("%c\n",Queue->point->data);
    printf("555");

//    addEdge(adj,'A','B');
//    addEdge(adj,'A','C');
//    addEdge(adj,'A','D');


}