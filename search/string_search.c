//
// Created by tdcengineer on 2021/10/13.
//

#include <malloc.h>
#include <stdbool.h>
#include <windef.h>

#define SIZE 256
//BF查找 暴力查找,O(m*n) 略

//RK查找 O(n) 需要借助哈希算法,否则O(m*n)

//BM查找

//坏字符规则,b模式串,m模式串长度

// bc散列表,用来存储模式串的散列表
void generateBC(char b[],int m,int *bc){
    for(int i=0;i<SIZE;i++){
        bc[i] = -1;//初始化bc
    }
    for(int i=0;i<m;i++){
        int ascii = (int)b[i]; //计算b[i]的ascii ,相同字母,保留最靠近尾部的元素
        bc[ascii] = i;
    }
}

////a主串,b模式串
//int bm(char a[], int n, char b[], int m){
//                int *bc = (int *)malloc(SIZE * sizeof(int));
//                generateBC(b,m,bc);//构建坏字符哈希表
//                int i=0; //i表示主串与模式串对其的第一个字符
//                while (i <= n-m){
//                    int j;
//                    for(j=m-1;j>=0;j--) {//模式串从后往前匹配
//                        if(a[i+j] !=b[j]) break;
//                    }
//                    if( j<0 ){
//            return i; //匹配成功,返回主串与模式串第一个匹配字符位置
//        }
//        //等同于将模式串往后滑动j-bc[(int)a[i+j])位
//        i = i + (j-bc[(int) a[i+j] ]);
//
//    }
//    return -1;
//
//}

//好后缀规则
//b表示模式串,m表示模式串长度, suffix,prefix数组事先申请好

void generateGS(char b[],int m,int suffix[],bool prefix[]){
    for(int i=0;i<m;i++){//初始化
        suffix[i] = -1;
        prefix[i] = false;
    }
    for(int i=0;i<m-1;i++){ //模式串从头开始截取一段 b[0,i]
        int j = i;
        int k = 0; //公共后缀字串长度
        while (j >=0 && b[j] == b[m-1-k]){ //与b[0,m-1]求公共后缀字串
            --j;
            ++k;
            suffix[k]=j+1; //j+1表示公共后缀子串在b[0.i]的下标
        }
        if(j==-1) prefix[k]=true;

    }
}
//-----------------------------整体实现bm
//
//j表示坏字符对应的模式串中的字符下标,m模式串长度
int moveByGS(int j,int m, int suffix[],bool prefix[]){
    int k = m-1-j;//好后缀长度
    if(suffix[k] !=-1) return j-suffix[k]+1; //如果后缀字串能匹配到,模式串向后移动j-suffix[k]+1
    for(int r = j+2;r<=m-1;r++){
        if(prefix[m-r] == true){//匹配到前缀子串,则模式串后移r位
            return r;
        }
    }
    return m;
}

//a主串,b模式串
int bm(char a[], int n, char b[], int m){
    int *bc = (int *)malloc(SIZE * sizeof(int));
    generateBC(b,m,bc);//构建坏字符哈希表
    int *suffix = (int *)malloc(m * sizeof(int));
    int *prefix = (bool *)malloc(m * sizeof(bool));
    int i=0; //i表示主串与模式串对其的第一个字符
    while (i <= n-m){
        int j;
        for(j=m-1;j>=0;j--) {//模式串从后往前匹配
            if(a[i+j] !=b[j]) break; //坏字符对应模式串中的下标是j
        }
        if( j<0 ){
            return i; //匹配成功,返回主串与模式串第一个匹配字符位置
        }
        //等同于将模式串往后滑动j-bc[(int)a[i+j])位
        int x = i + (j-bc[(int) a[i+j] ]);//坏字符移动位
        //加入好后缀规则
        int y = 0; //好后缀移动位
        if( j < m-1){//好后缀存在,即坏字符不在最后一位,说明坏字符后面有匹配
            y = moveByGS(j,m,suffix,prefix);
        }
        i = i + max(x,y);

    }
    return -1;

}

void main(){

};