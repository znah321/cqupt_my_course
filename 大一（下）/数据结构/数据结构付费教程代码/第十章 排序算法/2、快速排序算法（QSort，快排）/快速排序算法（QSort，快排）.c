#include <stdio.h>
#include <stdlib.h>
#define MAX 9
//������¼�Ľṹ��
typedef struct {
    int key;
}SqNote;
//��¼��Ľṹ��
typedef struct {
    SqNote r[MAX];
    int length;
}SqList;
//�˷����У��洢��¼�������У��±�Ϊ 0 ��λ��ʱ���ŵģ������κμ�¼����¼���±�Ϊ 1 ����ʼ���δ��
int Partition(SqList *L,int low,int high){
    L->r[0]=L->r[low];
    int pivotkey=L->r[low].key;
    //ֱ����ָ���������������
    while (low<high) {
        //highָ�����ƣ�ֱ��������pivotkeyֵС�ļ�¼��ָ��ֹͣ�ƶ�
        while (low<high && L->r[high].key>=pivotkey) {
            high--;
        }
        //ֱ�ӽ�highָ���С��֧��ļ�¼�ƶ���lowָ���λ�á�
        L->r[low]=L->r[high];
        //low ָ�����ƣ�ֱ��������pivotkeyֵ��ļ�¼��ָ��ֹͣ�ƶ�
        while (low<high && L->r[low].key<=pivotkey) {
            low++;
        }
        //ֱ�ӽ�lowָ��Ĵ���֧��ļ�¼�ƶ���highָ���λ��
        L->r[high]=L->r[low];
    }
    //��֧����ӵ�׼ȷ��λ��
    L->r[low]=L->r[0];
    return low;
}
void QSort(SqList *L,int low,int high){
    if (low<high) {
        //�ҵ�֧���λ��
        int pivotloc=Partition(L, low, high);
        //��֧�������ӱ��������
        QSort(L, low, pivotloc-1);
        //��֧���Ҳ���ӱ��������
        QSort(L, pivotloc+1, high);
    }
}
void QuickSort(SqList *L){
    QSort(L, 1,L->length);
}
int main() {
    SqList * L=(SqList*)malloc(sizeof(SqList));
    L->length=8;
    L->r[1].key=49;
    L->r[2].key=38;
    L->r[3].key=65;
    L->r[4].key=97;
    L->r[5].key=76;
    L->r[6].key=13;
    L->r[7].key=27;
    L->r[8].key=49;
    QuickSort(L);
    for (int i=1; i<=L->length; i++) {
        printf("%d ",L->r[i].key);
    }
    return 0;
}
