//
// Created by tdcengineer on 2021/9/27.
//

//无向图

#include <malloc.h>
#include <stdio.h>

typedef struct Edge{ //边表
    int adjvex; //该边所指向的顶点的位置
    struct Edge *next_edge; //指向下一条弧的指针 --链式存储顶点有几条边
} Edge ;

typedef struct Vertex { //顶点表
    char data; //顶点数据
    Edge *first_edge; //指向第一条依附该顶点的弧
} Vertex,AdjList[100]; //存储各链表头节点的数组 //相当于 struct node AdjList[100] 声名一个数组

typedef struct GraphLnk {
    AdjList vertices;//图顶点的数组
    int vexnum,edgenum;//记录图顶点数,边数
}GraphLnk;


int get_position(GraphLnk *graph,char c){

    int i;
    for(i=0;i<graph->vexnum;i++){
        if(graph->vertices[i].data== c) return i;
    }
    return -1;

}

void link_last(Edge *list,Edge *node){

    Edge *p = list;
//    printf("p value is %d, p next value is %d\n",p->adjvex,p->next_edge->adjvex);

    while (p->next_edge){
        p = p->next_edge ;
//        printf("%d\n",p->adjvex);
    }
    p->next_edge = node;
}

//创建邻接表对应的图
GraphLnk *create_lgraph(){
    char c1,c2;
    char vex[] = {'A','B','C','D','E','F','G'};
    char edges[][2] = {{'A', 'C'},
                       {'A', 'D'},
                       {'A', 'F'},
                       {'B', 'C'},
                       {'C', 'D'},
                       {'E', 'G'},
                       {'F', 'G'}};
    int vlen = sizeof(vex);
    int elen = sizeof(edges)/ sizeof(edges[0]);
    int i,p1,p2;
    Edge *edge1,*edge2;

    GraphLnk *graph;
    graph = (GraphLnk *)malloc(sizeof(GraphLnk));
    //初始化顶点数,边数
    graph->edgenum=elen;
    printf("edge num :%d\n",elen);
    graph->vexnum=vlen;
    //初始化顶点
    for(int i=0;i<graph->vexnum;i++){
        graph->vertices[i].data = vex[i];
        graph->vertices[i].first_edge = NULL;
    }


    //初始化边
    for(int i=0;i<graph->edgenum;i++){
        //读边的起始点和终止顶点
        printf("edge(%d): \n", i);
        c1 = edges[i][0];
        c2 = edges[i][1];

        p1=get_position(graph,c1); //p1是自己
        p2=get_position(graph,c2); //p2是指向的点
        //初始化edge1 自己->目标
        edge1 = (Edge*)malloc(sizeof(Edge));
        edge1->adjvex = p2;//边存的是终止顶点,起始点是自己
        edge1->next_edge=NULL;
        //将edge1链接到p1所在链表的末尾

        if(graph->vertices[p1].first_edge == NULL){
            graph->vertices[p1].first_edge = edge1;
            printf("direct vertex to be put %d\n",graph->vertices[p1].first_edge->adjvex);
        } else{
            printf("vertex to be put %d, already vertex %d\n",edge1->adjvex,graph->vertices[p1].first_edge->adjvex);
            link_last(graph->vertices[p1].first_edge,edge1);
        }
        //初始化edge2 目标->自己
//        edge2 = (Edge*)malloc(sizeof(Edge));
//        edge2->adjvex = p1;
//        edge2->next_edge=NULL;
//        //将edge2连接到p2所在链的末尾
//        if(graph->vertices[p2].first_edge==NULL){
//            graph->vertices[p2].first_edge=edge2;
//        } else{
//            link_last(graph->vertices[p2].first_edge,edge2);
//        }


    }

    return graph;


}





main(){
    GraphLnk *g=create_lgraph();
    Edge *ps=g->vertices[0].first_edge;
    for(int i=0;i<g->vexnum;i++){
        printf("%c->%d->",g->vertices[i].data,ps->adjvex);
        while (ps->next_edge){
            ps = ps->next_edge;
            printf("%d->",ps->adjvex);
        }
        printf("\n");
    }

//    printf("%c,%d\n",g->vertices[0].data,g->vertices[0].first_edge->adjvex);
//    printf("%c,%d\n",g->vertices[0].data,g->vertices[0].first_edge->next_edge->adjvex);
//    printf("%c,%d\n",g->vertices[0].data,g->vertices[0].first_edge->next_edge->next_edge->adjvex);

}