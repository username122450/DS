#include<stdio.h>
#include<stdlib.h>

//多重邻接表

typedef struct Node{
    int x,y;
    struct Node *xnext,*ynext;
}ListNode;

struct{
    char data;
    ListNode *next;
}b[105];

typedef struct qNode{
    int x;
    struct qNode *next;
    struct qNode *pre;
}QNode;

typedef struct {
    QNode *first;
    QNode *end;
}Queue;

Queue *InitQueue(){
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->first =(QNode *)malloc(sizeof(QNode));
    queue->end = (QNode *)malloc(sizeof(QNode));
    queue->first->next = queue->end;
    queue->end->next = queue->first ->pre = NULL;
    queue->end->pre = queue->first;
    return queue;
}

void Insert(Queue *queue,int data){
    QNode *t = (QNode *)malloc(sizeof(QNode));
    t->x = data;
    t->next = queue->end;
    t->pre = queue->end->pre;
    queue->end->pre->next = t;
    queue->end->pre =t;
}

void Visit(QNode *data){
    printf("%c ",b[data->x].data);
}

int isEmpty(Queue *queue){
    if(queue->first->next == queue->end) return 1;
    return 0;
}

void Delete(Queue *queue){
    if(isEmpty(queue) == 1){
        printf("栈空，删除失败\n");
        return ;
    }
    QNode *t = queue->first->next;
    Visit(t);
    queue->first->next = t->next;
    queue->first->next->pre = queue->first;
    free(t);
    t = NULL;
}

int flag[105];

int len;

int Find(char target){
    for(int i = 0 ; i< len;i++){
        if(b[i].data == target)return i;
    }
    return -1;
}

void BFS(int x){
    Queue *queue = InitQueue();
    Insert(queue ,x);
    flag[x] = 1;
    while(isEmpty(queue) == 0){
        ListNode *t = b[x].next;
        while(t != NULL){
            int index = t->x == x? t->y:t->x;
            if(flag[index] != 1){
                Insert(queue,index);
                flag[index] = 1;
            }
            if(t->x == x) t = t->xnext;
            else t = t->ynext;
        }
        Delete(queue);
    }
}

void InsertSide(int x,int y){
    ListNode *t = (ListNode *)malloc(sizeof(ListNode));
    t->x = x;
    t->y = y;
    t->xnext = b[x].next;
    b[x].next = t;
    t->ynext = b[y].next;
    b[y].next = t;
}


int main(){
    int num;
    printf("Pleace enter the number of nodes:\n");
    scanf("%d",&num);
    printf("Pleace enter those nodes:\n");
    for(int i = 0; i< num; i++){
        getchar();
        scanf("%c",&b[len].data);
        b[len].next = NULL;
        len++;
    }
    printf("Pleace enter the number of sides:\n");
    int sideNum = 0;
    scanf("%d",&sideNum);
    char x,y;
    int xi,yi;
    for(int i = 1;i<= sideNum;i++){
        printf("Please enter the description of the %dth side:",i);
        getchar();
        scanf("%c %c",&x,&y);
        xi = Find(x);
        yi = Find(y);
        InsertSide(xi,yi);
    }
    printf("开始广度优先遍历\n");
    BFS(0);
    printf("\n广度优先遍历结束\n");
    return 0;
}
/*
4
a b c d
5
a b
a c
a d
b c
d c

*/

