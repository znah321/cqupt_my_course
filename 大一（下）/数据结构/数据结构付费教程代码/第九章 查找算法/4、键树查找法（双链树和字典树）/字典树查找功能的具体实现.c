typedef enum{LEFT,BRANCH}NodeKind;//����������
typedef struct {//����洢�ؼ��ֵ�����
    char a[20];
    int num;
}KeysType;
//������ṹ
typedef struct TrieNode{
    NodeKind kind;//�������
    union{
        struct { KeysType k; struct TrieNode *infoptr; }lf;//Ҷ�ӽ��
        struct{ struct TrieNode *ptr[27]; int num; }bh;//��֧���
    };
}*TrieTree;
//���ַ� a ����ĸ���е�λ��
int ord(char  a){
    int b = a - 'A'+1;
    return b;
}
//���Һ���
TrieTree SearchTrie(TrieTree T, KeysType K){
    int i=0;
    TrieTree p = T;
    while (i < K.num){
        if (p && p->kind==BRANCH && p->bh.ptr[ord(K.a[i])]){
            i++;
            p = p->bh.ptr[ord(K.a[i])];
        }
        else{
            break;
        }
    }
    if (p){
        return p->lf.infoptr;
    }
    return p;
}
