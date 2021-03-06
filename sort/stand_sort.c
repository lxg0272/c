//
//
//
#include <malloc.h>
#include <stdio.h>
#include <mem.h>
#include <stdbool.h>

void show(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d,",arr[i]);
    }
    printf("\n");
}

void swap(int *a,int *b){
    int tmp;
    tmp = *a;
    *a=*b;
    *b=tmp;
}

void bubbleSort(int a[] ,int n){


    for (int i=0; i<n; ++i){
        //提前退出冒泡排序的标识
        bool flag = false;
        for(int j=0; j < n-i-1; ++j){
            if(a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                flag = true;
            }
        }
        if (!flag) break; //没有数据交换,提前退出
    }
}

void insertSort(int a[], int n){

    if (n <= 1) return;

    for(int i=1; i<n; ++i){
        int value = a[i];
        int j = i-1;
        //查找插入的位置
        for (; j>=0; --j){
            if (a[j] > value){
                a[j+1] = a[j]; //数据移动
            } else {break;}
        }
        a[j+1] = value; //插入数据
    }

}

void selectSort(int *A,int n){
    int i,j;


    for(i=0;i<n;i++){//遍历整个数组

        int minIndex=i;
        for(j=i+1;j<n;j++){
            if(A[j]<A[minIndex]) minIndex=j;
        }
        swap(&A[i],&A[minIndex]);

    }
}

main(){
//    int a[]={8,4,3,2,1};
//    printf("\nbefore bubble sort\n");
//    for (int i=0; i<5; i++){
//        printf("%d,",a[i]);
//    }
//    bubbleSort(a,5);
//    printf("\nafter bubble sort\n");
//    for (int i=0; i<5; i++){
//        printf("%d,",a[i]);
//    }
//    printf("\n");

    int b[]={9,3,8,2,1};
    insertSort(b,5);

    for (int i=0; i<5; i++){
        printf("%d,",b[i]);
    }


}