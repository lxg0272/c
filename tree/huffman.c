#include <malloc.h>
#include <stdio.h>
#include <mem.h>

//
// Created by tdcengineer on 2021/10/8.
//
//哈夫曼树节点结构
typedef struct {
    int weight; //节点权重
    int parent, left, right;//父节点,左右子节点在数组下标
}HTNode, *HuffmanTree;

//动态二维数组,存储哈夫曼编码
typedef char ** HuffmanCode;

//
void Select(HuffmanTree HT,int end,int *s1, int *s2){ //HT数组存放哈夫曼树,end标识HT数组的最终位置,s1s2权重值最小的两个节点在数组位置
    int min1, min2; //最小,第二小
    //遍历数组初始下标1
    int i = 1;
    //遍历没有构建的点
    while (HT[i].parent !=0 && i<= end){
        i++;
    }
    min1 = HT[i].weight;
    *s1 = i;
    i++;
    //继续遍历
    while (HT[i].parent !=0 && i<=end){
        i++;
    }
    //将找到的第二个节点放入min2,如果更小放入min1
    if(HT[i].weight < min1){
        min2 = min1;
        *s2 = *s1;
        min1 = HT[i].weight;
        *s1 = i;
    } else{
        min2 = HT[i].weight;
        *s2 = i;
    }


    //比较后续节点与min1,min2大小
    for(int j=i+1;j<=end;j++){

        //跳过有父节点(已参与构建)的
        if(HT[j].parent !=0){
            continue;
        }
        //根据大小放入min1或min2
        if(HT[j].weight < min1){
            min2 = min1;
            min1 = HT[j].weight;
            *s2 = *s1;
            *s1 = j;
        }else if (HT[j].weight >=min1 && HT[j].weight < min2){
            min2 = HT[j].weight;
            *s2 = j;
        }

    }

}



//构建哈夫曼树
void CreateHuffmanTree(HuffmanTree *HT, int *w,int n){ //HT哈夫曼树数组,w权重数组,n节点个数
    if(n<=1) return;
    int m = 2*n-1; //哈夫曼树节点总数
    *HT = (HuffmanTree*) malloc((m+1) * sizeof(HTNode));
    HuffmanTree p = *HT;
    //初始化哈夫曼树所有叶子节点
    for(int i=1;i<=n;i++){ //0号位置不用
        (p+i)->weight = *(w+i-1);
        (p+i)->parent = 0;
        (p+i)->left = 0;
        (p+i)->right = 0;
    }
    //从树组下表n+1开始初始化哈夫曼树中除叶子节点以外的节点
    for(int i=n+1;i<=m;i++){
        (p+i)->weight = 0;
        (p+i)->parent = 0;
        (p+i)->left = 0;
        (p+i)->right = 0;
    }

    //构建哈夫曼树
    for(int i=n+1;i<=m;i++){
        int s1,s2;
        Select(*HT,i-1,&s1,&s2);
        (*HT)[s1].parent = (*HT)[s2].parent = i;
        (*HT)[i].parent = 0;
        (*HT)[i].left = s1;
        (*HT)[i].right = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
        printf("parent is %d->%d,s1 is %d->%d,s2 is %d->%d\n",i,(*HT)[i].weight,s1,(*HT)[s1].weight,s2,(*HT)[s2].weight);
    }

}

void HuffmanCoding(HuffmanTree HT,HuffmanCode *HC, int n){//n为节点个数
    *HC = (HuffmanCode*) malloc((n+1)* sizeof(char *));
    char *cd = (char*) malloc(n*sizeof(char)); //存放哈夫曼编码的字符串数组
    cd[n-1]='\0'; //字符串结束符

    for(int i=1;i<=n;i++){
        //从叶子节点出发,得到逆序的哈夫曼编码,需要在字符串数组中逆序存放
        int start = n-1;
        //当前节点在数组位置
        int c = i;
        //当前父节点在数组位置
        int j = HT[i].parent;
        //一直寻找到根节点
//        printf("parent path is %d",j);
        while(j!=0){
            printf("parent code is %d\n",HT[j].weight);
            //如果该节点是父节点的左子节点则0,右子节点为1

            if(HT[j].left == c){
                printf("left is %d\n",HT[HT[j].left].weight);
                cd[--start] = '0';
            } else{
                printf("right is %d\n",HT[HT[j].right].weight);
                cd[--start] = '1';
            }
            printf("%c->\n",cd[start]);
            printf("start is %d\n",start);
            //继续往上遍历
            c = j;
            j = HT[j].parent;
            printf("before j is %d,j is %d\n",HT[c].weight,j);
//            printf("->%d",HT[j].weight);
        }

        printf("end one cirfle ###################\n");

        //
        (*HC)[i] = (char*)malloc((n-start)*sizeof(char));
        strcpy((*HC)[i], &cd[start]);


    }
    free(cd);
}





void PrintHuffmanCode(HuffmanCode htable,int *w,int n){
    printf("Huffman code:\n");
    for(int i=1;i<=n;i++){
        printf("%d code = %s\n",w[i-1],htable[i]);
    }
}


void main(){
    int w[5] = {2,8,7,6,5};
    int n = 5;
    HuffmanTree htree;
    HuffmanCode htable;
    CreateHuffmanTree(&htree,w,n);
    HuffmanCoding(htree,&htable,n);
    PrintHuffmanCode(htable,w,n);
}