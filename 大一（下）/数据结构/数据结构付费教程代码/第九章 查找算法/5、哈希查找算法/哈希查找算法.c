#include "stdio.h"
#include "stdlib.h"
#define HASHSIZE 7 //����ɢ�б�Ϊ����ĳ���
#define NULLKEY -1
typedef struct{
    int *elem;//����Ԫ�ش洢��ַ����̬��������
    int count; //��ǰ����Ԫ�ظ���
}HashTable;
//�Թ�ϣ����г�ʼ��
void Init(HashTable *hashTable){
    int i;
    hashTable->elem= (int *)malloc(HASHSIZE*sizeof(int));
    hashTable->count=HASHSIZE;
    for (i=0;i<HASHSIZE;i++){
        hashTable->elem[i]=NULLKEY;
    }
}
//��ϣ����(����������)
int Hash(int data){
    return data%HASHSIZE;
}
//��ϣ��Ĳ��뺯���������ڹ����ϣ��
void Insert(HashTable *hashTable,int data){
    int hashAddress=Hash(data); //���ϣ��ַ
    //������ͻ
    while(hashTable->elem[hashAddress]!=NULLKEY){
        //���ÿ��Ŷ�ַ�������ͻ
        hashAddress=(++hashAddress)%HASHSIZE;
    }
    hashTable->elem[hashAddress]=data;
}

//��ϣ��Ĳ����㷨
int Search(HashTable *hashTable,int data){
    int hashAddress=Hash(data); //���ϣ��ַ
    while(hashTable->elem[hashAddress]!=data){//������ͻ
        //���ÿ��Ŷ�ַ�������ͻ
        hashAddress=(++hashAddress)%HASHSIZE;
        //������ҵ��ĵ�ַ������ΪNULL�����߾���һȦ�ı����ص�ԭλ�ã������ʧ��
        if (hashTable->elem[hashAddress]==NULLKEY||hashAddress==Hash(data)){
            return -1;
        }
    }
    return hashAddress;
}
int main(){
    int i,result;
    HashTable hashTable;
    int arr[HASHSIZE]={13,29,27,28,26,30,38};
    //��ʼ����ϣ��
    Init(&hashTable);
    //���ò��뺯�������ϣ��
    for (i=0;i<HASHSIZE;i++){
        Insert(&hashTable,arr[i]);
    }
    //���ò����㷨
    result= Search(&hashTable,29);
    if (result==-1) printf("����ʧ��");
    else printf("29�ڹ�ϣ���е�λ����:%d",result+1);
    return  0;
}
