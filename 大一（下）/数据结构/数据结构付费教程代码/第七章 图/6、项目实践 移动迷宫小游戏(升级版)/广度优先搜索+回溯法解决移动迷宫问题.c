#include <stdio.h>
typedef enum{false,true} bool;

typedef struct {
    int x;
    int y;
    char mess;
    int value;
}check;

bool canUsed(int x,int y,char data,int n,int m){
    if (x>=0 && x<n && y>=0 && y<m && data!='#') {
        return true;
    }
    return false;
}
void createMaze(int n,int m,check a[][110],int *entryx,int *entryy,int *exitx,int *exity){
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%c",&a[i][j].mess);
            a[i][j].x=i;
            a[i][j].y=j;
            if (a[i][j].mess=='S') {
                *entryx=i;
                *entryy=j;
            }else if(a[i][j].mess=='E'){
                *exitx=i;
                *exity=j;
            }
        }
        getchar();
    }
}
//ʹ�õĹ������������˼�룬���ö��е����ݽṹʵ��
void findRoad(check a[][110],int top,int rear,check queue[],int *value,int entryx,int entryy,int n,int m){
    //���Ƚ���ڶ������
    check data;
    data.x=entryx;
    data.y=entryy;
    a[entryx][entryy].mess='#';
    data.mess=a[entryx][entryy].mess;
    data.value=0;
    queue[rear]=data;
    bool success=false;
    rear++;
    //���в���
    while (top!=rear) {
        //�������
        check temp=queue[top];
        a[temp.x][temp.y].value=temp.value;
        top++;
        //���ڳ��ӵĶ����ж��Ƿ��ǳ��ڣ��׸��ж�Ϊ���ڵĶ��㣬��valueֵ�������·���ĳ���
        if (temp.mess=='E') {
            *value=temp.value;
            printf("%d\n",temp.value);
            success=true;
            break;
        }
        //ÿ����ӣ��ж����ϡ��¡����ҵĶ����Ƿ���������������ϣ�����ӣ�ͬʱ����valueֵ��ֵΪǰһ������value+1��Ϊ�˱����ظ��жϴ˶��㣬��ÿ����ӵĶ��㣬�趨���ַ�Ϊ��#��
        if(canUsed(temp.x-1,temp.y,a[temp.x-1][temp.y].mess,n,m)){
            data.x=temp.x-1;
            data.y=temp.y;
            data.mess=a[temp.x-1][temp.y].mess;
            data.value=temp.value+1;
            queue[rear]=data;
            a[temp.x-1][temp.y].mess='#';
            rear++;
        }
        //�ұ�
        if(canUsed(temp.x,temp.y+1,a[temp.x][temp.y+1].mess,n,m)){
            data.x=temp.x;
            data.y=temp.y+1;
            data.mess=a[temp.x][temp.y+1].mess;
            data.value=temp.value+1;
            queue[rear]=data;
            a[temp.x][temp.y+1].mess='#';
            rear++;
        }
        //�±�
        if(canUsed(temp.x+1,temp.y,a[temp.x+1][temp.y].mess,n,m)){
            data.x=temp.x+1;
            data.y=temp.y;
            data.mess=a[temp.x+1][temp.y].mess;
            data.value=temp.value+1;
            queue[rear]=data;
            a[temp.x+1][temp.y].mess='#';
            rear++;
        }
        //���
        if(canUsed(temp.x,temp.y-1,a[temp.x][temp.y-1].mess,n,m)){
            data.x=temp.x;
            data.y=temp.y-1;
            data.mess=a[temp.x][temp.y-1].mess;
            data.value=temp.value+1;
            queue[rear]=data;
            a[temp.x][temp.y-1].mess='#';
            rear++;
        }
    }
    //������ɹ���֤�����ں����֮��û��ͨ·
    if (success==false) {
        printf("-1\n");
    }
}
//����������·��ʱ���ݹ����е��ж�
bool judgeValue(int x,int y,int n,int m){
    if (x>=0 && x<n && y>=0 && y<m ){
        return true;
    }
    return false;
}
//�����ʱ���������·���д���ڿ�ʼ��һֱ�����ڣ��������Ķ���� value ֵ�� +1�����Բ��û��ݷ��������п��ܵ����·��
void displayRoad(check a[][110],int entryx,int entryy,int n,int m,int value){
    //���þ�̬���飬ʵ��ջ������
    static check stack[1000];
    static int top=-1;//ջ��ջ��
    //����ÿ����ǰ�Ķ��㣬������Ҫ�ж����Ƿ�����������Ҫ��������ǰ�ڶ�ά�����е�ͨ·������ˡ�#�������������һ���ؼ��� ��value��ֵΪ���ؼ��ֽ�������
    if (judgeValue(entryx, entryy, n, m)) {
        //����˼���ʵ���õ��ǵݹ飬������Ҫ����һ�����ڣ����ھ��ǵ����ҵ������valueֵΪ���·���Ķ�����ʱ��������ʱ�Ѿ������ڳ���λ�ã���ʱ�Ϳ����������ջ�ڴ洢�ĸ��������Ķ��������
        if (a[entryx][entryy].value==value) {
            for (int i=0; i<top; i++) {
                printf("(%d,%d) ",stack[i].x,stack[i].y);
            }
            printf("\n");
            return;
        }
        //����ڳ������жϵ�ǰ����ϡ��¡�����λ���ϵĶ����Ƿ����Ҫ��1���ö��������û�г�����Χ��2�ö����valueֵ��ǰһ�������valueֵ+1����������ϣ�˵��֮ǰ�ж����·��ʱ��;���˶��㣬������ջ���б���
        if (judgeValue(entryx+1, entryy, n, m) && a[entryx+1][entryy].value==a[entryx][entryy].value+1) {
            top++;
            stack[top]=a[entryx+1][entryy];
            displayRoad(a, entryx+1, entryy, n, m,value);
            //���������ˣ������������;���˶��������ҵ����ڣ��������ս���������ʱӦ���ö��㵯ջ���ö����·��������ȷ�ģ�Ӧ��ջ�����������Ӧ��ջ��
            top--;
        }
        if (judgeValue(entryx-1, entryy, n, m) && a[entryx-1][entryy].value==a[entryx][entryy].value+1) {
            top++;
            stack[top]=a[entryx-1][entryy];
            displayRoad(a, entryx-1, entryy, n, m,value);
            top--;
        }
        if (judgeValue(entryx, entryy+1, n, m) && a[entryx][entryy+1].value==a[entryx][entryy].value+1) {
            top++;
            stack[top]=a[entryx][entryy+1];
            displayRoad(a, entryx, entryy+1, n, m,value);
            top--;
        }
        if (judgeValue(entryx, entryy-1, n, m) && a[entryx][entryy-1].value==a[entryx][entryy].value+1) {
            top++;
            stack[top]=a[entryx][entryy-1];
            displayRoad(a, entryx, entryy-1, n, m,value);
            top--;
        }
    }
}
int main(int argc, const char * argv[]) {
    check a[110][110];
    check queue[100000];
    int top=0,rear=0;
    int n,m;
    int entryx = 0,entryy=0,exitx=0,exity=0;
    scanf("%d %d",&n,&m);
    getchar();
    //�����Թ������ҵ���ںͳ��ڵ�λ������
    createMaze(n,m,a,&entryx,&entryy,&exitx,&exity);
    //���Թ��в��Ҵ���ڵ����ڵ����·�������У�������·���ĳ��ȣ���֮�����-1
    int value;
    findRoad(a,top,rear,queue,&value,entryx,entryy,n,m);
    //������е����·��
    displayRoad(a, entryx, entryy, n, m, value);
    return 0;
}
