//
// Created by tdcengineer on 2021/10/9.
//

#include <stdint.h>
#include <windef.h>
#include <stdio.h>

typedef char TElemType;

typedef enum {Link,Thread} PointerTag; //Link = 0表示指向左右子指针, Thread = 1表示指向前驱或后继线索指针

//二叉树线索节点存储结构
typedef struct BitThrNode{
    TElemType data; //节点数据
    struct BitThrNode *lchild,*rchild; //左右子指针
    PointerTag LTag;
    PointerTag RTag;
}BitThrNode, *BiThrTree;

BiThrTree pre=NULL;

//中序二叉树线索化
void InThreading(BiThrTree p){
    //当前节点存在
    if(p){//p遍历顺序:就是中序遍历,pre一直在p的上一个位置
        InThreading(p->lchild);//递归当前节点左子树,左指针指向上一节点pre
        //如果当前节点没有左子
        if(!p->lchild){
            p->LTag=Thread;
            p->lchild=pre; //第一个左子节点的前驱是NULL
        }
        //如果pre没有右子,右指针指向当前节点作为后继节点(线索化顺序:当前节点的左子节点线索化->pre和p移动->上一个节点的右子节点线索化)
        if(!pre->rchild){
            pre->RTag=Thread;
            pre->rchild = p;
        }
        pre = p; //p准备移动,pre跟随p的上一个位置
        InThreading(p->rchild);//右子树递归线索化
    }
}

//中序遍历线索二叉树
void InOrderThraverse_Thr(BiThrTree p){
    while (p){

        //一直找左子,找到中序第一个节点
        while (p->LTag == Link){
            p=p->lchild;
        }

        printf("%c",p->data);//操作节点数据
        //当右标识为1,直接找后继节点
        while (p->RTag == Thread && p->rchild !=NULL){
            p=p->rchild;
            printf("%c",p->data);
        }
        //其他,按中序遍历,继续遍历右子树最左下
        p=p->rchild;
    }
}