#include <stdio.h>
#include <stdlib.h>
#define  MAX 8
typedef struct{
    int key;
}SqNode;
typedef struct{
    SqNode r[MAX];
    int length;
}SqList;
//SR�еļ�¼�ֳ������֣��±�� i �� m ���򣬴� m+1 �� n Ҳ���򣬴˺����Ĺ����Ǻ϶�Ϊһ��TR�����У�ʹ������¼������
void Merge(SqNode SR[],SqNode TR[],int i,int m,int n){
    int j,k;
    //��SR�����е������ּ�¼���մ�С�����˳�������TR������
    for (j=m+1,k=i; i<=m && j<=n; k++) {
        if (SR[i].key<SR[j].key) {
            TR[k]=SR[i++];
        }else{
            TR[k]=SR[j++];
        }
    }
    //��ʣ��ı�ĿǰTR�����ж���ļ�¼���Ƶ�TR��������λ��
    while(i<=m) {
        TR[k++]=SR[i++];
    }
    while (j<=n) {
        TR[k++]=SR[j++];
    }
}

void MSort(SqNode SR[],SqNode TR1[],int s,int t){
    SqNode TR2[MAX];
    //�ݹ�ĳ���
    if (s==t) {
        TR1[s]=SR[s];
    }else{
        int m=(s+t)/2;//ÿ�εݹ齫��¼���м�¼ƽ�֣�ֱ��ÿ����¼����һ�ű�
        MSort(SR, TR2, s, m);//���ֿ���ǰ�벿�ֱ��еļ�¼��������
        MSort(SR,TR2, m+1, t);//����벿�ֱ��еļ�¼���й鲢����
        Merge(TR2,TR1,s,m, t);//���ǰ�벿�ֺͺ�벿���еļ�¼ͳһ��������
    }
}
//�鲢����
void MergeSort(SqList *L){
    MSort(L->r,L->r,1,L->length);
}

int main() {
    SqList * L=(SqList*)malloc(sizeof(SqList));
    L->length=7;
    L->r[1].key=49;
    L->r[2].key=38;
    L->r[3].key=65;
    L->r[4].key=97;
    L->r[5].key=76;
    L->r[6].key=13;
    L->r[7].key=27;
    MergeSort(L);
    for (int i=1; i<=L->length; i++) {
        printf("%d ",L->r[i].key);
    }
    return 0;
}
