#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM_OF_KEY 8//���ɹؼ��ֵ���ɲ��ֵ�������
#define RADIX 10        //����������ؼ��������֣�������0~9��ɣ���������10������ؼ������ַ�������ĸ��ɣ����������� 26
#define MAX_SPACE 10000
//��̬����Ľ��ṹ
typedef struct{
    int data;//�洢�Ĺؼ���
    int keys[MAX_NUM_OF_KEY];//�洢�ؼ��ֵ����飨��ʱ��һλһλ�Ĵ洢�������У�
    int next;//��ָ���ã������Ǿ�̬��������ÿ������д洢����һ��������������е�λ���±�
}SLCell;
//��̬����ṹ
typedef struct{
    SLCell r[MAX_SPACE];//��̬����Ŀ����ÿռ䣬����r[0]Ϊͷ���
    int keynum;//��ǰ���еĹؼ��������Ĺؼ�����������λ�����������ؼ����ǰ٣�˵������keynum=3
    int recnum;//��̬����ĵ�ǰ����
} SLList;

typedef int  ArrType[RADIX];//ָ�����飬���ڼ�¼�������е���βλ��
//����ķ����㷨��i��ʾ���շ����λ�Σ��Ǹ�λ��ʮλ���ǰ�λ����f��ʾ���������е�һ����¼�����һ����¼��λ��
void Distribute(SLCell *r,int i,ArrType f,ArrType e){
    //��ʼ��ָ������
    for (int j=0; j<RADIX; j++) {
        f[j]=0;
    }
    //���������ؼ���
    for (int p=r[0].next; p; p=r[p].next) {
        int j=r[p].keys[i];//ȡ��ÿ���ؼ��ֵĵ� i λ�����ڲ��õ������λ���ȷ������ԣ����磬�� 1 λָ�ľ���ÿ���ؼ��ֵĸ�λ
        if (!f[j]) {//���ֻ���λ���ֵ�ָ�벻���ڣ�˵�����ǵ�һ���ؼ��֣�ֱ�Ӽ�¼�ùؼ��ֵ�λ�ü���
            f[j]=p;
        }else{//������ڣ�˵��֮ǰ�Ѿ���ͬ�ùؼ�����ͬλ�ļ�¼��������Ҫ����������ӣ������һ����ͬ�Ĺؼ��ֵ�nextָ��ָ��ùؼ������ڵ�λ�ã�ͬʱ����ƶ�βָ���λ�á�
            r[e[j]].next=p;
        }
        e[j]=p;//�ƶ�βָ���λ��
    }
}
//����������ռ��㷨�����������������и�����βָ��
void Collect(SLCell *r,int i,ArrType f,ArrType e){
    int j;
    //�� 0 ��ʼ����������ͷָ�벻Ϊ�յ������Ϊ�ձ�����λû�и����͵Ĺؼ���
    for (j=0;!f[j]; j++);
    r[0].next=f[j];//��������ͷ���
    int t=e[j];//�ҵ�βָ���λ��
    while (j<RADIX) {
        for (j++; j<RADIX; j++) {
            if (f[j]) {
                r[t].next=f[j];//����������һ��λ�ε��׸��ؼ���
                t=e[j];//t������һ��λ�ε�βָ�����ڵ�λ��
            }
        }
    }
    r[t].next=0;//0��ʾ�������
}
void RadixSort(SLList *L){
    ArrType f,e;
    //���ݼ�¼���������Ĺؼ��ֵ����λ����һλһλ�Ľ��з������ռ�
    for (int i=0; i<L->keynum; i++) {
        //�����ȷ�����ռ���˳��
        Distribute(L->r, i, f, e);
        Collect(L->r, i, f, e);
    }
}
//������̬����
void creatList(SLList * L){
    int key,i=1,j;
    scanf("%d",&key);
    while (key!=-1) {
        L->r[i].data=key;
        for (j=0; j<=L->keynum; j++) {
            L->r[i].keys[j]=key%10;
            key/=10;
        }
        L->r[i-1].next=i;
        i++;
        scanf("%d",&key);
    }
    L->recnum=i-1;
    L->r[L->recnum].next=0;
}
//�����̬����
void print(SLList*L){
    for (int p=L->r[0].next; p; p=L->r[p].next) {
        printf("%d ",L->r[p].data);
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    SLList *L=(SLList*)malloc(sizeof(SLList));
    L->keynum=3;
    L->recnum=0;
    creatList(L);//������̬����
    printf("����ǰ��");
    print(L);

    RadixSort(L);//�Ծ�̬�����еļ�¼���л�������

    printf("�����");
    print(L);
    return 0;
}
