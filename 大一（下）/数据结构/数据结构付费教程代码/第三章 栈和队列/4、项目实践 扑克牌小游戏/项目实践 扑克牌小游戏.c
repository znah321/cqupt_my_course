#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int data[1000];
    int head;
    int tail;
};
struct stack
{
    int data[10];
    int top;
};
void showCard(struct queue *q,int *book,struct stack *s){
    int t=(*q).data[(*q).head]; //���һ���ƣ����Ӷ��� q �Ķ�ͷȡԪ�أ���ʱ���������ӵ�ջ��ţ�
    //�ж�ȡ�����������Ƿ��Ӯ��
    if(book[t]==0){ //����Ӯ�ƣ�ֻ��ŵ���������ջ����
        (*q).head++;//���ڴ�ʱ���Ѿ���������Զ��еĶ�ͷ��Ҫǰ��
        (*s).top++;
        (*s).data[(*s).top]=t; //�ٰѴ�����Ʒŵ����ϣ�����ջ
        book[t]=1; //������������Ѿ�������Ϊt����
    }
    else{
        (*q).head++;//���ڴ�ʱ�Ѿ����ȥһ���ƣ����Զ�ͷ��Ҫ +1
        (*q).data[(*q).tail]=t;//��������Ʒŵ������Ƶ��������ӣ�
        (*q).tail++;
        //��������Ӯ�õ������ηŵ������Ƶ�������γ�ջ������еĹ��̣�
        while((*s).data[(*s).top]!=t){
            book[(*s).data[(*s).top]]=0;//ȡ���Ը��ƺŵı��
            (*q).data[(*q).tail]=(*s).data[(*s).top];//���η����β
            (*q).tail++;
            (*s).top--;
        }
        //�������˽����һ����ȵ���ȡ���������
        book[(*s).data[(*s).top]]=0;
        (*q).data[(*q).tail]=(*s).data[(*s).top];
        (*q).tail++;
        (*s).top--;
    }
}

int main()
{
    struct queue q1,q2;//�������У��ֱ�ģ�������ˣ�����ֱ�ΪС����С��
    struct stack s;//ջ��ģ������
    int book[14];//Ϊ�˱����ж������ϵ����Ƿ�����ͬ�ģ�����һ�����������ж�
    int i;
    //��ʼ������
    q1.head=0; q1.tail=0;
    q2.head=0; q2.tail=0;
    //��ʼ��ջ
    s.top=-1;
    //��ʼ��������ǵ�����
    for(i=0;i<=13;i++)
        book[i]=0;
    //�������ÿ�������н��� 6 ���ƣ�ÿ����ӵ�е��ƶ�������ģ������� 1-13 ֮��
    for(i=1;i<=6;i++){
        q1.data[q1.tail]=rand()%13+1;
        q1.tail++;
    }
    for(i=1;i<=6;i++){
        q2.data[q2.tail]=rand()%13+1;
        q2.tail++;
    }
    //��������һ����û����ʱ����Ϸ����
    while(q1.head<q1.tail && q2.head<q2.tail ){         showCard(&q2, book, &s);//С�����
        showCard(&q1, book, &s);//С������
    }
    //��Ϸ����ʱ���������Ӯ���Լ�����ʣ�������
    if(q2.head==q2.tail){
        printf("С��Ӯ\n");
        printf("���л��У�%d ����",q1.tail-q1.head);
    }
    else{
        printf("С��Ӯ\n");
        printf("���л��У�%d ����",q2.tail-q2.head);
    }
    return 0;
}
