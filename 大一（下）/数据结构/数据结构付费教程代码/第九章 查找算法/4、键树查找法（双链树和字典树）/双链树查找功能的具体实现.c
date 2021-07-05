#include <stdio.h>
typedef enum{LEFT,BRANCH}NodeKind;//����������ͣ���Ҷ�ӽ�㻹���������͵Ľ��
typedef  struct {
    char a[20];//�洢�ؼ��ֵ�����
    int num;//�ؼ��ֳ���
}KeysType;
//��ʱ���ṹ
typedef struct DLTNode{
    char symbol;//����д洢������
    struct DLTNode *next;//ָ���ֵܽ���ָ��
    NodeKind *kind;//�������
    union{//��������ָ������ÿ������ѡһ
        struct DLTNode* first;//���ӽ��
        struct DLTNode* infoptr;//Ҷ�ӽ�����е�ָ��
    };
}*DLTree;
//���Һ�����������ҳɹ������ظùؼ��ֵ��׵�ַ�����򷵻�NULL��T Ϊ�ú����ֵܱ�ʾ����ʾ�ļ�����KΪ�����ҵĹؼ��֡�
DLTree SearchChar(DLTree T, KeysType k){
    int i = 0;
    DLTree p = T->first;//������ָ�� P ָ�������µĺ������ݵĺ��ӽ��
    //��� p ָ����ڣ��ҹؼ����бȶԵ�λ��С����λ��ʱ���ͼ����ȶ�
    while (p && i < k.num){
        //����ȶԳɹ�����ʼ��һλ�ıȶ�
        if (k.a[i] == p->symbol){
            i++;
            p = p->first;
        }
        //�����λ�ȶ�ʧ�ܣ����Ҹý����ֵܽ������ȶ�
        else{
            p = p->next;
        }
    }
    //�ȶ���ɺ�����ȶԳɹ������� p ָ���ָ��ùؼ��ֵ�Ҷ�ӽ�� $��ͨ�������е� infoptr ָ���ҵ��ùؼ��֡�
    if ( i == k.num){
        return p->infoptr;
    }
    else{
        return NULL;
    }
}
