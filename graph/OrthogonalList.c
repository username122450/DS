#include<stdio.h>
#include<stdlib.h>

//十字链表实现有向图，带权图需要在ListNode中加入int weight

typedef struct Node{
    int start;
    int end;
    struct Node *startnext;
    struct Node *endnext;
}ListNode;

struct {
    char data;
    ListNode *out;
    ListNode *in;
}OrthogonalList[105];

int len = 0;

int Find(char target){
    for(int i = 0; i < len; i++){
        if(OrthogonalList[i].data = target) return i;
    }
    return -1;
}

void AddPoint(char data){
    OrthogonalList[len].data = data;
    OrthogonalList[len].in = NULL;
    OrthogonalList[len].out = NULL;
    len++;
}

void Insert(char start,char end){
    int si = Find(start);
    int ei = Find(end);
    ListNode *t = (ListNode *)malloc(sizeof(ListNode));
    t->start = si;
    t->startnext = OrthogonalList[si].in;
    OrthogonalList[si].in = t;
    t->end = ei;
    t->endnext = OrthogonalList[ei].out;
    OrthogonalList[ei].out = t;
}

int main(){
    printf("Pleace enter the number of nodes:\n");
    int nodelen = 0;
    scanf("%d",&nodelen);
    printf("Pleace enter those nodes:\n");
    char data;
    for(int i = 0; i< nodelen;i++){
        printf("%d\n",i);
        scanf(" %c",&data);
        AddPoint(data);
    }
    int num = 0;
    printf("Pleace enter the number of sides:\n");
    scanf("%d",&num);
    char start;
    char end;

    for(int i = 1;i <= num;i++){
        printf("Please enter the description of the %dth side:",i);
        scanf(" %c %c",&start,&end);
        Insert(start,end);
    }
    return 0;
}