#include <stdio.h>
#include <stdlib.h>

typedef enum {RED, BLACK} ColorType;
typedef struct RB_TREE{
    int key;
    struct  RB_TREE * left;
    struct  RB_TREE * right;
    struct  RB_TREE * p;
    ColorType color;
}RB_TREE;

typedef struct RBT_Root{
    RB_TREE* root;
    RB_TREE* nil;
}RBT_Root;

RBT_Root* rbTree_init(void);
void rbTree_insert(RBT_Root* *T, int k);
void rbTree_delete(RBT_Root* *T, int k);

void rbTree_transplant(RBT_Root* T, RB_TREE* u, RB_TREE* v);

void rbTree_left_rotate( RBT_Root* T, RB_TREE* x);
void rbTree_right_rotate( RBT_Root* T, RB_TREE* x);

void rbTree_inPrint(RBT_Root* T, RB_TREE* t);
void rbTree_prePrint(RBT_Root * T, RB_TREE* t);
void rbTree_print(RBT_Root* T);

RB_TREE* rbt_findMin(RBT_Root * T, RB_TREE* t);
RB_TREE* rbt_findMin(RBT_Root * T, RB_TREE* t){
    if(t == T->nil){
        return T->nil;
    }
    while(t->left != T->nil){
        t = t->left;
    }
    return t;
}
RBT_Root* rbTree_init(void){
    RBT_Root* T;
    T = (RBT_Root*)malloc(sizeof(RBT_Root));
    T->nil = (RB_TREE*)malloc(sizeof(RB_TREE));
    T->nil->color = BLACK;
    T->nil->left = T->nil->right = NULL;
    T->nil->p = NULL;
    T->root = T->nil;
    return T;
}

