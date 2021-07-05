#include <stdio.h>
#define MAX 3//ģ��ͣ��������ͣ�ĳ�����
//���ı�Ҫ��Ϣ�Ľṹ��
typedef struct{
    int number;
    int arrive_time;
}zanInode;
//����ͣ�����Ĵ�����
int push(zanInode * park,int *parktop,zanInode car){
    //���ͣ�����������ó���������ȴ����ȷ��� -1 �����������д���
    if ((*parktop)>=MAX) {
        printf("ͣ������ͣ������ͣ�������.\n");
        return -1;
    }else{//���򽫸ó���ջ��ͬʱ�������
        park[(*parktop)]=car;
        printf("�ó���ͣ�����ĵ� %d ��λ����\n",(*parktop)+1);
        (*parktop)++;
        return 1;
    }
}
//����ͣ�������˳��Ĵ�����
zanInode pop(zanInode *park,int *parktop,int carnumber,zanInode * location,int *locationtop){
    int i;
    //���ں�������ķ���ֵ��Ҫ����һ������������Ҫ�ȳ�ʼ��һ��
    zanInode thecar;
    thecar.number=-1;
    thecar.arrive_time=-1;
    //��ͣ�������ҵ�Ҫ��ȥ�ĳ�
    for (i=-1; i<(*parktop); i++) {
        if (park[i].number==carnumber) {
            break;
        }
    }
    //������������һ��������û���ҵ���֤��ͣ������û��������
    if (i==(*parktop)) {
        printf("ͣ������û�иó�\n");
    }else{//�ͽ��ó��Ƴ�ͣ����
        //���Ƚ��ڸó������ͣ�����ĳ�ȫ��Ų����һ��ջ��
        while ((*parktop)>i+1) {
            (*parktop)--;
            location[*locationtop]=park[*parktop];
            (*locationtop)++;
        }
        //ͨ�����ϵ�ѭ���������ϸó�������ҳ���ȫ���ƿ����������ڸó�ҲҪ��ջ������ջ��ָ����Ҫ����һ��λ�ã�������ջʱ����ֱ�Ӹ��ǵ���
        (*parktop)--;
        thecar=park[*parktop];
        //�ó���ջ�󣬻�Ҫ��֮ǰ��ջ�����г�����ȫ����ջ
        while ((*locationtop)>0) {
            (*locationtop)--;
            park[*parktop]=location[*locationtop];
            (*parktop)++;
        }
    }
    return thecar;
}

int main(int argc, const char * argv[]) {
    //ͣ������ջ
    zanInode park[MAX];
    int parktop=0;//ջ��ָ��

    //����ͣ��������Ų����ջ
    zanInode location[MAX];
    int locationtop=0;//ջ��ָ��

    //ģ�����Ķ���
    zanInode accessroad[100];
    int front,rear;//��ͷ�Ͷ�βָ��
    front=rear=0;
    char order;//����ͣ��������������
    int carNumber;//���ƺ�
    int arriveTime;//��ͣ������ʱ��
    int leaveTime;//�뿪ͣ������ʱ��
    int time;//����ͣ�����ж�����ʱ��

    zanInode car;
    printf("�г�������ͣ������A��;�г�����ͣ����(D);����ֹͣ��#��:\n");
    while (scanf("%c",&order)) {
        if (order=='#') {
            break;
        }
        switch (order) {
            case 'A':
                printf("�Ǽǳ��ƺ�(���ƺŲ���Ϊ -1)����������ʱ�䣨��СʱΪ׼����\n");
                scanf("%d %d",&carNumber,&arriveTime);
                car.number=carNumber;
                car.arrive_time=arriveTime;
                //���г���Ҫ����ͣ����ʱ��������ͼ���ó�����ͣ����
                int result=push(park, &parktop, car);
                //�������ֵΪ -1 ��֤��ͣ������������Ҫͣ�ڱ����
                if (result==-1) {//ͣ�ڱ����
                    accessroad[rear]=car;
                    printf("�ó��ڱ���ĵ� %d ��λ����\n",rear+1-front);
                    rear++;
                }
                break;
            case 'D':
                printf("��ͣ�����ĳ��ĳ��ƺ��Լ��뿪��ʱ�䣺\n");
                scanf("%d %d",&carNumber,&leaveTime);
                //���г���Ҫ��ͣ����ʱ�����ó�ջ����
                car=pop(park, &parktop, carNumber, location, &locationtop);
                //������صĳ��ĳ��ƺ�Ϊ-1 ��������ͣ������û�в��ҵ�Ҫ���ҵĳ�
                if (car.number!=-1) {
                    //ͣ��ʱ�䣬���ڽ�ͣ������ʱ��-
                    time=leaveTime-car.arrive_time;
                    printf("�ó�ͣ����ʱ��Ϊ��%d Сʱ,Ӧ�ɷ���Ϊ��%f Ԫ\n",time,time*1.5);
                    //һ���г��뿪ͣ���������ڱ�����ȵȴ��ĳ��Ϳ��Խ��룬����ʱ���趨�������ʱ��
                    if (front!=rear) {
                        car=accessroad[front];
                        printf("�ڱ���ϵ�1��λ���ϣ����ƺ�Ϊ��%d �ĳ���ͣ������ʱ��Ϊ��\n",car.number);
                        scanf("%d",&car.arrive_time);
                        park[parktop]=car;
                        front++;
                        parktop++;
                    }else{
                        printf("�����û�еȴ�������ͣ����������\n");
                    }
                }
                break;
            default:
                break;
        }
        printf("\n�г�������ͣ������A��;�г�����ͣ����(D);����ֹͣ��#��:\n");
        scanf("%*[^\n]"); scanf("%*c");//��ջ�����
    }
    return 0;
}
