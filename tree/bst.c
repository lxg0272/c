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


void insert(node *p,int data){




    node *ps = (node *)malloc(sizeof(node));


//    if(p == NULL){
//        *p = *ps;
//    }

    while (p !=NULL){
        printf("current node is %d\n",p->value);
        if(data > p->value){
            if(p->rchild == NULL){

                p->rchild = (node *)malloc(sizeof(node));
                p->rchild->value = data;
                p->rchild->lchild=NULL;
                p->rchild->rchild=NULL;
                printf("right node is %d\n",data);
                return;
            }
            p = p->rchild;
            printf("step front right node %d \n",p->value);
        } else {
            if(p->lchild == NULL){

                p->lchild = (node *)malloc(sizeof(node));
                p->lchild->value=data;
                p->lchild->lchild=NULL;
                p->lchild->rchild=NULL;
                printf("left node is %d\n",data);

                return;
            }
            printf("step front left node %d\n",p->value);
            p=p->lchild;
        }
    }
}

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

int createBST(node *T){
    printf("input first num of tree:\n");

    int num;
    scanf("%d",&num);
    while (num != -1){
        insert(T,num);
        printf("input num to build tree, -1 to end :\n",num);
        scanf("%d",&num);
    }

    printf("%s func done ,created\n",__FUNCTION__);
    return 1;

}




node tree = {100,NULL,NULL};


node *findNode(int data){

    node *p = &tree;

    while (p!=NULL){
        if(data < p->value) {p=p->lchild;}
        else if (data > p->value) {p=p->rchild;}
        else {return p;}
    }
    return NULL;
}



void delete (node *p,int data){
    //p记录要删除的节点,初始化指向根节点
    node *pp; //pp记录父节点
    //找到要删除的节点
    while(p!=NULL && p->value !=data){
        pp = p;
        if(data > p->value ){p=p->rchild;}
        else{p=p->lchild;}
    }


    if(p==NULL) return;
    printf("parent node is %d,delete node is %d\n",pp->value,p->value);

    //要删除的节点有2个子节点
    if(p->lchild != NULL && p->rchild !=NULL){//查找右子树最小节点
        node *minP = p->rchild;
        node *minPP = minP; //记录minP的父节点
        while (minP->lchild !=NULL){//开始遍历右子树
            minPP = minP;
            minP = minP->lchild;
        }
        printf("min PP is %d, min P is %d\n",minPP->value,minP->value);
        p->value = minP->value; //将最小节点替换到要删除的p中.
        printf("delete node is changed to  %d  \n",p->value);
        p = minP; //指针指向最小节点,由于删除节点数据已被最小节点替换,删除最小节点即可
        pp = minPP;

    }

    //删除的节点是叶子节点或只有一个子节点
    node *child; //p的子节点
    if(p->lchild !=NULL) child = p->lchild;
    else if(p->rchild !=NULL) child = p->rchild;
    else child = NULL;

    //叶子节点直接把父节点的左子节点或右子节点置为NULL(包括含有双子节点的最后一步删除操作)
    if (pp->lchild->value == p->value) pp->lchild = child;
    else pp->rchild = child;

}



void preOrder(node *p){
    if (p){
        printf("%d\n",p->value);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }

}


main(){
    node *ps;
//    ps = createT();
    node a = {5,NULL,NULL};
    node b = {16,NULL,NULL};
    node c = {7,&a,&b};

    createBST(&b);
    preOrder(&b);
    printf("\n");
    delete(&b,13);
    preOrder(&b);

//    node *p1,*p2,*p3;
//    p1 = &a;
//    p2 = &b;
//
//    printf("%d\n",p1->value);
//
//    p1->value = p2->value;
//    b.value = 66;
//    printf("%d\n",a.value);



}