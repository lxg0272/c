//
// Created by tdcengineer on 2021/10/13.
//

#include <stdio.h>

#define SIZE 15
typedef struct {
    int key; //�ؼ��ֵ�ֵ
}SLNode;

typedef struct {
    SLNode r[SIZE];//�洢��¼������
    int length;//��¼�����м�¼������
}SqList;

//ϣ������
void ShellInsert(SqList *L,int gap){
    //ÿ��gapȡһ��Ԫ�����Ҫ�������������
    //��gap+1�� ��ʼ����,�ڸ��������л� ���в�������
    for(int i=gap+1;i<=L->length;i++){
        //ÿ�ν����n��,�����������:
        //���ǰ>��,����2��λ��
        if(L->r[i].key < L->r[i-gap].key){

            int j;
            //0λ���ڱ� ,�洢׼��������Ԫ��
            L->r[0] = L->r[i];
            //����һ��������������, �󲿷�������(������������),�����������,ֱ���ҵ�L[j]�����λ��
            for(int j=i-gap; j>0 && (L->r[0].key < L->r[j].key); j-=gap){
                L->r[j+gap] = L->r[j];
            }
            //L[j]�ҵ�λ�ú�,j���������ƶ�,j+gapλ�ÿճ���,�ѽ���ֵ�ŵ���λ
            L->r[j+gap] = L->r[0];
        }
    }
}




int shsort(int s[], int n)    /* �Զ��庯�� shsort()*/
{
    int i,j,d;
    d=n/2;    /*ȷ���̶�����ֵ*/
    while(d>=1)
    {
        for(i=d+1;i<=n;i++)    /*�����±��d+1��ʼ����ֱ�Ӳ�������*/
        {
            s[0]=s[i];    /*���ü�����*/
            j=i-d;    /*ȷ��Ҫ���бȽϵ�Ԫ�ص����ұ�λ��*/
            while((j>0)&&(s[0]<s[j]))
            {
                s[j+d]=s[j];    /*��������*/
                j=j-d;    /*������d��λ��V*/
            }
            s[j + d]=s[0];    /*��ȷ����λ�D����s[i]*/
        }
        d = d/2;    /*�����Ϊԭ����һ��*/
    }
    return 0;
}

int main()
{
    int a[11],i;    /*�������鼰����Ϊ��������*/
    printf("������ 10 �����ݣ�\n");
    for(i=1;i<=10;i++)
        scanf("%d",&a[i]);    /*�Ӽ���������10������*/
    shsort(a, 10);    /* ���� shsort()����*/
    printf("������˳���ǣ�\n");
    for(i=1;i<=10;i++)
        printf("%5d",a[i]);    /*�������������*/
    printf("\n");
    return 0;
}