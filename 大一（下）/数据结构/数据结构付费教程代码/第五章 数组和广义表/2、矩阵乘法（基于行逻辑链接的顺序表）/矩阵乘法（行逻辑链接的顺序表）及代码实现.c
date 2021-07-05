#include <stdio.h>
#define MAXSIZE 12500
#define MAXRC 100
#define      ElemType int
typedef struct
{
    int i,j;//�У���
    ElemType e;//Ԫ��ֵ
}Triple;

typedef struct
{
    Triple  data[MAXSIZE+1];
    int rpos[MAXRC+1];//ÿ�е�һ������Ԫ����data�����е�λ��
    int mu,nu,tu;//������������Ԫ�ظ���
}RLSMatrix;

RLSMatrix MultSMatrix(RLSMatrix A, RLSMatrix B, RLSMatrix C)
{
    //�������A�����������B���������ȣ����������������
    if(A.nu != B.mu)
        return C;
    C.mu = A.mu;
    C.nu = B.nu;
    C.tu = 0;
    //���������������Ԫ�ظ���Ϊ�㣬���˷�Ԫ��û�����壬ȫ��0
    if(A.tu * B.tu == 0)
        return C;
    else
    {
        int arow;
        int ccol;
        //��������A��ÿһ��
        for(arow=1; arow<=A.mu; arow++)
        {
            //����һ����ʱ�洢�˻���������飬�ҳ�ʼ��Ϊ0������ÿ�ζ���Ҫ���
            int ctemp[MAXRC+1] ={};
            C.rpos[arow] = C.tu + 1;
            //��������������Ԫ������ҵ��������еķ�0Ԫ�ص�λ��
            int tp;
            if(arow < A.mu)
                tp = A.rpos[arow+1];//��ȡ����A����һ�е�һ������Ԫ����data������λ��
            else
                tp = A.tu+1;//����ǰ�������һ�У���ȡ���һ��Ԫ��+1

            int p;
            int brow;
            //������ǰ�е����еķ�0Ԫ��
            for(p=A.rpos[arow]; p<tp; p++)
            {
                brow = A.data[p].j;//ȡ�÷�0Ԫ�ص�����������ȥB���Ҷ�Ӧ�����˻��ķ�0Ԫ��
                int t;
                // �ж��������A�з�0Ԫ�أ��ҵ�����B�����˷�����һ���е����еķ�0Ԫ��
                if(brow < B.mu)
                    t = B.rpos[brow+1];
                else
                    t = B.tu+1;
                int q;
                //�����ҵ��Ķ�Ӧ�ķ�0Ԫ�أ���ʼ���˻�����
                for(q=B.rpos[brow]; q<t; q++)
                {
                    //�õ��ĳ˻������ÿ�κ�ctemp��������Ӧλ�õ���ֵ���Ӻ�����
                    ccol = B.data[q].j;
                    ctemp[ccol] += A.data[p].e * B.data[q].e;
                }
            }
            //����C���������ھ���A���������������ھ���B�����������ԣ��õ���ctemp�洢�Ľ����Ҳ����C�������ķ�Χ��
            for(ccol=1; ccol<=C.nu; ccol++)
            {
                //���ڽ��������0����0����Ҫ�洢��������������Ҫ�ж�
                if(ctemp[ccol])
                {
                    //��Ϊ0�����¼�����з�0Ԫ�صĸ����ı���tuҪ+1���Ҹ�ֵ���ܳ��������Ԫ������Ŀռ��С
                    if(++C.tu > MAXSIZE)
                        return C;
                    else{
                        C.data[C.tu].e = ctemp[ccol];
                        C.data[C.tu].i = arow;
                        C.data[C.tu].j = ccol;
                    }
                }
            }
        }
        return C;
    }
}

int main(int argc, char* argv[])
{
    RLSMatrix M,N,T;

    M.tu = 4;
    M.mu = 3;
    M.nu = 4;

    M.rpos[1] = 1;
    M.rpos[2] = 3;
    M.rpos[3] = 4;

    M.data[1].e = 3;
    M.data[1].i = 1;
    M.data[1].j = 1;

    M.data[2].e = 5;
    M.data[2].i = 1;
    M.data[2].j = 4;

    M.data[3].e = -1;
    M.data[3].i = 2;
    M.data[3].j = 2;

    M.data[4].e = 2;
    M.data[4].i = 3;
    M.data[4].j = 1;

    N.tu = 4;
    N.mu = 4;
    N.nu = 2;

    N.rpos[1] = 1;
    N.rpos[2] = 2;
    N.rpos[3] = 3;
    N.rpos[4] = 5;

    N.data[1].e = 2;
    N.data[1].i = 1;
    N.data[1].j = 2;

    N.data[2].e = 1;
    N.data[2].i = 2;
    N.data[2].j = 1;

    N.data[3].e = -2;
    N.data[3].i = 3;
    N.data[3].j = 1;

    N.data[4].e = 4;
    N.data[4].i = 3;
    N.data[4].j = 2;

   T= MultSMatrix(M,N,T);
    for (int i=1; i<=T.tu; i++) {
        printf("(%d,%d,%d)\n",T.data[i].i,T.data[i].j,T.data[i].e);
    }
    return 0;

}
