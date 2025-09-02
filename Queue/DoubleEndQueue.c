#include<stdio.h>
#include<stdlib.h>
#define max 10

//基于“循环”队列的双端队列的写法： 1.入队 1）左端入队  2）右端入队
//                              2.出队 1）左端出队  2）有段出队
//                              3.判满
//                              4.判空

//规定：左端第一次入队可以放在0下标
typedef struct{
    int *data;
    int l;
    int r;
}DeQueue;

DeQueue* InitQueue(){
    DeQueue *p = (DeQueue *)malloc(sizeof(DeQueue));
    p->data = (int *)malloc(sizeof(int) * max);
    p->l = p->r = 0;
    return p;
}

void LeftPush(DeQueue *p,int k){
    //判满
    if(p->l -1 == p->r) {
        printf("队满\n");
        return ;
    }
    p->data[p->l] = k;
    p->l = (p->l - 1 + max) % max;
}

void LeftPop(DeQueue *p){
    if(p->l == p->r){
        printf("队空\n");
        return ;
    }
    p->l  =  (p->l + 1) % max ;
}

void RightPush(DeQueue *p,int k){
    if(p->l -1 == p->r) {
        printf("队满\n");
        return ;
    }
    p->r = (p->r + 1) % max;
    p->data[p->r] = k;
}

void RightPop(DeQueue *p){
    if(p->l == p->r){
        printf("队空\n");
        return ;
    }
    p->r = (p->r - 1 + max) % max ;
}

void Print(DeQueue *p){
    if(p->l == p->r){
        printf("队空\n");
        return ;
    }
    int temp = p-> l;
    while((temp + 1) % max != p->r){
        temp = (temp + 1) % max;
        printf("%d  ",p->data[temp]);
        
    }

    printf("%d  \n",p->data[p->r]);

}

int main(){
    DeQueue *p = InitQueue(); 
    LeftPush(p,1);
    LeftPush(p,2);
    RightPush(p,3);
    RightPush(p,4);
    Print(p);
    LeftPop(p);
    Print(p);
    return 0;
}