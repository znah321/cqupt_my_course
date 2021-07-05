#include <stdio.h>
#include <stdlib.h>
#define SIZE 15
typedef struct {
    int key;   //�ؼ��ֵ�ֵ
}SLNode;
typedef struct {
    SLNode r[SIZE];//�洢��¼������
    int length;//��¼�����м�¼������
}SqList;
//ϣ�������ʵ�ֺ��������� dk ��ʾ��ֵ��
void ShellInsert(SqList * L,int dk){
    //�� dk+1 ����¼��ÿ��� dk ����¼�͵�ȡһ������ֱ�Ӳ��������㷨
    for (int i=dk+1; i<=L->length; i++) {
        //����µ�ȡ�Ĺؼ��ֵ�ֵ�����ӱ������һ����¼�Ĺؼ���С��˵����Ҫ����ֵ����λ��
        if (L->r[i].key<L->r[i-dk].key) {
            int j;
            //��¼���У�ʹ��λ���±�Ϊ 0 �Ŀռ�洢��Ҫ����λ�õļ�¼��ֵ
            L->r[0]=L->r[i];
            //��ֱ�Ӳ�����������±�Ϊ 0 �Ĺؼ��ֱ��±�Ϊ j �Ĺؼ���С�������һ���±�Ϊ j ��ֵ��Ϊ�²���ļ�¼�ڳ��ռ䡣
            for (j=i-dk; j>0 && (L->r[0].key<L->r[j].key); j-=dk){
                L->r[j+dk]=L->r[j];
            }
            //����ѭ���󣬽��µļ�¼ֵ���뵽�ڳ��Ŀռ��У��������һ��ֱ�Ӳ�������
            L->r[j+dk]=L->r[0];
        }
    }
}
//ϣ������ͨ�����ò�ͬ������ֵ����¼����ʵ�ֶԶ���ӱ�ֱ����ֱ�Ӳ�������
void ShellSort(SqList * L,int dlta[],int t){
    for (int k=0; k<t; k++) {
        ShellInsert(L, dlta[k]);
    }
}
int main(int argc, const char * argv[]) {
    int dlta[3]={5,3,1};//���������洢����ֵ������ 5 ����ÿ���5����¼���һ���ӱ�1��ʾÿ���һ����Ҳ�������һ�ζ����ű��ֱ�Ӳ�������
    SqList *L=(SqList*)malloc(sizeof(SqList));
    L->r[1].key=49;
    L->r[2].key=38;
    L->r[3].key=64;
    L->r[4].key=97;
    L->r[5].key=76;
    L->r[6].key=13;
    L->r[7].key=27;
    L->r[8].key=49;
    L->r[9].key=55;
    L->r[10].key=4;
    L->length=10;
    //����ϣ�������㷨
    ShellSort(L, dlta, 3);
    //������
    for (int i=1; i<=10; i++) {
        printf("%d ",L->r[i].key);
    }
    return 0;
}
