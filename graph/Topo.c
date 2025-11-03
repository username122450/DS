#include<stdio.h>
#include<stdlib.h>

//拓扑排序:用十字链表实现有向无环图(DAG)的存储
//图的元素与下标相同
//链栈保存入度为0的元素

typedef struct Node{
    int out;
    struct Node *innext;
}ListNode;

struct{
    int data;
    ListNode *first;
}sides[105];

int num;//元素的个数

int ind[105];//sides[i]的入度


typedef struct SNode{
    int index;
    struct SNode *next;
}LinkedSNode,*Stack;

Stack InitStack(){
    Stack stack = (Stack)malloc(sizeof(LinkedSNode));
    stack->next = NULL;
    return stack;
}

void Push(Stack stack,int data){
    LinkedSNode *t = (LinkedSNode *)malloc(sizeof(LinkedSNode));
    t->index = data;
    t->next = stack->next;
    stack->next = t;
}

void Pop(Stack stack){
    if(stack->next == NULL){
        printf("栈空,删除失败\n");
        return ;
    }
    LinkedSNode *t = stack->next;
    stack->next  = t->next;
    free(t);
    t = NULL;
}

LinkedSNode *GetElement(Stack stack){
    if(stack->next == NULL){
        printf("栈空,返回NULL值\n");
    }
    return stack->next;
}

void PrintInd(){
    for(int i = 1;i <= num; i++){
        printf("%d ",ind[i]);
    }
}

void InitNodes(){
    for(int i = 1;i <= num;i++){
        sides[i].data = i;
        sides[i].first = NULL;
    }
}

ListNode *CreateNode(int in,int out){
    ListNode *t = (ListNode *)malloc(sizeof(ListNode));
    t->out = out;
    t->innext = sides[in].first;
    sides[in].first = t;
    return t;
}

void Topo(){
    Stack stack = InitStack();
    for(int i = 1;i <= num;i++){
        if(ind[i] == 0) Push(stack,i);
    }
    int index = -1;
    for(int i = 1; i<= num;i++){
        index = GetElement(stack)->index;
        printf("%d ",index);
        Pop(stack);
        ListNode *t = sides[index].first;
        while(t != NULL){
            ind[t->out]--;
            if(ind[t->out] == 0) Push(stack,t->out);
            t = t->innext;
        }
    }
}
int main(){
    printf("Pleace enter the number of nodes:");
    scanf("%d", &num);
    InitNodes();
    int SideNum;
    printf("Pleace enter the number of sides:");
    scanf("%d",&SideNum);
    for(int i = 1;i <= SideNum;i++){
        int in,out;
        scanf("%d %d",&in, &out);
        ListNode *t = CreateNode(in,out);
        ind[out]++;
    }
    Topo();
    return 0;
}
/*
6
8
1 2
1 6
1 4
3 2
3 5
2 5
4 6
4 5
*/