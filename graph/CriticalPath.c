#include<stdio.h>
#include<stdlib.h>
#define INF 1001
//求关键路径需求关键活动,求关键活动需求关键事件
//关键路径可能不是唯一的,最后得出的关键路径只是其中之一,但关键路径长度是固定的

int EGV[105],LGV[105];//关键事件的最小开始时间和最晚开始时间
int ind[105];

typedef struct Node{
    int index,w;
    int EGE,LGE;
    struct Node *next;
}ListNode;

struct{
    int data;
    ListNode *first;
}sides[105];//用十字链表存储有向无环图(DAG)

int num;//储存事件(点)的个数

void InitSide(){
    for(int i = 1;i <= num;i++){
        sides[i].data =i;//元素的内容定义为下标,仅做方便使用
        sides[i].first = NULL; 
        ind[i] = 0;
        EGV[i] = 0;//每次都是找最大都赋值为0
        LGV[i] = INF;
    }
}

ListNode *CreateNode(int index,int w){
    ListNode *t = (ListNode *)malloc(sizeof(ListNode));
    t->index = index;
    t->w = w;
    t->EGE = 0;
    t->LGE = INF;
    return t;
}

/*
先用拓扑排序保存顺序在栈中,这一步骤得出事件的最早开始时间,
然后在栈中读取元素,得出时间的最晚开始时间
最后得出活动的最早开始时间和最晚开始时间
*/

typedef struct snode{
    int data;
    struct snode *next;
}SNode ,*Stack;//定义栈暂存拓扑排序元素

Stack InitStack(){
    Stack stack = (Stack)malloc(sizeof(SNode));
    stack->next = NULL;
    return stack;
}

void Insert(Stack stack,int data){
    SNode *t = (SNode *)malloc(sizeof(SNode));
    t->data = data;
    t->next = stack->next;
    stack->next = t;
}

SNode *GetElement(Stack stack){
    if(stack->next == NULL) printf("栈空\n");
    return stack->next;
}

void Pop(Stack stack){
    if(stack->next == NULL){
        printf("栈空,删除失败\n");
        return ;
    }
    SNode *t = stack->next;
    stack->next = t->next;
}

void PrintStack(Stack stack){
    SNode *t = stack->next;
    while(t != NULL){
        printf("%d  ",t->data);
        t = t->next;
    }
    printf("\n");

}

int *Topo(){
    int *temp = (int *)malloc(sizeof(int) * num);
    int n = 0;
    Stack stack = InitStack();
    for(int i = 1;i <= num;i++){
        if(ind[i] == 0) {
            Insert(stack,i);
        }
    }
    PrintStack(stack);
    SNode *t;
    ListNode *l;
    int e;
    while(stack ->next != NULL){
        t = GetElement(stack);
        Pop(stack);
        e = t->data;
        temp[n++] = e;
        l = sides[e].first;
        while(l != NULL){
            ind[l->index]--;
            if(l->w + EGV[e] > EGV[l->index]) EGV[l->index] = l->w + EGV[e];//给EGV赋值的位置
            if(ind[l->index] == 0) {
                Insert(stack,l->index);
            }
            l = l->next;
        }
    }
    return temp;
}

/*
拓扑排序:
在添加边时统计每个元素的入度
开始循环:找每个入度为零的点,并将他们放入栈中
遍历栈中元素,访问后将其邻接点的入度-1,如果入度变为0,则将其入栈
*/

void PrintArray(int arr[]){
    printf("\n");
    for(int i = 1;i <= num;i++){
        printf("%d:%d  ",i,arr[i]);
    }
    printf("\n");
}

void CalculateLGV(){
    int t = num;
    LGV[t] = EGV[t];
    ListNode *l ;
    t--;
    while(t > 0){
        printf("%d\n",t);
        int min = INF;
        l = sides[t].first;
        while(l != NULL){
            if(LGV[l->index] - l->w < min) min = LGV[l->index] - l->w;
            l = l->next;
        }
        LGV[t] = min;
        t--;
    }
}

void CalculateEGE(){
    printf("活动最早发生时间:\n");
    for(int i = 1;i <= num ;i++){
        ListNode *t = sides[i].first;
        while(t != NULL){
            t->EGE = EGV[i];
            printf("%d->%d:%d\n",i,t->index,t->EGE);
            t = t->next;
        }
    }
}

int CalculateLGE(){
    printf("活动最晚发生时间:\n");
    for(int i = 1;i <= num;i++){
        ListNode *t = sides[i].first;
        while(t != NULL){
            if(LGV[t->index] - t->w < t->LGE) t->LGE = LGV[t->index] - t->w;
            printf("%d->%d:%d\n",i,t->index,t->LGE );
            t = t->next;
        }
    }
}

int CriticalPath(){
    int *Order = Topo();
    PrintArray(Order);
    printf("拓扑完成\n");
    
    printf("事件最早发生时间:\n");
    PrintArray(EGV);
    printf("事件最晚发生时间:\n");
    PrintArray(LGV);
    CalculateEGE();
    CalculateLGE();
    printf("关键路径:\n");
    int sum = 0;
    int index = Order[0];
    printf("%d",index);
    while(index != Order[num-1]){
        ListNode *t = sides[index].first;
        while(t != NULL){
            if(t->EGE == t->LGE){
                printf("->%d",t->index);
                sum += t->w;
                index = t->index;
                break; 
            }
            t = t->next;
        }
        
    }
    return sum;
}

int main(){
    printf("Pleace enter the number of nodes:\n");
    scanf("%d",&num);
    InitSide();
    printf("Pleace enter the number of sides:\n");
    int SideNum;
    scanf("%d",&SideNum);
    int start,end,w;
    ListNode *t;
    for(int i = 0;i< SideNum;i++){
        scanf("%d %d %d",&start,&end,&w);
        t = CreateNode(end,w);
        t->next = sides[start].first;
        sides[start].first = t;
        ind[end]++;
    }
    int sum = CriticalPath();
    printf("这张图的关键路径长度为:%d\n",sum);
    return 0;
}
/*
6
7
1 2 4
1 3 6
2 3 5
3 4 4
4 6 3
3 5 3
5 6 3
*/