#include <stdio.h>
#include <stdlib.h>
#define VertexType int
#define VRType int
#define MAX_VERtEX_NUM 20
#define InfoType char
#define INFINITY 65535
typedef struct {
    VRType adj;                             //������Ȩͼ���� 1 �� 0 ��ʾ�Ƿ����ڣ����ڴ�Ȩͼ��ֱ��ΪȨֵ��
    InfoType * info;                        //�����⺬�е���Ϣָ��
}ArcCell,AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];

typedef struct {
    VertexType vexs[MAX_VERtEX_NUM];        //�洢ͼ�ж�������
    AdjMatrix arcs;                         //��ά���飬��¼����֮��Ĺ�ϵ
    int vexnum,arcnum;                      //��¼ͼ�Ķ������ͻ����ߣ���
}MGraph;

//���ݶ��㱾�����ݣ��жϳ������ڶ�ά�����е�λ��
int LocateVex(MGraph G,VertexType v){
    int i=0;
    //����һά���飬�ҵ�����v
    for (; i<G.vexnum; i++) {
        if (G.vexs[i]==v) {
            return i;
        }
    }
    return -1;
}
//����������
void CreateUDN(MGraph* G){
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));
    for (int i=0; i<G->vexnum; i++) {
        scanf("%d",&(G->vexs[i]));
    }
    for (int i=0; i<G->vexnum; i++) {
        for (int j=0; j<G->vexnum; j++) {
            G->arcs[i][j].adj=INFINITY;
            G->arcs[i][j].info=NULL;
        }
    }
    for (int i=0; i<G->arcnum; i++) {
        int v1,v2,w;
        scanf("%d,%d,%d",&v1,&v2,&w);
        int m=LocateVex(*G, v1);
        int n=LocateVex(*G, v2);
        if (m==-1 ||n==-1) {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj=w;
        G->arcs[m][n].adj=w;
    }
}

//�������飬����ÿ��ɸѡ��Ȩֵ��С�ıߵ��ڽӵ�
typedef struct {
    VertexType adjvex;//��¼Ȩֵ��С�ıߵ���ʼ��
    VRType lowcost;//��¼�ñߵ�Ȩֵ
}closedge[MAX_VERtEX_NUM];
closedge theclose;//����һ��ȫ�����飬��Ϊÿ�������ж���ʹ�õ�
//�ڸ����������ҳ�Ȩֵ��С�ıߵ������±꣬�Ϳ��Լ���ҵ��˱ߵ��յ㶥�㡣
int minimun(MGraph G,closedge close){
    int min=INFINITY;
    int min_i=-1;
    for (int i=0; i<G.vexnum; i++) {
        //ȨֵΪ0��˵�������Ѿ�������С�������У�Ȼ��ÿ�κ�min�������бȽϣ�����ҳ���С�ġ�
        if (close[i].lowcost>0 && close[i].lowcost < min) {
            min=close[i].lowcost;
            min_i=i;
        }
    }
    //������СȨֵ���ڵ������±�
    return min_i;
}
//����ķ�㷨������GΪ��������uΪ������ѡ������ⶥ����Ϊ��ʼ��
void miniSpanTreePrim(MGraph G,VertexType u){
    //�ҵ�����ʼ���ڶ��������е�λ���±�
    int k=LocateVex(G, u);
    //���Ƚ������ʼ����ص����бߵ���Ϣ���ߵ���ʼ���Ȩֵ�����븨����������Ӧ��λ�ã����磨1��2���ߣ�adjvexΪ0��lowcostΪ6������theclose[1]�У�����������±��ʾ�ñߵĶ���2
    for (int i=0; i<G.vexnum; i++) {
        if (i !=k) {
            theclose[i].adjvex=k;
            theclose[i].lowcost=G.arcs[k][i].adj;
        }
    }
    //������ʼ���Ѿ���Ϊ��С�����������Ը��������Ӧλ�õ�ȨֵΪ0������������ʱ�Ͳ��ᱻѡ��
    theclose[k].lowcost=0;
    //ѡ����һ���㣬�����¸��������е���Ϣ
    for (int i=1; i<G.vexnum; i++) {
        //�ҳ�Ȩֵ��С�ı����������±�
        k=minimun(G, theclose);
        //���ѡ���·��
        printf("v%d v%d\n",G.vexs[theclose[k].adjvex],G.vexs[k]);
        //������С�������Ķ���ĸ��������е�Ȩֵ��Ϊ0
        theclose[k].lowcost=0;
        //��Ϣ���������д洢����Ϣ�����ڴ�ʱ�����¼�����һ�����㣬��Ҫ�жϣ��ɴ˶�����������������������Ȩֵ�Ƿ��֮ǰ��¼��Ȩֵ��ҪС�������С�������
        for (int j=0; j<G.vexnum; j++) {
            if (G.arcs[k][j].adj<theclose[j].lowcost) {
                theclose[j].adjvex=k;
                theclose[j].lowcost=G.arcs[k][j].adj;
            }
        }
    }
    printf("\n");
}

int main(){
    MGraph G;
    CreateUDN(&G);
    miniSpanTreePrim(G, 1);
}
