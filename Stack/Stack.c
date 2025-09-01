#include<stdio.h>
#include<stdlib.h>

#define max 10

//顺序结构的栈（顺序栈）写法：1.判空
//                2.判满
//                3.入栈，
//                4.出栈
//                5.获取一个元素
typedef struct{
    int *data;
    int top;
}Stack;

Stack Initstack(){
    Stack l ;
    l.data = (int *)malloc(sizeof(int)* max);
    l.top = 0;
    return l;
}

int isFull(Stack *p){
    if(p->top == max){
        printf("栈满\n");
        return 0;
    }
    return 1;
}

int isEmpty(Stack *p){
    if(p->top == 0){
        printf("栈空\n");
        return 0;
    }
    return 1;
}

void Push(Stack *p,int k){
    if(isFull(p) == 0){
        printf("入栈失败\n");
        return ;
    }
    p->data[p->top++] = k;
}

void Pop(Stack *p ){
    if(isEmpty(p) == 0){
        printf("出栈失败\n");
        return ;
    }
    p->top--;
}

int Get(Stack *p){
    if(isEmpty(p) == 0){
        printf("获取失败\n");
        return -1;
    }
    int res = p->data[p->top-1];
    return res;
}

void Print(Stack *p){
    printf("栈底到栈顶：\n");
    for(int i = 0; i<p->top;i++){
        printf("%d  ",p->data[i]);
    }
    printf("\n");
}

int main(){
    Stack l = Initstack();
    Push(&l,1);
    Push(&l,2);
    Push(&l,4);
    Pop(&l);
    printf("栈顶元素：%d\n",Get(&l));
    Print(&l);
    return 0;
}

