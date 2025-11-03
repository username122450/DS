#include<stdio.h>
#include<stdlib.h>
#define INF 1001;

//Prim算法求最小生成树的权值
//邻接表存图

typedef struct Node{
    int x;
    int y;
    int w;
    struct Node *xnext;
    struct Node *ynext;
}ListNode;

struct{
    int data;
    ListNode *first;
}sides[105];

int flag[105];//保存下标为i的点是否收入到最小生成树中
int dis[105];//下标为i的点到最小生成树的距离
int len;//元素个数
int minSum;//最小生成树权值和

void InitSide(int num){
    for(int i = 1; i<= num ;i++){
        sides[i].data = i;
        sides[i].first = NULL;
        flag[i] = 0;
        dis[i] = INF;
    }
}

void Prim(int x){
    dis[x] = 0;
    int index;
    int min;
    ListNode *t = NULL;
    for(int i = 0 ; i< len;i++){
        index = -1;
        min = INF;
        for(int j = 1; j<= len;j++){
            if(flag[j] == 0 && dis[j] < min){
                min = dis[j];
                index = j;
            }
        }
        printf("%d ",sides[index].data);
        flag[index] = 1;
        minSum+=min;
        t = sides[index].first;
        while(t != NULL){
            if(t->x == index){
                if(dis[t->y] > t->w) dis[t->y] = t->w;
                t = t->xnext;
            }else{
                if(dis[t->x] > t->w) dis[t->x] = t->w;
                t =t->ynext;
            }
        }
    }
}

int main(){
    printf("Pleace enter the number of nodes:");
    scanf("%d",&len);
    InitSide(len);
    int num = 0;
    printf("Pleace enter the number of sides:");
    scanf("%d",&num);
    
    for(int i = 0 ; i < num; i++){
        ListNode *node = (ListNode *)malloc(sizeof(ListNode));
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        node->x = x;
        node->y = y;
        node->w = w;
        node->xnext = sides[x].first;
        sides[x].first = node;
        node->ynext = sides[y].first;
        sides[y].first = node;
    }
    printf("开始Prim算法\n");
    Prim(1);
    printf("结束\n");
    printf("%d",minSum);
    return 0;
}
/*
9
15
9 1 3
9 5 4
1 6 6
1 2 8
1 8 5
2 8 2
2 3 12
8 3 11
6 5 7
6 7 9
6 3 14
7 3 6
7 4 1
3 4 10
5 4 18

*/
