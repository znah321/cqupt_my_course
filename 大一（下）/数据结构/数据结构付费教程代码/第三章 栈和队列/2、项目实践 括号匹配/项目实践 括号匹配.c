#include <stdio.h>
#include <string.h>
int top=-1;//top����ʱ�̱�ʾջ��Ԫ������λ��
void push(char * a,int elem){
    a[++top]=elem;
}
void pop(char* a){
    if (top==-1) {
        return ;
    }
    top--;
}
char visit(char * a){
    //��ȡջ��Ԫ�أ������ڵ�ջ�����ջΪ�գ�Ϊʹ���򲻷������󣬷��ؿ��ַ�
    if (top!=-1) {
        return a[top];
    }else{
        return ' ';
    }
}
int main() {
    char a[30];
    char bracket[100];
    printf("�������������У�");
    scanf("%s",bracket);
    getchar();
    int length=(int)strlen(bracket);
    for (int i=0; i<length; i++) {
        //����������ţ�ֱ��ѹջ
        if (bracket[i]=='('||bracket[i]=='{') {
            push(a, bracket[i]);
        }else{
            //������ұ����ţ��ж���ջ��Ԫ���Ƿ�ƥ�䣬���ƥ�䣬ջ��Ԫ�ص�ջ������������У����򣬷������Ų�ƥ�䣬������ֱ���˳�
            if (bracket[i]==')') {
                if (visit(a)=='(') {
                    pop(a);
                }else{
                    printf("���Ų�ƥ��");
                    return 0;
                }
            }else{
                if (visit(a)=='{') {
                    pop(a);
                }else{
                    printf("���Ų�ƥ��");
                    return 0;
                }
            }
        }
    }
    //�����������ƥ����ɣ�ջ��Ϊ�գ�˵����������ȫ��ƥ��ɹ�
    if (top!=-1) {
         printf("���Ų�ƥ��");
    }else{
       printf("����ƥ��");
    }
}
