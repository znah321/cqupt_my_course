#include <stdio.h>
#include <stdlib.h>

typedef struct GLNode{
    int tag;//��־��
    union{
        char atom;//ԭ�ӽ���ֵ��
        struct{
            struct GLNode * hp,*tp;
        }ptr;//�ӱ����ָ����hpָ���ͷ��tpָ���β
    };
}*Glist,GNode;

Glist creatGlist(Glist C){
    //�����C
    C=(Glist)malloc(sizeof(GNode));
    C->tag=1;
    //��ͷԭ�ӡ�a��
    C->ptr.hp=(Glist)malloc(sizeof(GNode));
    C->ptr.hp->tag=0;
    C->ptr.hp->atom='a';
    //��β�ӱ�b,c,d��,��һ������
    C->ptr.tp=(Glist)malloc(sizeof(GNode));
    C->ptr.tp->tag=1;
    C->ptr.tp->ptr.hp=(Glist)malloc(sizeof(GNode));
    C->ptr.tp->ptr.tp=NULL;
    //��ʼ�����һ������Ԫ�أ�b,c,d��,��ͷΪ��b������βΪ��c,d��
    C->ptr.tp->ptr.hp->tag=1;
    C->ptr.tp->ptr.hp->ptr.hp=(Glist)malloc(sizeof(GNode));
    C->ptr.tp->ptr.hp->ptr.hp->tag=0;
    C->ptr.tp->ptr.hp->ptr.hp->atom='b';
    C->ptr.tp->ptr.hp->ptr.tp=(Glist)malloc(sizeof(GNode));
    //����ӱ�(c,d)����ͷΪc����βΪd
    C->ptr.tp->ptr.hp->ptr.tp->tag=1;
    C->ptr.tp->ptr.hp->ptr.tp->ptr.hp=(Glist)malloc(sizeof(GNode));
    C->ptr.tp->ptr.hp->ptr.tp->ptr.hp->tag=0;
    C->ptr.tp->ptr.hp->ptr.tp->ptr.hp->atom='c';
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp=(Glist)malloc(sizeof(GNode));
    //��ű�βd
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->tag=1;
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp=(Glist)malloc(sizeof(GNode));
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->tag=0;
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->atom='d';
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.tp=NULL;
    return C;
}
int GlistDepth(Glist C){
    //�����CΪ�ձ�ʱ��ֱ�ӷ��س���1��
    if (!C) {
        return 1;
    }
    //�����CΪԭ��ʱ��ֱ�ӷ���0��
    if (C->tag==0) {
        return 0;
    }
    int max=0;//���ñ�C�ĳ�ʼ����Ϊ0��
    for (Glist pp=C; pp; pp=pp->ptr.tp) {
        int dep=GlistDepth(pp->ptr.hp);
        if (dep>max) {
            max=dep;//ÿ���ҵ����б�����������ı�����max��¼
        }
    }
    //�����������˴�������������ǿձ�����ԭ�ӷ��ص���0����ʵ�ʳ�����1�����ԣ��˴�Ҫ+1��
    return max+1;
}
int main(int argc, const char * argv[]) {
    Glist C=creatGlist(C);
    printf("���������Ϊ��%d",GlistDepth(C));
    return 0;
}
