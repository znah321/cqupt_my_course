#include <stdio.h>
#define MAX_VERtEX_NUM 1000              //�����������
#define VRType int                          //��ʾ����Ȩֵ������
#define VertexType char                     //ͼ�ж������������
#define INFINITY 65535
typedef enum{false,true} bool;
typedef struct {
    VertexType vexs[MAX_VERtEX_NUM];        //�洢ͼ�ж�������
    VRType arcs[MAX_VERtEX_NUM][MAX_VERtEX_NUM];                         //��ά���飬��¼����֮��Ĺ�ϵ
    int vexnum,arcnum;                      //��¼ͼ�Ķ������ͻ����ߣ���
}MGraph;
typedef int PathMatrix[MAX_VERtEX_NUM];     //���ڴ洢���·���о����Ķ�����±�
typedef int ShortPathTable[MAX_VERtEX_NUM]; //���ڴ洢�������·����Ȩֵ��

//�Ͻ�˹�����㷨��v0��ʾ����������ʼ�����������е��±�
void ShortestPath_Dijkstra(MGraph G,int v0,PathMatrix *p,ShortPathTable *D){
    int final[MAX_VERtEX_NUM];//���ڴ洢�������Ƿ��Ѿ�ȷ�����·��������
    //�Ը�������г�ʼ��
    for (int v=0; v<G.vexnum; v++) {
        final[v]=0;
        (*D)[v]=G.arcs[v0][v];
        (*p)[v]=0;
    }
    //�����Ϊ�±�Ķ���Ϊ��ʼ�㣬���Բ������ж�
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
        //�Դ���㵽�������Ȩֵ���и���
        for (int w=0; w<G.vexnum; w++) {
            if (!final[w]&&(min+G.arcs[k][w]<(*D)[w])) {
                (*D)[w]=min+G.arcs[k][w];
                (*p)[w]=k;//��¼�������·���ϴ��ڵĶ���
            }
        }
    }
}
//�ڽ���ά����ת��Ϊͼ�Ĺ����У���Ҫ�жϵ�ǰ�ĵ��Ƿ�Խ������Ƿ�Ϊͨ·
bool canUsed(int i,int j,int n,int m,char a[][110]){
    if (a[i][j]!='#' && i>=0 && i<n && j>=0 && j<m) {
        return true;
    }
    return false;
}
int main(){
    char a[110][110];
    int n,m;
    scanf("%d %d",&n,&m);
    getchar();
    MGraph G;
    G.vexnum=0;
    G.arcnum=0;
    //��¼�����ͼ�Ķ��������е�λ���±�
    int start =0;
    //��¼������ͼ�Ķ��������е�λ���±�
    int exit=0;
    //��ʼ����¼ͼ�ıߵĶ�ά���飬��������ߵĳ���Ϊ����󣬼�������֮��û�б�
    for (int i=0; i<n*m; i++) {
        for (int j=0; j<n*m; j++) {
            G.arcs[i][j]=INFINITY;
        }
    }
    //�����ά���飬ͬʱ��¼��ںͳ��ڵ�λ��
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%c",&a[i][j]);
            G.vexs[i*m+j]=a[i][j];
            G.vexnum++;
            if (a[i]
                [j]=='S') {
                start=i*m+j;
            }else if(a[i][j]=='E'){
                exit=i*m+j;
            }
        }
        getchar();//������Ϊ�˶�ȡ�������еĻ��з�����Ϊ�Թ���һ��һ�����뵽�ڴ��еģ�
    }
    //����ά����ת��Ϊ����ͼ����ת��ʱ���Ӷ�ά��������Ͻǿ�ʼ��ÿ���жϵ�ǰ������Ҳ���²��Ƿ�Ϊͨ·���������е�ͨ·�Ϳ���ת��Ϊ����ͼ�еıߡ�
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            //�����жϵ�ǰ���Ƿ�Ϊͨ·
            if (canUsed(i, j, n, m, a)) {
                if (canUsed(i+1, j, n, m, a)) {
                    //�趨������֮��ıߵ�ȨֵΪ 1
                    G.arcs[i*m+j][(i+1)*m+j]=1;
                    G.arcs[(i+1)*m+j][i*m+j]=1;
                    G.arcnum++;
                }
                if (canUsed(i, j+1, n, m, a)) {
                    G.arcs[i*m+j][i*m+j+1]=1;
                    G.arcs[i*m+j+1][i*m+j]=1;
                    G.arcnum++;
                }
            }
        }
    }
    PathMatrix P;
    ShortPathTable D;
    //���еϽ�˹�����㷨
    ShortestPath_Dijkstra(G,start, &P, &D);
    //������ռ�¼��Ȩֵ�ͻ��������֤������ںͳ���֮��û��ͨ·
    if (D[exit]==INFINITY) {
        printf("-1");
    }else{
        printf("��ڵ����ڵ����·������Ϊ:\n");
        printf("%d\n",D[exit]);
        printf("��ڵ����ڵ����·��Ϊ(����):\n");
        printf("(%d,%d) ",exit/m,exit%m);
        while (P[exit]!=0) {
            printf("(%d,%d) ",P[exit]/m,P[exit]%m);
            exit=P[exit];
        }
        printf("(%d,%d)\n",start/m,start%m);
    }
    return 0;
}
