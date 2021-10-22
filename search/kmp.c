//
// Created by tdcengineer on 2021/10/19.
//

#include <malloc.h>

//next数组计算
int *getNexts(char b[],int m){
    int *next = (int *)malloc(m*sizeof(int));
    next[0] = -1;
    int k = -1;//最长可匹配前缀字串
    for(int i=1;i<m;i++){
        while (k !=-1 && b[k+1] !=  b[i]){
            k = next[k];
        }
        if(b[k+1] == b[i]){
            ++k;
        }
        next[i] = k;
    }
    return next;
}



//a,b位模式串,主串   //n,m表示长度
int kmp(char a[],int n,char b[],int m){
    int *next = getNexts(b,m);
    int j = 0;
    for (int i=0;i<n;i++){
        while (j>0 && a[i] != b[j]){//一直找到a[i]和b[j]
            j = next[j-1] + 1;
        }
        if(a[i] == b[j]){
            j++;
        }
        if(j == m){ //找到匹配模式串了
            return i-m+1;
        }
    }
    return -1;

}