#include <stdio.h>
#include <stdlib.h>
typedef struct line{
    struct line * prior;
    int data;
    struct line * next;
}line;

line* initLine(line * head);
void display(line * head);
int main() {
    line * head=NULL;
    head=initLine(head);
    display(head);
    return 0;
}
//����˫��ѭ������
line* initLine(line * head){
    head=(line*)malloc(sizeof(line));
    head->prior=NULL;
    head->next=NULL;
    head->data=1;
    line * list=head;
    for (int i=2; i<=3; i++) {
        line * body=(line*)malloc(sizeof(line));
        body->prior=NULL;
        body->next=NULL;
        body->data=i;

        list->next=body;
        body->prior=list;
        list=list->next;
    }
    //ͨ�����ϴ��룬�Ѿ�������˫���������������������β�ڵ����˫������
    list->next=head;
    head->prior=list;
    return head;
}

//�������Ĺ��ܺ���
void display(line * head){
    line * temp=head;
    //������ѭ���������Ե�����ָ��tempָ�����һ���ڵ���headʱ��֤����ʱ�Ѿ�ѭ������������һ���ڵ�
    while (temp->next!=head) {
        if (temp->next==NULL) {
            printf("%d\n",temp->data);
        }else{
            printf("%d->",temp->data);
        }
        temp=temp->next;
    }
    //���ѭ�����������һ���ڵ��ֵ
    printf("%d",temp->data);
}
