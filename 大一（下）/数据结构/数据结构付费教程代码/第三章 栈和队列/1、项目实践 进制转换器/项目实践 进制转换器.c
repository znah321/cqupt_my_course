#include <stdio.h>
#include <string.h>
#include <math.h>
int top=-1;//top����ʱ�̱�ʾջ��Ԫ������λ��
void push(char * a,char elem){
    a[++top]=elem;
}
void pop(char * a){
    if (top==-1) {
        return ;
    }
    //���ʱҪ������ȷ�ĸ�ʽ��ʾ���û�
    if (a[top]>=10) {
        printf("%c",a[top]+55);
    }else{
        printf("%d",a[top]);
    }
    top--;
}
//����������ת����ʮ������
int scaleFun(char * data,int system){
    int k=(int)strlen(data)-1;
    int system_10_data=0;
    int i;
    for (i=k; i>=0; i--) {
        int temp;
        if (data[i]>=48 && data[i]<=57) {
            temp=data[i]-48;
        }else{
            temp=data[i]-55;
        }
        system_10_data+=temp*pow(system, k-i);
    }
    return system_10_data;
}
int main() {
    char data[100];
    printf("����ת������������ԭ���ݵĽ��ƣ�2-36��:");
    int system;
    scanf("%d",&system);
    getchar();
    printf("������Ҫת�������ݣ�");
    scanf("%s",data);
    getchar();
    int system_10_data=scaleFun(data, system);
    printf("������ת��������ݵĽ��ƣ�");
    int newSystem;
    scanf("%d",&newSystem);
    getchar();
    while (system_10_data/newSystem) {
        push(data,system_10_data%newSystem );
        system_10_data/=newSystem;
    }
    push(data,system_10_data%newSystem);
    printf("ת����Ľ��Ϊ��\n");
    while (top!=-1) {
        pop(data);
    }
}
