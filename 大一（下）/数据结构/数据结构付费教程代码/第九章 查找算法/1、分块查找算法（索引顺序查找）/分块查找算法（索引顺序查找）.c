#include <stdio.h>
#include <stdlib.h>
struct index {  //�����Ľṹ
    int key;
    int start;
} newIndex[3];   //����ṹ������

int search(int key, int a[]);

int cmp(const void *a,const void* b){
    return (*(struct index*)a).key>(*(struct index*)b).key?1:-1;
}
int main(){
    int i, j=-1, k, key;
    int a[] = {33,42,44,38,24,48, 22,12,13,8,9,20,  60,58,74,49,86,53};
    //ȷ��ģ�����ʼֵ�����ֵ
    for (i=0; i<3; i++) {
        newIndex[i].start = j+1;  //ȷ��ÿ���鷶Χ����ʼֵ
        j += 6;
        for (int k=newIndex[i].start; k<=j; k++) {
            if (newIndex[i].key<a[k]) {
                newIndex[i].key=a[k];
            }
        }
    }
    //�Խṹ�尴�� key ֵ��������
    qsort(newIndex,3, sizeof(newIndex[0]), cmp);

    //����Ҫ��ѯ�����������ú������в���
    printf("����������Ҫ���ҵ�����\n");
    scanf("%d", &key);
    k = search(key, a);
    //������ҵĽ��
    if (k>0) {
        printf("���ҳɹ�����Ҫ�ҵ����������е�λ���ǣ�%d\n",k+1);
    }else{
        printf("����ʧ�ܣ���Ҫ�ҵ������������С�\n");
    }
    return 0;
}
int search(int key, int a[]){
    int i, startValue;
    i = 0;
    while (i<3 && key>newIndex[i].key) { //ȷ�����ĸ����У�����ÿ���飬ȷ��key���ĸ�����
        i++;
    }
    if (i>=3) {  //���ڷֵõĿ������򷵻�0
        return -1;
    }
    startValue = newIndex[i].start;  //startValue���ڿ鷶Χ����ʼֵ
    while (startValue <= startValue+5 && a[startValue]!=key)
    {
        startValue++;
    }
    if (startValue>startValue+5) {  //������ڿ鷶Χ�Ľ���ֵ����˵��û��Ҫ���ҵ���
        return -1;
    }
    return startValue;
}
