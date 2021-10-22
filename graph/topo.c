//
// Created by tdcengineer on 2021/10/20.
//
#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTEX_NUM 20 //最大顶点数
typedef int VertexType;//顶点数据类型


typedef struct ArcNode{ //边
    int adjvex; //邻接点在数组下标
    struct ArcNode * next;//下一个邻接点
} ArcNode;

typedef struct VNode{
    VertexType data;//顶点数据域
    ArcNode *firstArc;//邻接点
}VNode,AdjList[MAX_VERTEX_NUM]; //存储各链表头节点的数组

typedef struct {
    AdjList vertices;//图中顶点及各邻接点数组
    int vexnum,arcnum; //图中顶点数,边数
}ALGraph;

//顶点在邻接表的下标
int LocateVex(ALGraph G,VertexType u){
    for(int i=0;i<G.vexnum;i++){
        if(G.vertices[i].data == u){
            return i;
        }
    }
    return -1;
}

void createAOV(ALGraph **G){
    *G=(ALGraph*)malloc(sizeof(ALGraph));
    //创造一张图,设置最大顶点数,最大边数
    scanf("%d,%d",&((*G)->vexnum),&(*G)->arcnum);
    //生成顶点,放入邻接表vertice
    for(int i=0;i<(*G)->vexnum;i++){
        scanf("%d",&(*G)->vertices[i].data);
        (*G)->vertices[i].firstArc=NULL;
    }

    VertexType initial,end;

    for(int i=0;i<(*G)->arcnum;i++){
        scanf("%d,%d",&initial,&end);

        ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
        //找到end在邻接表下标,作为邻接点p
        p->adjvex = LocateVex(*(*G),end);
        p->next = NULL;
        //找到init在邻接表下标,作为顶点
        int locate=LocateVex(*(*G),initial);
        //p插入到顶点的链表首位(所有的邻接点都插入到init顶点的链表内)
        p->next=(*G)->vertices[locate].firstArc;
        (*G)->vertices[locate].firstArc=p;

    }

}

typedef struct stack{
    VertexType data;
    struct stack *next;
}stack;

void initStack(stack **S){
    (*S) = (stack*)malloc(sizeof(stack));
    (*S) ->next=NULL;
}
bool StackEmpty(stack S){
    if(S.next==NULL){
        return true;
    }
    return false;
}

void push(stack *S,VertexType u){
    stack *p=(stack*)malloc(sizeof(stack));
    p->data=u;
    p->next=NULL;
    p->next=S->next;
    S->next=p;
}
//出栈函数,删除来链表首元节点,并将节点的数据域传给i
void pop(stack *S,VertexType *i){
    stack *p = S->next;
    *i=p->data;
    S->next=S->next->next;
    free(p);
}

//统计各节点入度
void FindInDegree(ALGraph G, int indegree[]){
    //初始化数组
    for(int i=0;i<G.vexnum;i++){
        indegree[i]=0;
    }
    //遍历邻接表,各顶点的链表,下标每出现一次该下标对应顶点入度+1
    for(int i=0;i<G.vexnum;i++){
        ArcNode *p = G.vertices[i].firstArc;
        while (p){
            indegree[p->adjvex]++;
            p=p->next;
        }
    }
}

void TopologicalSort(ALGraph G){
    int indegree[G.vexnum];//记录各顶点入度
    FindInDegree(G,indegree);//统计各顶点入度
    //建立栈
    stack *S;
    initStack(&S);
    //查找度为0的顶点,作为起始点
    for(int i=0;i<G.vexnum;i++){
        if(!indegree[i]){
            push(S,i);
        }
    }
    int count = 0;
    //当栈为空,说明排序完成
    while (!StackEmpty(*S)){
        int index;
        //弹出,并记录顶点所在邻接表下标
        pop(S,&index);
        printf("%d",G.vertices[index].data);
        count++;
        //依次查找跟该顶点相链接的顶点，如果初始入度为1，当删除前一个顶点后，该顶点入度为0
        for(ArcNode *p=G.vertices[index].firstArc;p;p=p->next){
            VertexType k=p->adjvex;
            if(!(--indegree[k])){ //相当于顶点被删除,链表里的所有邻接点入度-1
                //顶点入度为0,入栈
                push(S,k);
            }
        }
    }
    if(count<G.vexnum){
        printf("该图有回路");
        return;
    }
}


int main(){
//    ALGraph *G;
//    createAOV(&G);
//    TopologicalSort(*G);
//    return 0;

    int m=10;
    if(--m == 0) printf("if %d",m);
    printf("final %d",m);
}