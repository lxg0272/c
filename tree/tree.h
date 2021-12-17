//
// Created by tdcengineer on 2021/9/30.
//

#ifndef PATTERN_TREE_H
#define PATTERN_TREE_H

#define TRUE 1
#define FALSE 0
typedef int Status;

typedef int TElemType; //定义二叉树节点的数据类型
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild,*rchile;
}BiTNode, *BiTree;

//等价于
// typedef struct BitNode BitNode;用于定义struct
// typedef struct BitNode *BitTree;用于定义指向struct的指针
Status CreateBiTree(BiTree *T);
Status PreOrderTraverse(BiTree T,Status (*visit)(TElemType e));



#endif //PATTERN_TREE_H
