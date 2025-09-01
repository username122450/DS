#include<stdio.h>
#include<stdlib.h>
#define max 20
//顺序结构的队列写法: 1.入队
//                  2.出队
//                  3.判满
//                  4.判空
typedef struct{
    int *data;
    int f;
    int r;
}Queue;

Queue* Initqueue(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int)*max);
    q->f = 0;
    q->r = 0;
    return q;
}

int isEmpty(Queue *p){
    return p->r==p->f?1:0;
}

int isFull(Queue *p){
    return p->r == max?1:0;
}

void Push(Queue *p,int k){
    //判满
    if(isFull(p)==0) return ;

    p->data[p->r++] = k;
}

void Pop(Queue *p){
    //判空
    if(isEmpty(p)==0) return ;

    p->f++;
}

int main(){
    Queue *queue = Initqueue();


    return 0;
}
