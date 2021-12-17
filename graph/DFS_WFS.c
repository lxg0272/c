//
// Created by tdcengineer on 2021/11/19.
//http://data.biancheng.net/view/39.html

#include <stdint.h>
#include <stdio.h>

int visited[20];//全局数据,记录顶点是否访问过
typedef struct {
    int adj; //用1和0表示是否相邻
    char info;
}ArcCell,AdjMatrix[20][20];

typedef struct {
    int vexs[20]; //存储图中顶点数据
    AdjMatrix arcs;//二维数组,记录顶点之间关系
    int vexnum,arcnum;//顶点数,边数
}MGraph;

//根据顶点本身数据,判断出顶点在二维数组位置
int LocateVex(MGraph *G,int v){
    int i=0;
    //遍历一维数组,找到变量v
    for(;i<G->vexnum;i++){
        if(G->vexs[i]==v){
            return i;
        }
    }
    //找不到退出
    return -1;
}

int FirstAdjVex(MGraph G,int v){
    //查找与数组下标为v的顶点之间有边的顶点,返回它在数组的下标
    for(int i=0;i<G.vexnum;i++){
        if(G.arcs[v][i].adj){
            return i;
        }
    }
    return -1;
}

int NextAdjVex(MGraph G,int v,int w){
    //从前一个位置访问w的下一个位置开始,查找之间有边的顶点
    //当作先序遍历
    for(int i=w+1;i<G.vexnum;i++){
        if(G.arcs[v][i].adj){
            return i;
        }
    }
    return -1;
}

void visitVex(MGraph G,int v){
    printf("%d",G.vexs[v]);
}


void DFS(MGraph G,int v){
    visited[v] = 1;
    visitVex(G,v);//访问第V个顶点
    //从该顶点第一个边开始,一直到最后一个边,对处于边的另一端的顶点调用DFS函数
    for(int w = FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w)){
        //
        if(!visited[w]){
            DFS(G,w);
        }
    }
}

void DFSTraverse(MGraph G){
    int v;
    for(v=0;v<G.vexnum;++v){
        visited[v]=0;
    }

    for(v=0;v<G.vexnum;v++){
        if(!visited[v]){
            DFS(G,v);
        }
    }
}

