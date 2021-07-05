#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef enum {false,true} bool;
//�Թ�������һ��8��10�еľ���
int ROWS=8;
int COLS=10;
//��ʼ���Թ�����������Թ�����ڣ�ͬʱ���Թ���������ÿ��е�·��
void mazeGenerator(char [][COLS],int *,int *,int *,int *);
//ʹ�û��ݷ�����ڴ����ϵس����ҵ����ڵ�·��
void mazeTraversal(char maze[ROWS][COLS],int row,int col,int entryRow,int entryCol,int exitrow,int exitcol);
//�Թ����������
void printMaze(const char[][COLS]);
//�ж�ÿһ���ƶ��Ƿ���Ч
bool validMove(const char [][COLS],int,int);

int main()
{
    printf("*********�ƶ��Թ�С��Ŀ�����ݽṹ�͸���ôѧ��*********\n");
    char maze[ROWS][COLS];
    int xStart,yStart,x,y;
    srand(time(0));//���������������ÿ���������²�ͬ�����ӣ�����ͨ��rand()������õ�������Ͳ�ͬ��
    //ͨ��һ��Ƕ��ѭ�����Ƚ��Թ��и����ط�����Ϊ��·(��#����ʾΪǽ����ʾ�˴�����ͨ��)
    for(int loop=0;loop<ROWS;++loop ){
        for(int loop2=0;loop2<COLS;++loop2 ){
            maze[loop][loop2]='#';
        }
    }
    //��ʼ���Թ��������Թ���������ó��ڡ���ں��м�ĵ�·���á�0����ʾ��ͨ���˺�������ͬʱ�õ���ڵ�����
    mazeGenerator(maze,&xStart,&yStart,&x,&y);

    printf("�Թ����λ������Ϊ(%d,%d);����λ������Ϊ��(%d��%d);\n",xStart+1,yStart+1,x+1,y+1);
    printf("�Թ��������£���#����ʾǽ����0����ʾͨ·����\n");
    printMaze(maze);//���һ����ʼ���õ��Թ�
    //ʹ�û��ݷ���ͨ�����ϵؽ��г��ԣ���ͼ�ҵ�һ��ͨ�����ڵ�·��
    mazeTraversal(maze,xStart,yStart,xStart,yStart,x,y);
}
//�����Թ����岼��Ϊ���Σ��������ߣ��ڳ�ʼ���Թ��ĳ��ں����ʱ�����ѡ��ͬ����������Ϊ���ó��ں���ڵı�
void mazeGenerator(char maze[][COLS],int *xPtr,int *yPtr,int *exitx,int *exity){
    int a,x,y,entry,exit;
    do {
        entry=rand()%4;
        exit=rand()%4;
    }while(entry==exit);
    // ȷ�����λ�ã�0 ����ѡ���Ϊ���ıߣ�1 ����Ϊ�ϱߣ�2����Ϊ�Ҳ�ıߣ�3 ����Ϊ�±�
    if(entry==0){
        *xPtr=1+rand()%(ROWS-2);
        *yPtr=0;
        maze[*xPtr][*yPtr]='0';
    }else if(entry==1){
        *xPtr=0;
        *yPtr=1+rand()%(COLS-2);
        maze[*xPtr][*yPtr]='0';
    }else if(entry==2){
        *xPtr=1+rand()%(ROWS-2);
        *yPtr=COLS-1;
        maze[*xPtr][*yPtr]='0';
    }else{
        *xPtr=ROWS-1;
        *yPtr=1+rand()%(COLS-2);
        maze[*xPtr][*yPtr]='0';
    }
    //ȷ������λ��
    if(exit==0){
        a=1+rand()%(ROWS-2);
        *exitx=a;
        *exity=0;
        maze[a][0]='0';}
    else if(exit==1){
        a=1+rand()%(COLS-2);
        *exitx=0;
        *exity=a;
        maze[0][a]='0';}
    else if(exit==2){
        a=1+rand()%(ROWS-2);
        *exitx=a;
        *exity=COLS-1;
        maze[a][COLS-1]='0';}
    else{
        a=1+rand()%(COLS-2);
        *exitx=ROWS-1;
        *exity=a;
        maze[ROWS-1][a]='0';
    }
    //���Թ��������ö����ͬ�����ͨ·
    for(int loop=1;loop<(ROWS-2)*(COLS-2);++loop) {
        x=1+rand()%(ROWS-2);
        y=1+rand()%(COLS-2);
        maze[x][y]='0';}
}

void mazeTraversal(char maze[ROWS][COLS],int row,int col,int entryRow,int entryCol,int exitrow,int exitcol){
    //���ڴ���ڴ����룬Ϊ�������߹���ͨ·��û�߹���ͨ·�����߹���ͨ·����Ϊ��x����
    maze[row][col]='x';
    static bool judge=false;//����һ���жϱ������ж������λ���Ƿ���ͨ·���ڡ�
    static int succ=0;//����ͳ�ƴ���ڵ����ڵĿ���ͨ·������
    if (row==exitrow && col==exitcol) {
        printf("�ɹ��߳��Թ�����·ͼ���£�\n");
        printMaze(maze);
        succ++;
        return;
    }
    //�жϵ�ǰλ�õ��·��Ƿ�Ϊͨ·
    if (validMove(maze, row+1, col)) {
        judge=true;//֤��������·���ڣ�����֤���Ƿ��п�ͨ�����ڵ�·
        mazeTraversal(maze, row+1, col,entryRow,entryCol,exitrow,exitcol);//���·���λ��Ϊ����������
    }
    //�жϵ�ǰλ�õ��Ҳ��Ƿ�Ϊͨ·
    if (validMove(maze, row, col+1)) {
        judge=true;
        mazeTraversal(maze, row, col+1,entryRow,entryCol,exitrow,exitcol);
    }
    //�жϵ�ǰλ�õ��Ϸ��Ƿ�Ϊͨ·
    if (validMove(maze, row-1, col)) {
        judge=true;
        mazeTraversal(maze, row-1, col,entryRow,entryCol,exitrow,exitcol);
    }
    //�жϵ�ǰλ�õ�����Ƿ�Ϊͨ·
    if (validMove(maze, row, col-1)) {
        judge=true;
        mazeTraversal(maze, row, col-1,entryRow,entryCol,exitrow,exitcol);
    }
    //���judge��Ϊ�٣�˵������ڴ�ȫ����ǽ��Χ����·����
    if (judge==false) {
        printf("��ڱ�������������·���ߣ�\n");
        printMaze(maze);
    }
    //���judgeΪ�棬����succֵΪ0���������ֻص�����ڵ�λ�ã�֤�����еĳ��Թ���������ɣ�����û�з���ͨ�����ڵ�·
    else if(judge==true && row==entryRow && col==entryCol && succ==0){
        printf("���������е�·�����ں����֮��û��ͨ·��\n");
        printMaze(maze);
    }
}
//��Ч�ƶ�����֤����λ�ô��������Թ��ľ��η�Χ�ڣ��Ҹ�λ����ͨ·������ǽ��Ҳ��δ�߹�
bool validMove(const char maze[][COLS],int r,int c){
    return(r>=0&&r<=ROWS-1&&c>=0&&c<=COLS-1&&maze[r][c]!='#'&& maze[r][c]!='x');
}
//����Թ�
void printMaze(const char maze[][COLS] ){
    for(int x=0;x<ROWS;++x){
        for(int y=0;y<COLS;++y){
            printf("%c ",maze[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}
