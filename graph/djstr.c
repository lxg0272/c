//
// Created by tdcengineer on 2021/10/21.
//http://data.biancheng.net/view/46.html
#include <stdio.h>
#define MAX_VERTEX_NUM 20
#define VRType int
#define VertexType int
#define INFINITY 65535

typedef struct {
    VertexType vexs[MAX_VERTEX_NUM]; //存储图顶点的值
    VRType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //二维数组,记录顶点之间的关系
    int vexnum,arcnum; //记录图顶点数,边数
}MGraph;

typedef int PathMatrix[MAX_VERTEX_NUM]; //存储最短路径中经过的顶点下标
typedef int ShortPathTable[MAX_VERTEX_NUM]; //存储各个最短路径的权值和

//根据顶点本身数据,判断出顶点在二维数组中的位置
int LocateVex(MGraph *G,VertexType v){
    int i=0;
    //遍历一维数组,找到v
    for(; i<G->vexnum; i++){
        if(G->vexs[i]==v){
            break;
        }
    }
    //如果找不到,输出提示语句,返回-1
    if(i>G->vexnum){
        printf("no such vertex.\n");
        return -1;
    }
    return i;
}

//构造有向网
void createUDG(MGraph *G){
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    //初始化顶点值
    for(int i=0;i<G->vexnum;i++){
        scanf("%d",&(G->vexs[i]));
    }
    //初始化所有顶点间距离
    for(int i=0;i<G->vexnum;i++){
        for(int j=0;j<G->vexnum;j++){
            G->arcs[i][j]=INFINITY;
        }
    }
    //所有顶点间距离赋值
    for(int i=0;i<G->arcnum;i++){
        int v1,v2,w;
        scanf("%d,%d,%d",&v1,&v2,&w);
        int n=LocateVex(G,v1);
        int m=LocateVex(G,v2);
        if(m==-1 || n==-1){
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m]=w;
    }

}

//迪杰斯特拉,v0表示有向网中起始点下标
void ShortestPath_dijstra(MGraph G,int v0,PathMatrix *p,ShortPathTable *D){
    int final[MAX_VERTEX_NUM]; //存储各个点是否已确定最短路径
    //初始化p,D数组
    for(int v=0;v<G.vexnum;v++){
        final[v]=0;
        (*D)[v]=G.arcs[v0][v]; //vo到各个顶点距离
        (*p)[v]=0;
    }
    //由于以v0作为起始点,不再判断
    (*D)[v0]=0;
    final[v0]=1;

    int k=0;
    for(int i=0;i<G.vexnum;i++){
        int min = INFINITY;
        //选择v0到各顶点权值最小的顶点,即位本次能确定最短路径的顶点
        for(int w=0;w<G.vexnum;w++){
            if(!final[w]){
                if((*D)[w]<min){
                    k=w;
                    min=(*D)[w];
                }
            }
        }

        //获得最小距离点k,设置该顶点标志位为1
        final[k]=1;
        //对v0到各顶点的权值进行更新
        for(int w=0;w<G.vexnum;w++){
            if(!final[w]&&( min+G.arcs[k][w] < (*D)[w] )){//k作为起点,到各个点的距离, v0->k->各个点距离 和v0->各个点比较
                (*D)[w]=min +G.arcs[k][w]; //如果v0->k->a(举例) < v0->a ,则D[a]=v0->k->a,即v0到a的最小距离为v0->k->a
                (*p)[w]=k; //把k记录到a点的最短路径上
            }
        }
    }

}


int main(){
    MGraph G;
    createUDG(&G);
    PathMatrix P;
    ShortPathTable D;
    ShortestPath_dijstra(G,0,&P,&D);
    for(int i=1;i<G.vexnum;i++){
        printf("V%d - V%d的最短路径中的顶点-逆序:,",0,i);
        printf(" V%d",i);
        int j=i;
        //由于每一段最短路径上都记录经过的顶点,采用嵌套输出获取各路径所有的点
        while (P[j] !=0){
            printf(" V%d",P[j]);
            j=P[j];
        }
        printf(" V0\n");
    }
    printf("源点到各顶点的最短路径长度为:\n");
    for(int i=1;i<G.vexnum;i++){
        printf("V%d - V%d : %d \n",G.vexs[0],G.vexs[i],D[i]);
    }
    return 0;
}


//6,8
//0
//1
//2
//3
//4
//5
//0,5,100
//0,4,30
//0,2,10
//1,2,5
//2,3,50
//3,5,10
//4,3,20
//4,5,60