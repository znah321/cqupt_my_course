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

typedef int PathMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];     //���ڴ洢���·���о����Ķ�����±�
typedef int ShortPathTable[MAX_VERtEX_NUM][MAX_VERtEX_NUM]; //���ڴ洢�������·����Ȩֵ��

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
//���������㷨������P��ά�����Ÿ��Զ�������·�������Ķ��㣬D��ά����洢��������֮���Ȩֵ
void ShortestPath_Floyed(MGraph G,PathMatrix *P,ShortPathTable *D){
    //��P�����D������г�ʼ��
    for (int v=0; v<G.vexnum; v++) {
        for (int w=0; w<G.vexnum; w++) {
            (*D)[v][w]=G.arcs[v][w];
            (*P)[v][w]=-1;
        }
    }
    //�ó�ÿ��������Ϊ��������
    for (int k=0; k<G.vexnum; k++) {
        //���ڵ�k��������˵���������������������㣬�жϼ�ӵľ����Ƿ����
        for (int v=0; v<G.vexnum; v++) {
            for (int w=0; w<G.vexnum; w++) {
                //�жϾ�������k�ľ����Ƿ���̣�����жϳ�������洢������̵�·��
                if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w]) {
                    (*D)[v][w]=(*D)[v][k] + (*D)[k][w];
                    (*P)[v][w]=k;
                }
            }
        }
    }
}
int main(){
    MGraph G;
    CreateUDG(&G);
    PathMatrix P;
    ShortPathTable D;
    ShortestPath_Floyed(G, &P, &D);
    for (int i=0; i<G.vexnum; i++) {
        for (int j=0; j<G.vexnum; j++) {
            printf("%d ",P[i][j]);
        }
        printf("\n");
    }
    for (int i=0; i<G.vexnum; i++) {
        for (int j=0; j<G.vexnum; j++) {
            printf("%d ",D[i][j]);
        }
        printf("\n");
    }
    return 0;
}