void RB_Insert_Fixup(RBT_Root* T, RB_TREE* x){
    //�����ж��丸�����ɫΪ��ɫʱ����Ҫ������Ϊ��ɫʱֱ�Ӳ��뼴�ɣ�����Ҫ����
    while (x->p->color == RED) {
        //���ڻ��漰���������㣬���Դ˴���ֿ����ۣ�ȷ����������游�������ӻ����Һ���
        if (x->p == x->p->p->left) {
            RB_TREE * y = x->p->p->right;//�ҵ���������
            //�����������ɫΪ��ɫ����Ϊ�� 1 �������������Ϊ���������ɫ��Ϊ��ɫ����������ɫ��Ϊ��ɫ���游�����ɫ��Ϊ��ɫ�����游��㸳ֵΪ��ǰ��㣬�����жϣ�
            if (y->color == RED) {
                x->p->color = BLACK;
                y->color = BLACK;
                x->p->p->color = RED;
                x = x->p->p;
            }else{
                //��֮�������������ɫΪ��ɫ���˴����Ϊ���������1����ǰ���ʱ�������Һ��ӣ�2����ǰ����Ǹ���������
                if (x == x->p->right) {
                    //�� 2 ���������ǰ���ʱ�������Һ��ӡ�������������������Ϊ��ǰ���������������
                    x = x->p;
                    rbTree_left_rotate(T, x);
                }else{
                    //�� 3 ���������ǰ����Ǹ��������ӡ�������������������ɫ��Ϊ��ɫ���游�����ɫ��Ϊ��ɫ�����游��㴦������������
                    x->p->color = BLACK;
                    x->p->p->color = RED;
                    rbTree_right_rotate(T, x->p->p);
                }
            }
        }else{//��������ʱ�游�����Һ��ӣ���������ҩ��ֻ�轫���ϴ��벿���е�left��Ϊright���ɣ�������һ���ġ�
            RB_TREE * y = x->p->p->left;
            if (y->color == RED) {
                x->p->color = BLACK;
                y->color = BLACK;
                x->p->p->color = RED;
                x = x->p->p;
            }else{
                if (x == x->p->left) {
                    x = x->p;
                    rbTree_right_rotate(T, x);
                }else{
                    x->p->color = BLACK;
                    x->p->p->color = RED;
                    rbTree_left_rotate(T, x->p->p);
                }
            }
        }
    }
    T->root->color = BLACK;
}
//���������Ϊ 3 ����1�����������������������ҵ������λ�ã�2����ʼ�������㣬���½�����ɫ��Ϊ��ɫ��3��ͨ�����õ�����������������������¸�Ϊ�����
void rbTree_insert(RBT_Root**T, int k){
    //1���ҵ���Ҫ�����λ�á����˼·Ϊ�������ĸ���㿪ʼ��ͨ�����ϵ�ͬ�½���ֵ���бȽϣ������ҵ�����λ��
    RB_TREE * x, *p;
    x = (*T)->root;
    p = x;

    while(x != (*T)->nil){
        p = x;
        if(k<x->key){
            x = x->left;
        }else if(k>x->key){
            x = x->right;
        }else{
            printf("\n%d�Ѵ���\n",k);
            return;
        }
    }
    //��ʼ����㣬���½�����ɫ��Ϊ��ɫ
    x = (RB_TREE *)malloc(sizeof(RB_TREE));
    x->key = k;
    x->color = RED;
    x->left = x->right =(*T)->nil;
    x->p = p;
    //���²���Ľ�㣬�������丸���֮�����ϵ
    if((*T)->root == (*T)->nil){
        (*T)->root = x;
    }else if(k < p->key){
        p->left = x;
    }else{
        p->right = x;
    }
    //3���Զ�����������е���
    RB_Insert_Fixup((*T),x);
}
void rbTree_transplant(RBT_Root* T, RB_TREE* u, RB_TREE* v){
    if(u->p == T->nil){
        T->root = v;
    }else if(u == u->p->left){
        u->p->left=v;
    }else{
        u->p->right=v;
    }
    v->p = u->p;
}
void RB_Delete_Fixup(RBT_Root**T,RB_TREE*x){
    while(x != (*T)->root && x->color == BLACK){
        if(x == x->p->left){
            RB_TREE* w = x->p->right;
            //�� 1 ��������ֵܽ���Ǻ�ɫ��
            if(RED == w->color){
                w->color = BLACK;
                w->p->color = RED;
                rbTree_left_rotate((*T),x->p);
                w = x->p->right;
            }
            //��2��������ֵ��Ǻ�ɫ�ģ������ֵܵ��������Ӷ��Ǻ�ɫ�ġ�
            if(w->left->color == BLACK && w->right->color == BLACK){
                w->color = RED;
                x = x->p;
            }
            //��3�����
            if(w->left->color == RED && w->right->color == BLACK){
                w->left->color = BLACK;
                w->color = RED;
                rbTree_right_rotate((*T),w);
                w = x->p->right;
            }
            //��4�����
            if (w->right->color == RED) {
                w->color = x->p->color;
                x->p->color = BLACK;
                w->right->color = BLACK;
                rbTree_left_rotate((*T),x->p);
                x = (*T)->root;
            }
        }else{
            RB_TREE* w = x->p->left;
            //�� 1 �����
            if(w->color == RED){
                w->color = BLACK;
                x->p->color = RED;
                rbTree_right_rotate((*T),x->p);
                w = x->p->left;
            }
            //�� 2 �����
            if(w->left->color == BLACK && w->right->color == BLACK){
                w->color = RED;
                x = x->p;
            }
            //�� 3 �����
            if(w->left->color == BLACK && w->right->color == RED){
                w->color = RED;
                w->right->color = BLACK;
                w = x->p->left;
            }
            //�� 4 �����
            if (w->right->color == BLACK){
                w->color=w->p->color;
                x->p->color = BLACK;
                w->left->color = BLACK;
                rbTree_right_rotate((*T),x->p);
                x = (*T)->root;
            }
        }
    }
    x->color = BLACK;//���ս���������ɫ��Ϊ��ɫ
}
void rbTree_delete(RBT_Root* *T, int k){
    if(NULL == (*T)->root){
        return ;
    }
    //�ҵ�Ҫ��ɾ���Ľ��
    RB_TREE * toDelete = (*T)->root;
    RB_TREE * x = NULL;
    //�ҵ�ֵΪk�Ľ��
    while(toDelete != (*T)->nil && toDelete->key != k){
        if(k<toDelete->key){
            toDelete = toDelete->left;
        }else if(k>toDelete->key){
            toDelete = toDelete->right;
        }
    }
    if(toDelete == (*T)->nil){
        printf("\n%d ������\n",k);
        return;
    }
    //����������ӣ����ҵ�����������С�Ľ�㣬��֮���棬Ȼ��ֱ��ɾ���ý�㼴��
    if(toDelete->left != (*T)->nil && toDelete->right != (*T)->nil){
        RB_TREE* alternative = rbt_findMin((*T), toDelete->right);
        k = toDelete->key = alternative->key;//����ֻ��ֵ���и��ƣ�����������ɫ�������ƻ������������
        toDelete = alternative;
    }
    //���ֻ��һ�����ӽ�㣨ֻ�����ӻ�ֻ���Һ��ӣ���ֱ���ú��ӽ�㶥��ý��λ�ü��ɣ�û�к��ӽ���Ҳ�ߴ��ж���䣩��
    if(toDelete->left == (*T)->nil){
        x = toDelete->right;
        rbTree_transplant((*T),toDelete,toDelete->right);
    }else if(toDelete->right == (*T)->nil){
        x = toDelete->left;
        rbTree_transplant((*T),toDelete,toDelete->left);
    }
    //��ɾ���ý��֮ǰ�����жϴ˽�����ɫ������Ǻ�ɫ��ֱ��ɾ���������ƻ�����������Ǻ�ɫ��ɾ������ƻ�������ĵ� 5 �����ʣ���Ҫ������������
    if(toDelete->color == BLACK){
        RB_Delete_Fixup(T,x);
    }
    //���տ��Գ���ɾ��Ҫɾ���Ľ�㣬�ͷ���ռ�õĿռ�
    free(toDelete);
}

