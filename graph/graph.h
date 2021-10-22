//
// Created by tdcengineer on 2021/9/30.
//

#ifndef PATTERN_GRAPH_H
#define PATTERN_GRAPH_H

#define MAX_VERTEX_NUM 20 //图种最大20个顶点
typedef int VertexType;

typedef struct ArcNode{ //边
    int adjvex; /*邻接点在数组中的下标*/
    struct ArcNode *next;//下一个邻接点
}ArcNode;

typedef struct VNode{//顶点
    VertexType data; //顶点存储的数据信息
    ArcNode *firstArc //指向邻接点
}VNode;

VNode G[MAX_VERTEX_NUM]; //vNode类型的数组G,存储图中的顶点

//队列---------------------
typedef int QelemType;

typedef struct QNode{
    QelemType data; //链队列节点中的数据域
    struct QNode *next; //链队列节点中的指针
}QNode, *QueuePtr;

typedef struct LinkQueue{
    QueuePtr front; //队头指针
    QNode *rear;   //队尾
}LinkQueue;







#endif //PATTERN_GRAPH_H
