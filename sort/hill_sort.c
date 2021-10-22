//
// Created by tdcengineer on 2021/10/13.
//

#include <stdio.h>

#define SIZE 15
typedef struct {
    int key; //关键字的值
}SLNode;

typedef struct {
    SLNode r[SIZE];//存储记录的数组
    int length;//记录数组中记录的数量
}SqList;

//希尔排序
void ShellInsert(SqList *L,int gap){
    //每隔gap取一个元素组成要插入排序的数组
    //从gap+1个 开始遍历,在各个数组切换 进行插入排序
    for(int i=gap+1;i<=L->length;i++){
        //每次进入第n组,插入排序操作:
        //如果前>后,交换2者位置
        if(L->r[i].key < L->r[i-gap].key){

            int j;
            //0位置哨兵 ,存储准备交换的元素
            L->r[0] = L->r[i];
            //进入一个插入排序数组, 左部分已排序(插入排序特性),从右往左遍历,直到找到L[j]插入的位置
            for(int j=i-gap; j>0 && (L->r[0].key < L->r[j].key); j-=gap){
                L->r[j+gap] = L->r[j];
            }
            //L[j]找到位置后,j继续向左移动,j+gap位置空出来,把交换值放到空位
            L->r[j+gap] = L->r[0];
        }
    }
}




int shsort(int s[], int n)    /* 自定义函数 shsort()*/
{
    int i,j,d;
    d=n/2;    /*确定固定增虽值*/
    while(d>=1)
    {
        for(i=d+1;i<=n;i++)    /*数组下标从d+1开始进行直接插入排序*/
        {
            s[0]=s[i];    /*设置监视哨*/
            j=i-d;    /*确定要进行比较的元素的最右边位置*/
            while((j>0)&&(s[0]<s[j]))
            {
                s[j+d]=s[j];    /*数据右移*/
                j=j-d;    /*向左移d个位置V*/
            }
            s[j + d]=s[0];    /*在确定的位罝插入s[i]*/
        }
        d = d/2;    /*增里变为原来的一半*/
    }
    return 0;
}

int main()
{
    int a[11],i;    /*定义数组及变量为基本整型*/
    printf("请输入 10 个数据：\n");
    for(i=1;i<=10;i++)
        scanf("%d",&a[i]);    /*从键盘中输入10个数据*/
    shsort(a, 10);    /* 调用 shsort()函数*/
    printf("排序后的顺序是：\n");
    for(i=1;i<=10;i++)
        printf("%5d",a[i]);    /*输出排序后的数组*/
    printf("\n");
    return 0;
}