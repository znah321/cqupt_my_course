#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef enum {false,true} bool;

typedef struct line{
    int No;
    struct line * next;
}line;

//���ն�ͽ��������ʼ��ѭ������
void initLine(line ** head,int n){
    *head=(line*)malloc(sizeof(line));
    (*head)->next=NULL;
    (*head)->No=1;
    line * list=*head;
    for (int i=1; i<n; i++) {
        line * body=(line*)malloc(sizeof(line));
        body->next=NULL;
        body->No=i+1;
        list->next=body;
        list=list->next;
    }
    list->next=*head;//������ɻ�
}
//������������еĽ����Ϣ
void display(line * head){
    line * temp=head;
    while (temp->next!=head) {
        printf("%d ",temp->No);
        temp=temp->next;
    }
    printf("%d\n",temp->No);
}

int main() {
    line * head=NULL;
    srand((int)time(0));
    int n,shootNum,round=1;
    printf("�����ͽ������");
    scanf("%d",&n);
    initLine(&head,n);
    line* lineNext=head;//���ڼ�¼ÿ�ֿ�ʼ��λ��
    //����������ֻ����һ�����ʱ����ͷ���ʱ���˳�ѭ��
    while (head->next!=head) {
        printf("�� %d �ֿ�ʼ���ӱ��Ϊ %d ���˿�ʼ��",round,lineNext->No);
        shootNum=rand()%n+1;
        printf("ǹ�ڵ� %d �ο۶����ʱ����\n",shootNum);
        line *temp=lineNext;
        //����ѭ�������ҵ���Ҫɾ��������һ�����
        for (int i=1; i<shootNum-1; i++) {
            temp=temp->next;
        }
        //��Ҫɾ������������ɾ�������ͷ���ռ�ÿռ�
        printf("���Ϊ %d �Ķ�ͽ�˳��Ĳ�,ʣ���ͽ�������Ϊ��\n",temp->next->No);
        line * del=temp->next;
        temp->next=temp->next->next;
        if (del==head) {
            head=head->next;
        }
        free(del);
        display(head);
        //��ֵ��һ�ֿ�ʼ��λ��
        lineNext=temp->next;
        round++;//��¼ѭ������
    }
    printf("����ʤ���Ķ�ͽ����ǣ�%d\n",head->No);
    return 0;
}
