#include<stdio.h>
#include<stdlib.h>

//基于（特殊）双链表的双端队列的写法： 1.入队 1）左端入队  2）右端入队
//                              2.出队 1）左端出队  2）有段出队
//                              3.判空
//规定：左端第一次入队可以放在mid节点
typedef struct QNode{
    int data;
    struct QNode *next;
    struct QNode *pre;
}DeQNode;

typedef struct {
    DeQNode *l;
    DeQNode *r;
}LDeQueue;

LDeQueue* InitQueue(){
    LDeQueue *p = (LDeQueue *)malloc(sizeof(LDeQueue));
    p->l = (DeQNode *)malloc(sizeof(DeQNode));
    p->l->next = NULL;
    p->l->pre = NULL;
    p->r = p->l;
    return p;
}

void LeftPush(LDeQueue *q,int k){
    q->l->data = k;
    DeQNode *s = (DeQNode *)malloc(sizeof(DeQNode));
    s->pre = NULL;
    s->next = q->l;
    q->l->pre = s;
    q->l = s;
}

/*
这里是LeftPush的第二种实现逻辑：
开始创建的节点是作为空节点，不存放数据，可以理解为双链表的头指针
*/

/*
void LeftPush(LDeQueue *q,int k){
    DeQNode *s = (DeQNode *)malloc(sizeof(DeQNode));
    s->data = k;
    s->next = q->l->next;
    s->pre = q->l;
    if(q->l == q->r){
        q->r = s;
    }else{
        q->l->next->pre = s;
    }
    q->l->next = s;

}
*/


void LeftPop(LDeQueue *q){
    //这里做指针指向的是真正存放数据的节点的前一个节点，这个节点是不断新创建的
    if(q->l == q->r){
        printf("队空\n");
        return ;
    }
    DeQNode *s = q->l;
    q->l = s->next;
    free(s);
    s = NULL;
}

void RightPush(LDeQueue *q , int k){
    DeQNode *s = (DeQNode *)malloc(sizeof(DeQNode));
    s->data = k;
    s->pre = q->r;
    s->next = NULL;
    q->r->next = s;
    q->r = s;
}

void RightPop(LDeQueue *q){
    if(q->l == q->r){
        printf("队空\n");
        return ;
    }
    DeQNode *s = q->r;
    q->r = q->r->pre;
    free(s);
    s = NULL;
}

void Print(LDeQueue *q){
    if(q->l == q->r){
        printf("队空\n");
        return ;
    }
    DeQNode *s = q->l->next;
    while(s != NULL){
        printf("%d  ",s->data);
        s = s->next;
    }
    printf("\n");
}

int main(){
    LDeQueue *q = InitQueue();
    LeftPush(q,1);
    LeftPush(q,2);
    RightPush(q,3);
    RightPush(q,4);
    Print(q);
    LeftPop(q);
    Print(q);
    return 0;
}