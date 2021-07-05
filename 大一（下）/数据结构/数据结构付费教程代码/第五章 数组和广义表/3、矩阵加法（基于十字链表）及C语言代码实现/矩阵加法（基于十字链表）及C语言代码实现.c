#include<stdio.h>
#include<stdlib.h>

typedef struct OLNode
{
    int i,j,e;                      //������Ԫ��i������ j������ e����ǰλ�õ�����
    struct OLNode *right,*down;     //ָ���� ��ָ�� ��ָ��
}OLNode,*OLink;

typedef struct
{
    OLink *rhead,*chead;            //�к�������ͷָ��
    int mu,nu,tu;                   //���������,�����ͷ���Ԫ�ĸ���
}CrossList;

CrossList CreateMatrix_OL(CrossList M);
CrossList AddSMatrix(CrossList M,CrossList N);

void display(CrossList M);

void main()
{
    CrossList M,N;
    printf("������Ծ���M:\n");
    M=CreateMatrix_OL(M);
    printf("������Ծ���N:\n");
    N=CreateMatrix_OL(N);
    M=AddSMatrix(M,N);
    printf("������ӵĽ��Ϊ:\n");
    display(M);
}

CrossList CreateMatrix_OL(CrossList M)
{
    int m,n,t;
    int i,j,e;
    OLNode *p,*q;
    scanf("%d%d%d",&m,&n,&t);
    M.mu=m;
    M.nu=n;
    M.tu=t;
    if(!(M.rhead=(OLink*)malloc((m+1)*sizeof(OLink)))||!(M.chead=(OLink*)malloc((n+1)*sizeof(OLink))))
    {
        printf("��ʼ������ʧ��");
        exit(0);
    }
    for(i=1;i<=m;i++)
    {
        M.rhead[i]=NULL;
    }
    for(j=1;j<=n;j++)
    {
        M.chead[j]=NULL;
    }
    for(scanf("%d%d%d",&i,&j,&e);0!=i;scanf("%d%d%d",&i,&j,&e))    {
        if(!(p=(OLNode*)malloc(sizeof(OLNode))))
        {
            printf("��ʼ����Ԫ��ʧ��");
            exit(0);
        }
        p->i=i;
        p->j=j;
        p->e=e;
        if(NULL==M.rhead[i]||M.rhead[i]->j>j)
        {
            p->right=M.rhead[i];
            M.rhead[i]=p;
        }
        else
        {
            for(q=M.rhead[i];(q->right)&&q->right->j<j;q=q->right);
            p->right=q->right;
            q->right=p;
        }

        if(NULL==M.chead[j]||M.chead[j]->i>i)
        {
            p->down=M.chead[j];
            M.chead[j]=p;
        }
        else
        {
            for (q=M.chead[j];(q->down)&& q->down->i<i;q=q->down);
            p->down=q->down;
            q->down=p;
        }
    }
    return M;
}

CrossList AddSMatrix(CrossList M,CrossList N){
    OLNode * pa,*pb;
    OLink * hl=(OLink*)malloc(M.nu*sizeof(OLink));
    OLNode * pre=NULL;
    for (int j=1; j<=M.nu; j++) {
        hl[j]=M.chead[j];
    }
    for (int i=1; i<=M.mu; i++) {
        pa=M.rhead[i];
        pb=N.rhead[i];
        while (pb!=NULL) {
            OLNode * p=(OLNode*)malloc(sizeof(OLNode));
            p->i=pb->i;
            p->j=pb->j;
            p->e=pb->e;
            p->down=NULL;
            p->right=NULL;
            if (pa==NULL||pa->j>pb->j) {
                if (pre==NULL) {
                    M.rhead[p->i]=p;
                }else{
                    pre->right=p;
                }
                p->right=pa;
                pre=p;
                if (!M.chead[p->j]||M.chead[p->j]->i>p->i) {
                    p->down=M.chead[p->j];
                    M.chead[p->j]=p;
                }else{
                    p->down=hl[p->j]->down;
                    hl[p->j]->down=p;
                }
                hl[p->j]=p;
            }else{
                if (pa->j<pb->j) {
                    pre=pa;
                    pa=pa->right;
                    continue;
                }
                if (pa->j==pb->j) {
                pa->e+=pb->e;
                if (pa->e==0) {
                    if (pre==NULL) {
                        M.rhead[pa->i]=pa->right;
                    }else{
                        pre->right=pa->right;
                    }
                    p=pa;
                    pa=pa->right;
                    if (M.chead[p->j]==p) {
                        M.chead[p->j]=hl[p->j]=p->down;
                    }else{
                        hl[p->j]->down=p->down;
                    }
                    free(p);
                    }
                }
            }
            pb=pb->right;
        }
    }
    display(M);
    return M;
}

void display(CrossList M){
    printf("������Ծ���:\n");
    printf("M:\n---------------------\ni\tj\te\n---------------------\n");
    for (int i=1;i<=M.nu;i++)
    {
        if (NULL!=M.chead[i])
        {
           OLink p=M.chead[i];
            while (NULL!=p)
            {
                printf("%d\t%d\t%d\n",p->i,p->j,p->e);
                p=p->down;
            }
        }
    }

}
