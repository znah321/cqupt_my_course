#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct gambler{
    int number;
}gambler;

int main(){
    int n;
    int round=1;
    int location=1;
    int shootNum;
    int i,j;
    srand((int)time(0));//���û������������ӣ��̶����룬û����䣬������ǹ̶�����ģ�
    printf("�����ͽ��������");
    scanf("%d",&n);
    printf("����ͽ���α��Ϊ 1-%d\n",n);
    gambler gamblers[n+1];//�洢��ͽ��ŵ�����
    for (i=1;i<=n; i++) {//����Ϊ�μ��߷�����
        gamblers[i].number=i;
    }
    //��ֻʣ��һ����ʱ���˳�����
    while (n!=1) {
        printf("�� %d �ֿ�ʼ���ӱ��Ϊ %d ���˿�ʼ��",round,gamblers[location].number);
        shootNum=rand()%6+1;
        printf("ǹ�ڵ� %d �ο۶����ʱ����\n",shootNum);
        for (i=location; i<location+shootNum; i++);//�ҵ�ÿ���˳����˵�λ�ã�i-1 ���ǣ��˴���õ�iֵΪ��һ�ֿ�ʼ��λ�ã�
        i=i%n;//���ڲ������ųɵ��ǻ���������Ҫ����� i ֵ����ȡ�ദ��
        if (i==1 || i==0) {//�� i=1����i=0ʱ��ʵ����ָ����λ�����鿪ͷ�ͽ�β�Ĳ����ߣ���Ҫ���µ��� i ��ֵ
            i=n+i;
        }
        printf("���Ϊ %d �Ķ�ͽ�˳��Ĳ�,ʣ���ͽ�������Ϊ��\n",gamblers[i-1].number);
        //ʹ��˳��洢ʱ�����ɾ��Ԫ�أ���Ҫ�������λ�õ�Ԫ�ؽ���ȫ��ǰ��
        for (j=i-1; j+1<=n; j++) {
            gamblers[j]=gamblers[j+1];
        }
        n--;//��ʱ���������� n ���˱�Ϊ n-1 ����
        for (int k=1; k<=n; k++) {
            printf("%d ",gamblers[k].number);
        }
        printf("\n");
        location=i-1;//location��ʾ������һ�ֿ�ʼ��λ��
        //ͬ��ע��locationֵ�ķ�Χ
        if (location>n) {
            location%=n;
        }
        round++;
    }
    printf("����ʤ���Ķ�ͽ����ǣ�%d\n",gamblers[1].number);
}
