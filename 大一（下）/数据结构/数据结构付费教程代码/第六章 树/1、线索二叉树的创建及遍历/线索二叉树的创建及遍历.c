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
//�����������������
void InOrderThraverse_Thr(BiThrTree p)
{
    while(p)
    {
        //һֱ�����ӣ����һ��Ϊ�����������ŵ�һ��
        while(p->Ltag == Link){
            p = p->lchild;
        }
        printf("%c ", p->data);  //�����������
        //������ұ�־λΪ1ʱ��ֱ���ҵ����̽��
        while(p->Rtag == Thread && p->rchild !=NULL)
        {
            p = p->rchild;
            printf("%c ", p->data);
        }
        //���򣬰�����������Ĺ��ɣ������������������µĽ�㣬Ҳ���Ǽ���ѭ������
        p = p->rchild;
    }
}

int main() {
    BiThrTree t;
    printf("����ǰ�������:\n");
    CreateTree(&t);
    InThreading(t);
    printf("�����������:\n");
    InOrderThraverse_Thr(t);
    return 0;
}
