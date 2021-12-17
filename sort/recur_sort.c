//
//
//
#include <malloc.h>
#include <stdio.h>

//递归函数

void merge(int *A,int p,int q,int r){
    int i=p,j=q+1,k=0;
    //申请一个[r...p]大小的临时数组
    int tmp[r-p+1];
    while (i<=q && j<=r){
        if (A[i] <= A[j]){
            tmp[k++] = A[i++];
        } else{
            tmp[k++] = A[j++];
        }
    }
    //判断哪个子数组有剩余
    int start = i,end = q;
    if ( j<=r ) start = j,end = r; //剩余数据拷贝至tmp

    while (start <= end ){
        tmp[k++] = A[start++];
    }
    //tmp拷贝回A
    for (int i=0;i<=r-p;i++){
        A[p+i] = tmp[i];
    }


//    int tmp[r-p]
}

void merge_sort_c(int *A,int p,int r){
    if (p>=r) return;
    //取中间p,r位置
    int q=(p+r)/2;
    //分治递归
    merge_sort_c(A,p,q);
    merge_sort_c(A,q+1,r);
    //
    merge(A,p,q,r);

}
//归并排序,A数组,n数组长度
void merge_sort(int *A,int n){
    merge_sort_c(A,0,n-1);
}

main(){

    int arr[] = {9,23,2,3,4,5,6,7,8};
    for (int i=0;i<=8;i++){
        printf("%d,",arr[i]);
    }
    printf("\n");
    merge_sort(arr,9);
    for (int i=0;i<=8;i++){
        printf("%d,",arr[i]);
    }

}