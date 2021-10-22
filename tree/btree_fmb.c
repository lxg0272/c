//
//
//
#include <malloc.h>
#include <stdio.h>

typedef int Status;

typedef struct bTreeNode{
    int value;
    struct bTreeNode *lchild,*rchild;
}node ;



node *createT(){
    int data;
    node *T;
    scanf("%d",&data);
    if(data==-1){
        T=NULL;

    }else{
        T=(node *) malloc(sizeof(node));
        T->value = data;
        printf("input %d left child node: \n",data);
        T->lchild = createT(T->lchild);
        printf("input %d right child node: \n",data);
        T->rchild = createT(T->rchild);
    }
    return T;

}



void addNode(node *root,node *lchild,node *rchild,int value){
    root->value = value;
    root->lchild = lchild;
    root->rchild = rchild;
}


void preSort(node *root){
    if(root){
        //先遍历根节点
        printf("%d\n",root->value);
        //遍历左子树
        preSort(root->lchild);
        //遍历右子树
        preSort(root->rchild);
    }
    return;
}



void midOrder(node *root){
    if(root){
        //先遍历左子树
        midOrder(root->lchild);
        //遍历根节点
        printf("%d\n",root->value);
        //再遍历又子树
        midOrder(root->rchild);
    }
    return;
}

void backOrder(node *root){
    if(root){
        //
        backOrder(root->lchild);
        //
        backOrder(root->rchild);
        //
        printf("%d\n",root->value);
    }
}


main(){


    node *ps;
    ps = createT();
    printf("\npre order:\n");
    preSort(ps);
    printf("\nmid order:\n");
    midOrder(ps);
    printf("\nback order:\n");
    backOrder(ps);




}