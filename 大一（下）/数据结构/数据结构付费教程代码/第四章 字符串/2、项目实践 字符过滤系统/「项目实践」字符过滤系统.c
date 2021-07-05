#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000
//KMP�㷨�е�next����
void Next(char*T,int *next){
    int i=1;
    next[1]=0;
    int j=0;
    while (i<strlen(T)) {
        if (j==0||T[i-1]==T[j-1]) {
            i++;
            j++;
            if (T[i-1]!=T[j-1]) {
                next[i]=j;
            }
            else{
                next[i]=next[j];
            }
        }else{
            j=next[j];
        }
    }
}
//KMP�㷨(����ģʽƥ��)ʵ�ֺ���
void KMP(char * S,char * T,int (*a)[],int *number){
    int next[10];
    Next(T,next);//����ģʽ��T,��ʼ��next����
    int i=1;
    int j=1;
    *number=0;
    while (i<=strlen(S)) {
        if (j==0 || S[i-1]==T[j-1]) {
            i++;
            j++;
        }else{
            j=next[j];
        }
        if (j>strlen(T)) {
            (*number)++;
            (*a)[(*number)]=i-(int)strlen(T);
            j=0;
            i--;
        }
    }
}
//�ַ����滻�㷨��oldData��ԭ�ַ�����selectDataҪ�滻�����ַ��������� a �洢�������滻�ַ���ԭ�ַ����е��׵�ַ��number��ʾ���� a �ĳ��ȣ�newData���ڴ洢���ַ�����replaceΪ�滻�����ַ�
void replaceData(char * oldData,int *a,int number,char *replace,char * selectData,char * newData){
    int order=0;//��ʾnewData�洢�ַ���λ��
    int begin=0;
    for (int i=1; i<=number; i++) {
        //�Ƚ��滻λ��֮ǰ���ַ������ĸ��Ƶ����ַ���������
        for (int j=begin; j<a[i]-1; j++) {
            newData[order]=oldData[j];
            order++;
        }
        //�滻�ַ��������ַ�����
        for (int k=0;k<strlen(replace);k++) {
            newData[order]=replace[k];
            order++;
        }
        //������ɺ󣬼����ԭ�ַ����и������ַ�������һ����ʼλ��
        begin=a[i]+(int)strlen(selectData)-1;
    }
    //Ҫ�滻λ��ȫ���滻��ɺ󣬼���Ƿ��к����ַ�������ֱ�Ӹ���
    while(begin<strlen(oldData)) {
        newData[order]=oldData[begin];
        order++;
        begin++;
    }
}
int main() {
    while (1) {
        printf("�ַ����˼��ϵͳ����(S),�ر�(O)����ѡ��\n");
        char s;
        char oldData[SIZE];
        char selectData[SIZE];
        char replace[SIZE];
        char judge;
        char *newData=(char*)malloc(SIZE*sizeof(char));
        FILE * out;
        scanf("%c",&s);
        getchar();
        if (s=='O') {
            break;
        }else{
            printf("������ԭ�ַ�����\n");
            scanf("%[^\n]",oldData);
            getchar();//���ڳнӻ�������Ļ��з�
            printf("����Ҫ���ҵ��ַ����ַ�����\n");
            while (scanf("%s",selectData)) {
                getchar();
                int a[SIZE],number;
                KMP(oldData,selectData,&a,&number);
                if (number==0){
                    printf("δ��⵽�������и��ַ������Ƿ���������(Y/N)��\n");
                    scanf("%c",&judge);
                    getchar();
                    if (judge=='N') {
                        break;
                    }else{
                        printf("����Ҫ���ҵ��ַ����ַ�����\n");
                    }
                }else{
                    printf("ϵͳ��⵽���ַ���ԭ�ַ����г��� %d �Σ���ʼλ�������ǣ�\n",number);
                    for (int i=1; i<=number; i++) {
                        printf("%d ",a[i]);
                    }
                    printf("\n");
                    printf("�Ƿ�ʹ�����ַ����滻���е� %s(Y/N)\n",selectData);
                    scanf("%c",&judge);
                    getchar();
                    if (judge=='Y') {
                        printf("�����������滻���ַ�����\n");
                        scanf("%[^\n]",replace);
                        getchar();
                        replaceData(oldData,a,number,replace,selectData,newData);
                        printf("�����ɵ��ַ���Ϊ: %s\n",newData);
                        if((out=fopen("new.txt", "wr"))==NULL){
                            printf("�����ɵ��ַ���Ϊ%s��д���ļ�ʧ��",newData);
                        }
                        if(fputs(newData, out)){
                            printf("�ѽ����ַ���д��new.txt�ļ���\n");
                        }
                        free(newData);
                        fclose(out);
                    }
                    break;
                }
            }
        }
    }
    return 0;
}
