#include "stdio.h"
#include "stdlib.h"
#define MAX_VERtEX_NUM 20
#define VertexType int
typedef struct edge{
    VertexType initial;
    VertexType end;
    VertexType weight;
}edge[MAX_VERtEX_NUM];
//���帨������
typedef struct {
    VertexType value;//��������
    int sign;//ÿ�����������ļ���
}assist[MAX_VERtEX_NUM];

assist assists;

//qsort��������ʹ�ã�ʹedges�ṹ���еı߰���Ȩֵ��С��������
int cmp(const void *a,const void*b){
    return  ((struct edge*)a)->weight-((struct edge*)b)->weight;
}
//��ʼ����ͨ��
void CreateUDN(edge *edges,int *vexnum,int *arcnum){
    printf("������ͨ���ı�����\n");
    scanf("%d %d",&(*vexnum),&(*arcnum));
    printf("������ͨ���Ķ��㣺\n");
    for (int i=0; i<(*vexnum); i++) {
        scanf("%d",&(assists[i].value));
        assists[i].sign=i;
    }
    printf("������ߵ���ʼ����յ㼰Ȩ�أ�\n");
    for (int i=0 ; i<(*arcnum); i++) {
        scanf("%d,%d,%d",&(*edges)[i].initial,&(*edges)[i].end,&(*edges)[i].weight);
    }
}
//��assists�������ҵ�����point��Ӧ��λ���±�
int Locatevex(int vexnum,int point){
    for (int i=0; i<vexnum; i++) {
        if (assists[i].value==point) {
            return i;
        }
    }
    return -1;
}
int main(){

    int arcnum,vexnum;
    edge edges;
    CreateUDN(&edges,&vexnum,&arcnum);
    //����ͨ���е����б߽����������򣬽���Ա�����edges������
    qsort(edges, arcnum, sizeof(edges[0]), cmp);
    //����һ���յĽṹ�����飬���ڴ����С������
    edge minTree;
    //����һ�����ڼ�¼��С�������бߵ������ĳ���
    int num=0;
    //�������еı�
    for (int i=0; i<arcnum; i++) {
        //�ҵ��ߵ���ʼ����ͽ�������������assists�е�λ��
        int initial=Locatevex(vexnum, edges[i].initial);
        int end=Locatevex(vexnum, edges[i].end);
        //�������λ�ô����Ҷ���ı�ǲ�ͬ��˵������һ�������У����������·
        if (initial!=-1&& end!=-1&&assists[initial].sign!=assists[end].sign) {
            //��¼�ñߣ���Ϊ��С����������ɲ���
            minTree[num]=edges[i];
            //����+1
            num++;
            //���¼����������Ķ�����ȫ������Ϊһ����
            for (int k=0; k<vexnum; k++) {
                if (assists[k].sign==assists[end].sign) {
                    assists[k].sign=assists[initial].sign;
                }
            }
            //���ѡ��ıߵ������Ͷ��������1��֤����С�������Ѿ��γɣ��˳�ѭ��
            if (num==vexnum-1) {
                break;
            }
        }
    }
    //������
    for (int i=0; i<vexnum-1; i++) {
        printf("%d,%d\n",minTree[i].initial,minTree[i].end);
    }
    return 0;
}
