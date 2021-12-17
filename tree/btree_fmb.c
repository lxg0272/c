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





//二叉树层次遍历
//http://data.biancheng.net/view/27.html
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//头尾指针初始位置
int front=0,rear=0;

void CreateBiTree(BiTree *T){
    *T = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->data = 1;
    (*T)->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->data=2;
    (*T)->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->lchild->data = 4;
    (*T)->lchild->rchild->data = 5;

    (*T)->rchild->data=3;
    (*T)->rchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->lchild->data=6;
    (*T)->rchild->rchild->data=7;

}

//入队函数
void Enqueue(BiTree *a,BiTree node){ //node -BitNode指针,也可以当作一条存储BitNode指针的链表
    a[rear++]=node; //a为存放*BitNode的数组
}

//出队函数
BiTNode* Dequeue(BiTNode** a){
    return a[front++];//返回一个BitNode指针,*BitNode
}
//输出函数
void displayNode(BiTNode *a){
    printf("%d \n",a->data);
}

int exec_level(){
    BiTree tree;
    BiTree a[20];
    BiTNode *p;

    Enqueue(a,tree);
    while (front<rear){
        p=Dequeue(a);
        displayNode(p);
        if(p->lchild){
            Enqueue(a,tree->lchild);
        }
        if(p->rchild){
            Enqueue(a,tree->rchild);
        }
    }

    return 0;


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