//T��ʾΪ������x ��ʾ��Ҫ���������������ĸ����
void rbTree_left_rotate( RBT_Root* T, RB_TREE* x){
    RB_TREE* y = x->right;//�ҵ�������������

    x->right = y->left;//���������������ƶ������ x ���Һ��Ӵ�
    if(x->right != T->nil){//��� x ������������nil������������ ��������˫�׽��Ϊ x
        x->right->p = x;
    }
    y->p = x->p;//���� y ��˫�׽��Ϊ x ��˫�׽��
    //�������� y ��˫�׽��ͬ y �����ӣ���Ϊ 2 �������1��ԭ x ��㱾�������������������㣬��ʱֻ��Ҫ�� T ָ��ָ�� y��2������ y �йؼ���ͬ�丸���ؼ��ֵ�ֵ�Ĵ�С���ж� y �Ǹ��������ӻ����Һ���
    if(y->p == T->nil){
        T->root = y;
    }else if(y->key < y->p->key){
        y->p->left = y;
    }else{
        y->p->right = y;
    }
    y->left = x;//�� x ���Ӹ� y �������Ӵ�
    x->p = y;//���� x ��˫�׽��Ϊ y��
}

void rbTree_right_rotate( RBT_Root* T, RB_TREE* x){
    RB_TREE * y = x->left;
    x->left = y->right;
    if(T->nil != x->left){
        x->left->p = x;
    }
    y->p = x->p;
    if(y->p == T->nil){
        T->root = y;
    }else if(y->key < y->p->key){
        y->p->left= y;
    }else{
        y->p->right = y;
    }
    y->right = x;
    x->p = y;
}
void rbTree_prePrint(RBT_Root* T, RB_TREE* t){
    if(T->nil == t){
        return;
    }
    if(t->color == RED){
        printf("%dR ",t->key);
    }else{
        printf("%dB ",t->key);
    }
    rbTree_prePrint(T,t->left);
    rbTree_prePrint(T,t->right);
}
void rbTree_inPrint(RBT_Root* T, RB_TREE* t){
    if(T->nil == t){
        return ;
    }
    rbTree_inPrint(T,t->left);
    if(t->color == RED){
        printf("%dR ",t->key);
    }else{
        printf("%dB ",t->key);
    }
    rbTree_inPrint(T,t->right);
}

//����������ǰ���������������Ľ��
void rbTree_print(RBT_Root* T){
    printf("ǰ����� ��");
    rbTree_prePrint(T,T->root);
    printf("\n");
    printf("������� ��");
    rbTree_inPrint(T,T->root);
    printf("\n");
}

int main(){
    RBT_Root* T = rbTree_init();

    rbTree_insert(&T,3);
    rbTree_insert(&T,5);
    rbTree_insert(&T,1);
    rbTree_insert(&T,2);
    rbTree_insert(&T,4);
    rbTree_print(T);
    printf("\n");
    rbTree_delete(&T,3);
    rbTree_print(T);

    return 0;
}
