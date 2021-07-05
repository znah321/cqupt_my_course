#include <stdio.h>
#include <stdlib.h>
#define TElemType char//�궨�壬����������������
//ö�٣�LinkΪ0��ThreadΪ1
typedef enum {
    Link,
    Thread
}PointerTag;
//���ṹ����
typedef struct BiThrNode{
    TElemType data;//������
    struct BiThrNode* lchild,*rchild;//���ӣ��Һ���ָ����
    PointerTag Ltag,Rtag;//��־��ö������
}BiThrNode,*BiThrTree;

BiThrTree pre=NULL;

//����ǰ���ʼ��������
//����ͺ���ֻ��ı丳ֵ����λ�ü���
void CreateTree(BiThrTree * tree){
    char data;
    scanf("%c",&data);
    if (data!='#'){
        if (!((*tree)=(BiThrNode*)malloc(sizeof(BiThrNode)))){
            printf("������ռ�ʧ��");
            return;
        }else{
            (*tree)->data=data;//����ǰ�������ʽ��ʼ��������
            CreateTree(&((*tree)->lchild));//��ʼ��������
            CreateTree(&((*tree)->rchild));//��ʼ��������
        }
    }else{
        *tree=NULL;
    }
}
//����Զ���������������
void InThreading(BiThrTree p){
    //�����ǰ������
    if (p) {
        InThreading(p->lchild);//�ݹ鵱ǰ����������������������
        //�����ǰ���û�����ӣ����־λ��Ϊ1����ָ����ָ����һ��� pre
        if (!p->lchild) {
            p->Ltag=Thread;
            p->lchild=pre;
        }
        //��� pre û���Һ��ӣ��ұ�־λ��Ϊ 1����ָ����ָ��ǰ��㡣
        if (pre&&!pre->rchild) {
            pre->Rtag=Thread;
            pre->rchild=p;
        }
        pre=p;//preָ��ǰ���
        InThreading(p->rchild);//�ݹ�����������������
    }
}
//����˫����������
void InOrderThread_Head(BiThrTree *h, BiThrTree t)
{
    //��ʼ��ͷ���
    (*h) = (BiThrTree)malloc(sizeof(BiThrNode));
    if((*h) == NULL){
        printf("�����ڴ�ʧ��");
        return ;
    }
    (*h)->rchild = *h;
    (*h)->Rtag = Link;
    //����������ǿ���
    if(!t){
        (*h)->lchild = *h;
        (*h)->Ltag = Link;
    }
    else{
        pre = *h;//preָ��ͷ���
        (*h)->lchild = t;//ͷ���������Ϊ�������
        (*h)->Ltag = Link;
        InThreading(t);//��������������pre�����Ϊȫ�ֱ�����������������pre���ָ���������������һ�����
        pre->rchild = *h;
        pre->Rtag = Thread;
        (*h)->rchild = pre;
    }
}
//�����������˫������������
void InOrderThraverse_Thr(BiThrTree h)
{
    BiThrTree p;
    p = h->lchild;           //pָ������
    while(p != h)
    {
        while(p->Ltag == Link)   //��ltag = 0ʱѭ�����������еĵ�һ�����
        {
            p = p->lchild;
        }
        printf("%c ", p->data);  //��ʾ������ݣ����Ը���Ϊ�����Խ��Ĳ���
        while(p->Rtag == Thread && p->rchild != h)
        {
            p = p->rchild;
            printf("%c ", p->data);
        }

        p = p->rchild;           //p������������
    }
}
int main() {
    BiThrTree t;
    BiThrTree h;
    printf("����ǰ�������:\n");
    CreateTree(&t);
    InOrderThread_Head(&h, t);
    printf("�����������:\n");
    InOrderThraverse_Thr(h);
    return 0;
}
