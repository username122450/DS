#include<stdio.h>
#include<stdlib.h>


//邻接表（这里只写了无权，有权要在节点结构体里加上weight数据）

typedef struct Node{
    int index;
    struct Node *next;
}pointNode;

struct{
    char data;
    pointNode *point;
}Graph[105];

int Find(char data){
    for(int i = 0;i < 105;i++){
        if(Graph[i].data == data) return i;
    }
    return -1;
}

pointNode *CreateNode(int index){
    pointNode *t = (pointNode *)malloc(sizeof(pointNode));
    t->index = index;
    return t;
}

int main(){
    int len;
    printf("Pleace enter the number of nodes:\n");
    scanf("%d",&len);
    printf("Please enter those nodes:\n");
    for(int i = 0; i< len ;i++){
        scanf(" %c",&Graph[i].data);
        Graph[i].point = (pointNode *)malloc(sizeof(pointNode));
        Graph[i].point->next = NULL;
    }
    int isDirection;
    printf("Directed input 1:");
    scanf("%d",&isDirection);
    int num;
    printf("Pleace enter the number of sides:");
    scanf("%d",&num);
    char start,end;
    int si,ei;
    if(isDirection == 1){
        for(int i = 1; i <= num; i++){
            printf("Please enter the description of the %dth side:",i);
            getchar();
            scanf("%c %c",&start,&end);
            si = Find(start);
            ei = Find(end);
            printf("%c :%d\n",start,si);
            printf("%c :%d\n",end,ei);
            pointNode *t = CreateNode(ei);
            t->next = Graph[si].point->next;
            Graph[si].point->next = t;
        }
    }else{
        for(int i = 1; i <= num; i++){
            printf("Please enter the description of the %dth side:",i);
            getchar();
            scanf("%c %c",&start,&end);
            si = Find(start);
            ei = Find(end);
            printf("%c :%d\n",start,si);
            printf("%c :%d\n",end,ei);
            pointNode *t = CreateNode(ei);
            t->next = Graph[si].point->next;
            Graph[si].point->next = t;
            pointNode *f = CreateNode(si);
            t->next = Graph[ei].point->next;
            Graph[ei].point->next = t;
        }
    }
    return 0;
}