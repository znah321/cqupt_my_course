typedef int KeyType;//����ؼ�������
typedef struct{
    KeyType key;
}ElemType;//����Ԫ������
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//�������
int i;
int min;
int dw;
//�������Ų�������R����Ϊ���ұ�sw����Ϊ�洢�ĸ��ؼ��ֵĸ��ʣ�Ȩֵ����low��high��ʾ��sw�����е�Ȩֵ�ķ�Χ
void SecondOptimal(BiTree T, ElemType R[], float sw[], int low, int high){
    //�������R[low...high]�����ۼ�Ȩֵ��sw������sw[0]==0���ݹ鹹����Ų�����
    i = low;
    min = abs(sw[high] - sw[low]);
    dw = sw[high] + sw[low - 1];
    //ѡ����С�ġ�Piֵ
    for (int j = low+1; j <=high; j++){
        if (abs(dw-sw[j]-sw[j-1])<min){
            i = j;
            min = abs(dw - sw[j] - sw[j - 1]);
        }
    }

    T = (BiTree)malloc(sizeof(BiTNode));
    T->data = R[i];//���ɽ�㣨��һ�����ɸ���
    if (i == low) T->lchild = NULL;//��������
    else SecondOptimal(T->lchild, R, sw, low, i - 1);//����������
    if (i == high) T->rchild = NULL;//��������
    else SecondOptimal(T->rchild, R, sw, i + 1, high);//����������

}
