#include<stdio.h>
#include<stdlib.h>
#define max 20
//逻辑“循环”
//“循环”顺序结构的队列写法: 1.入队
//                  2.出队
//                  3.判满
//                  4.判空

typedef struct{
    int *data;
    int f;
    int r;
}Queue,*CQueue;

CQueue InitQueue(){
    CQueue p = (Queue *)malloc(sizeof(Queue));
    p->data = (int *)malloc(sizeof(int) * max);
    p->f = 0;
    p->r = 0;
    return p;
}

int isEmpty(CQueue p){
    if(p->f == p->r) return 1;
    return 0;
}

int isFull(CQueue p){
    if((p->r + 1) % max == p->f) return 1;
    return 0;
}

void Push(CQueue p, int k){
    if(isFull(p) == 1){
        printf("队满，入队失败\n");
        return ;
    }
    p->data[p->r] = k;
    p->r = (p->r + 1) % max;
}

void Pop(CQueue p){
    if(isEmpty(p) == 1){
        printf("队空\n");
        return ;
    }
    p->f = (p->f + 1) % max ;
}

void Print(CQueue p){
    int temp = p->f;
    while(temp != p->r ){
        printf("%d  ", p->data[temp]);
        temp = (temp + 1) % max;
    }
    printf("\n");
}

int main(){
    CQueue p = InitQueue(); 
    Push(p,1);
    Push(p,2);
    Push(p,3);
    Print(p);
    Pop(p);
    Print(p);
    return 0;
}
