//
// Created by tdcengineer on 2021/9/26.
//

#include <stdio.h>

int count,n;

void swap(int *x,int *y){
    int tmp=*x;
    *x = *y;
    *y = tmp;
}

void show(int *a,int n){
    for(int i=0;i<n;i++){
        printf("%d,",a[i]);
    }
}

int *max(int *a,int *b){
    int *max = a;
    if (*b > *max) max = b;
    return max;
}

//从下往上堆化(也是第1种建堆方式)
void insert(int *a,int data){
    if (count > n) return;
    ++count;
    a[count] = data;
    int i = count;
    while( i/2 > 0 && a[i] > a[i/2]){//0和1 不需要交换
        swap(a+i,a+i/2);
        i=i/2;
    }
}




//从上往下堆化
heapify(int *a,int n,int i){
    while (1){
        int maxPos = i;
        if(i*2<=n && a[i]<a[i*2]) maxPos = i*2;//左子节点大
        if(i*2+1<=n && a[i]<a[i*2+1] && a[i*2+1] > a[i*2]) maxPos = i*2+1;//右子节点大
        //这里应该选择二者更大(小)的作为交换节点
        //如果maxpos没发生变化,退出
        if(maxPos == i) break;
        swap(a+i,a+maxPos);
        //指向被交换节点
        i = maxPos;
    }
}

//第2种建堆 --从上往下堆化
void buildheap(int *a,int n){
    //从第一个非叶子节点开始,n/2=i是第一个非叶子节点
    for(int i=n/2;i>=1;--i){
        heapify(a,n,i);
    }
}



void delete_top(int *a){
    //删除顶部,最后一个元素移至顶部
    if (count == 0) return;
    a[1]=a[count];
    a[count] = NULL;
    --count;
    heapify(a,count,1);
}

void sort(int *a,int n){
    buildheap(a,n);
    int k = n;
    while (k>1){
        swap(a+1,a+k); //头节点和最后一位互换,取走头节点
        --k;
        heapify(a,k,1);//堆化,然后继续取走头节点
    }
}



///////////////////////////////////heap应用
//1.优先级队列



main(){
    count=5;
    int a[6]={9999,6,2,3,4,5};
//    delete_top(a);
//    buildheap(a,5);
    sort(a,5);
    show(a,6);

}