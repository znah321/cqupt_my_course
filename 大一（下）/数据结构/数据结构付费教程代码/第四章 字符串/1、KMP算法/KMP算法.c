#include <stdio.h>
#include <string.h>
void Next(char*T,int *next){
    int i=1;
    next[1]=0;
    int j=0;
    while (i<strlen(T)) {
        if (j==0||T[i-1]==T[j-1]) {
            i++;
            j++;
            next[i]=j;
        }else{
            j=next[j];
        }
    }
}
int KMP(char * S,char * T){
    int next[10];
    Next(T,next);//����ģʽ��T,��ʼ��next����
    int i=1;
    int j=1;
    while (i<=strlen(S)&&j<=strlen(T)) {
        //j==0:����ģʽ���ĵ�һ���ַ��ͺ͵�ǰ���Ե��ַ�����ȣ�S[i-1]==T[j-1],�����Ӧλ���ַ���ȣ���������£�ָ��ǰ���Ե�����ָ���±�i��j�������
        if (j==0 || S[i-1]==T[j-1]) {
            i++;
            j++;
        }
        else{
            j=next[j];//������Ե������ַ�����ȣ�i������j��Ϊ��ǰ�����ַ�����nextֵ
        }
    }
    if (j>strlen(T)) {//�������Ϊ�棬˵��ƥ��ɹ�
        return i-(int)strlen(T);
    }
    return -1;
}
int main() {
    int i=KMP("ababcabcacbab","abcac");
    printf("%d",i);
    return 0;
}
