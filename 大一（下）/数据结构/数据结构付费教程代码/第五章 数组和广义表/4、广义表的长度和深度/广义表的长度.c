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
}*Glist;
Glist creatGlist(Glist C){
    //�����C
    C=(Glist)malloc(sizeof(Glist));
    C->tag=1;
    //��ͷԭ�ӡ�a��
    C->ptr.hp=(Glist)malloc(sizeof(Glist));
    C->ptr.hp->tag=0;
    C->ptr.hp->atom='a';
    //��β�ӱ�b,c,d��,��һ������
    C->ptr.tp=(Glist)malloc(sizeof(Glist));
    C->ptr.tp->tag=1;
    C->ptr.tp->ptr.hp=(Glist)malloc(sizeof(Glist));
    C->ptr.tp->ptr.tp=NULL;
    //��ʼ�����һ������Ԫ�أ�b,c,d��,��ͷΪ��b������βΪ��c,d��
    C->ptr.tp->ptr.hp->tag=1;
    C->ptr.tp->ptr.hp->ptr.hp=(Glist)malloc(sizeof(Glist));
    C->ptr.tp->ptr.hp->ptr.hp->tag=0;
    C->ptr.tp->ptr.hp->ptr.hp->atom='b';
    C->ptr.tp->ptr.hp->ptr.tp=(Glist)malloc(sizeof(Glist));
    //����ӱ�(c,d)����ͷΪc����βΪd
    C->ptr.tp->ptr.hp->ptr.tp->tag=1;
    C->ptr.tp->ptr.hp->ptr.tp->ptr.hp=(Glist)malloc(sizeof(Glist));
    C->ptr.tp->ptr.hp->ptr.tp->ptr.hp->tag=0;
    C->ptr.tp->ptr.hp->ptr.tp->ptr.hp->atom='c';
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp=(Glist)malloc(sizeof(Glist));
    //��ű�βd
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->tag=1;
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp=(Glist)malloc(sizeof(Glist));
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->tag=0;
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->atom='d';
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.tp=NULL;
    return C;
}
int GlistLength(Glist C){
    int Number=0;
    Glist P=C;
    while(P){
        Number++;
        P=P->ptr.tp;
    }
    return Number;
}
int main(){
    Glist C = creatGlist(C);
    printf("�����ĳ���Ϊ��%d",GlistLength(C));
    return 0;
}
