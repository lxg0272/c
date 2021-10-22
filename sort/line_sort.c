//
//
//
#include <malloc.h>
#include <stdio.h>


int getMax(int *arr,int n){

    int maxVal = arr[0];
    for (int i=1;i<n;i++){
        if(arr[i]>maxVal) maxVal=arr[i];
    }
    return maxVal;
}

void bucketSort(int *arr,int n){
    int max = getMax(arr,n);
    int c[max+1]; //桶大小
    //桶初始化
    for(int i=0;i<=max;i++){
        c[i]=0;
    }
    for(int i=0;i<n;i++){
        c[arr[i]]++;
    }

    for(int i=0,j=0;i<=max;i++){ //由小到大逐个桶遍历排序
        while (c[i] != 0){ //对不为空的桶排序
            arr[j] = i; //桶里拿出放回原数组
            j++;
            c[i]--;
        }
    }

}







void countingSort(int *a, int n){
    if (n<=1) return;

    //获取样本最大值
    int max = a[0];
    for(int i=0;i<n;i++){
        if( max < a[i] ){
            max = a[i];
        }
    }
    //生成数组C,存放各元素的数量(连续数值,正整数)
    int c[max+1];
    for(int i=0;i<=max;i++){
        c[i] = 0;
    }

    //计算每个元素的计数
    for(int i=0;i<n;i++){
        c[a[i]]++;
    }

    //再依次累加
    int tmp=0;
    for(int i=1;i<=max;i++){
        c[i] = c[i-1] + c[i];
    }

    //临时数组r,存储排序后结果
    int r[n];
    //计算排序关键步骤
    for (int i=n-1;i>=0;i--){
        int index = c[a[i]]-1;
        r[index] = a[i];
        c[a[i]]--;
    }
    //结果拷贝给a数组
    for(int i=0;i<n;i++){
        a[i]=r[i];
    }


}


//用于基数排序,求数据最大位数
int maxbit(int *data,int n){

    int maxData=data[0];
    //最大数
    for(int i=1;i<n;i++){
        if(maxData<data[i]){ maxData=data[i]; }
    }

    //位数,每次除10直到计算出位数.
    int d=1,p=10;
    while (maxData >=p){
        maxData /= 10;
        ++d;
    }

    return d;

}



//由后往前依次做位排序,需要稳定排序
radix_sort(int *data, int n){

    int d = maxbit(data,n);
    int tmp[n];
    int count[10];
    int i,j,k,radix=1;
    for(i=1;i<=d;i++){ //进行d次排序
        for(j=0;j<10;j++){
            count[j] = 0; //每次分配前清空计数器
        }
        for(j=0;j<n;j++){
            k = (data[j]/radix) % 10;//统计每个桶中的记录数
            count[k]++;
        }
        //用计数排序方法
        for(j=1;j<10;j++){
            count[j] = count[j-1] + count[j]; //桶内依次累加计数
        }
        for(j=n-1;j>=0;j--){
            k=((data[j])/radix) % 10; //在桶列表里找到对应的桶
            tmp[count[k] - 1] = data[j]; //桶num-1就是原数组排序后的位置
            count[k]--;
        }
        for(j=0;j<n;j++){
            data[j] = tmp[j];
            printf("%d,",data[j]);
        }
        radix = radix * 10;
        printf("\n");
    }

    free(tmp);


}




main(){
    int a[]={2,5,3,0,2,3,0,3};
    countingSort(a,8);
    for (int i=0;i<=8;i++){
        printf("%d,",a[i]);
    }

    int arr[] = {53, 3, 542, 748, 14, 214, 154, 63, 616};

    radix_sort(arr,9);
    for(int i=0;i<=8;i++){
        printf("%d,",arr[i]);
    }

    int arr2[] = {8,4,2,3,5,1,6,9,0,7};
    bucketSort(arr2,10);
    for(int i=0;i<=9;i++){
        printf("%d,",arr2[i]);
    }


}