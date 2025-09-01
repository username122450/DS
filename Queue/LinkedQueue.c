#include<stdio.h>
#include<stdlib.h>

//单向链式结构的队列写法: 1.入队
//                  2.出队
//                  3.判空

typedef struct QueueNode{
    int data;
    struct QueueNode *next;
}QNode;

typedef struct {
    QNode *f;
    QNode *r;
}LinkedQueue;

LinkedQueue* InitQueue(){
    LinkedQueue *p = (LinkedQueue *)malloc(sizeof(LinkedQueue));
    p->f =(QNode *)malloc(sizeof(QNode));
    p->f->next = NULL;
    p->r = p->f;
    return p;  
}

int isEmpty(LinkedQueue *p){
    if(p->f->next == NULL) return 1;
    return 0;
}

void Push(LinkedQueue *p,int k){
    QNode *s = (QNode *)malloc(sizeof(QNode));
    s->data = k;
    s->next = NULL;
    p->r->next = s;
    p->r = s;
}

void Pop(LinkedQueue *p){
    if(isEmpty(p) == 1) {
        printf("队空\n");
        return ;
    }
    
    QNode *s = p->f->next;
    if(p->r == s) p->r = p->f;
    p->f->next = s->next;
    free(s);
    s = NULL;
    
}
void Print(LinkedQueue *p){
    QNode *s = p->f->next;
    while(s != NULL){
        printf("%d  ",s->data);
        s = s->next;
    }
    printf("\n");
}

int main(){
    LinkedQueue *p = InitQueue();
    Push(p,1);
    Push(p,2);
    Push(p,3);
    Print(p);
    Pop(p);
    Print(p);
    return 0;
}