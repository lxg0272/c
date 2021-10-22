//
//
//
#include <malloc.h>
#include <stdio.h>


int partition(int *A,int p,int r){
    printf("input p is %d, r is %d\n",p,r);
    int piovt = A[r],i=p;
    for(int j=p;j<=r-1;j++){
        if(A[j] < piovt ){
            int tmp=A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
        }
    }
    int tmp=A[i];
    A[i]=A[r];
    A[r]=tmp;
    printf("i is %d,r is %d\n",i,r);
    return i;
}

//快排递归函数,p,r为下标
void quick_sort_c(int *A,int p,int r){
    if (p >= r) return;

    int q = partition(A,p,r);
    quick_sort_c(A,p,q-1);
    quick_sort_c(A,q+1,r);
}



//A数组,n数组长度
void quick_sort(int *A,int n){
    quick_sort_c(A,0,n-1);
}

main(){
    int a[]={1,3,5,6,8};
    quick_sort(a,5);
    for(int i=0;i<5;i++){
        printf("%d,",a[i]);
    }
}