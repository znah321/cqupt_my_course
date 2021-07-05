#include <stdio.h>
#define MAX_VERtEX_NUM 20                   //�����������
#define VRType int                          //��ʾ����Ȩֵ������
#define VertexType int                      //ͼ�ж������������
#define INFINITY 65535
typedef struct {
    VertexType vexs[MAX_VERtEX_NUM];        //�洢ͼ�ж�������
    VRType arcs[MAX_VERtEX_NUM][MAX_VERtEX_NUM];                         //��ά���飬��¼����֮��Ĺ�ϵ
    int vexnum,arcnum;                      //��¼ͼ�Ķ������ͻ����ߣ���
}MGraph;

typedef int PathMatrix[MAX_VERtEX_NUM];     //���ڴ洢���·���о����Ķ�����±�
typedef int ShortPathTable[MAX_VERtEX_NUM]; //���ڴ洢�������·����Ȩֵ��

//���ݶ��㱾�����ݣ��жϳ������ڶ�ά�����е�λ��
int LocateVex(MGraph * G,VertexType v){
    int i=0;
    //����һά���飬�ҵ�����v
    for (; i<G->vexnum; i++) {
        if (G->vexs[i]==v) {
            break;
        }
    }
    //����Ҳ����������ʾ��䣬����-1
    if (i>G->vexnum) {
        printf("no such vertex.\n");
        return -1;
    }
    return i;
}
//����������
void CreateUDG(MGraph *G){
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    for (int i=0; i<G->vexnum; i++) {
        scanf("%d",&(G->vexs[i]));
    }
    for (int i=0; i<G->vexnum; i++) {
        for (int j=0; j<G->vexnum; j++) {
            G->arcs[i][j]=INFINITY;
        }
    }
    for (int i=0; i<G->arcnum; i++) {
        int v1,v2,w;
        scanf("%d,%d,%d",&v1,&v2,&w);
        int n=LocateVex(G, v1);
        int m=LocateVex(G, v2);
        if (m==-1 ||n==-1) {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m]=w;
    }
}
//�Ͻ�˹�����㷨��v0��ʾ����������ʼ�����������е��±�
void ShortestPath_Dijkstra(MGraph G,int v0,PathMatrix *p,ShortPathTable *D){
    int final[MAX_VERtEX_NUM];//���ڴ洢�������Ƿ��Ѿ�ȷ�����·��������
    //�Ը�������г�ʼ��
    for (int v=0; v<G.vexnum; v++) {
        final[v]=0;
        (*D)[v]=G.arcs[v0][v];
        (*p)[v]=0;
    }
    //������v0λ�±�Ķ���Ϊ��ʼ�㣬���Բ������ж�
    (*D)[v0]=0;
    final[v0]=1;
    int k = 0;
    for (int i=0; i<G.vexnum; i++) {
        int min=INFINITY;
        //ѡ�񵽸�����Ȩֵ��С�Ķ��㣬��Ϊ������ȷ�����·���Ķ���
        for (int w=0; w<G.vexnum; w++) {
            if (!final[w]) {
                if ((*D)[w]<min) {
                    k=w;
                    min=(*D)[w];
                }
            }
        }
        //���øö���ı�־λΪ1�������´��ظ��ж�
        final[k]=1;
        //��v0���������Ȩֵ���и���
        for (int w=0; w<G.vexnum; w++) {
            if (!final[w]&&(min+G.arcs[k][w]<(*D)[w])) {
                (*D)[w]=min+G.arcs[k][w];
                (*p)[w]=k;//��¼�������·���ϴ��ڵĶ���
            }
        }
    }
}
int main(){
    MGraph G;
    CreateUDG(&G);
    PathMatrix P;
    ShortPathTable D;
    ShortestPath_Dijkstra(G, 0, &P, &D);
    for (int i=1; i<G.vexnum; i++) {
        printf("V%d - V%d�����·���еĶ�����(����)��",0,i);
        printf(" V%d",i);
        int j=i;
        //����ÿһ�����·���϶���¼�ž����Ķ��㣬���Բ���Ƕ�׵ķ�ʽ������ɵõ��������·���ϵ����ж���
        while (P[j]!=0) {
            printf(" V%d",P[j]);
            j=P[j];
        }
        printf(" V0\n");
    }
    printf("Դ�㵽����������·������Ϊ:\n");
    for (int i=1; i<G.vexnum; i++) {
        printf("V%d - V%d : %d \n",G.vexs[0],G.vexs[i],D[i]);
    }
    return 0;
}
