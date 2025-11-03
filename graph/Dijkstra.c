#include<stdio.h>
#include<stdlib.h>
#define INF 1001;

//最短路径的Dijkstra算法
//多重邻接表存图

typedef struct Node{
    int x,y,w;
    struct Node *xnext,*ynext;
}ListNode;

struct {
    int data;
    ListNode *first;
}sides[105];

int num;//表示元素的个数

int dis[105];//表示下标的点到目标点的距离
int flag[105];//表示下标点是否已确定最短路径(是否还能更改)
int pre[105];

void InitSide(int num){
    for(int i = 1 ; i<= num ;i++){
        sides[i].data = i;
        sides[i].first = NULL;
        dis[i] = INF;
        pre[i] = -1;
    }
}

void Dijkstra(int x){
        dis[x] = 0;
        for(int i = 0;i < num;i++){
            int min = INF;
            int index = -1;
            for(int i = 1;i <=num;i++){
                if(flag[i]==0 && dis[i]<min){
                    index = i;
                    min = dis[i];
                }
            }
            flag[index] = 1;
            ListNode *t = sides[index].first;
            while(t != NULL){
                if(t->x == sides[index].data){
                    if(dis[t->y] > dis[index] + t->w) {
                        dis[t->y] = dis[index] + t->w;
                        pre[t->y] = index;
                    }
                    t = t->xnext;
                }else{
                    if(dis[t->x] > dis[index] + t->w) {
                        dis[t->x] = dis[index] + t->w;
                        pre[t->x] = index;
                    }
                    t= t->ynext;
                }
            }
            printf("元素%d:%d\n",index,dis[index]);
        }
    }

int main(){
    printf("Pleace enter the number of nodes:\n");
    scanf("%d",&num);
    InitSide(num);
    int SideNum;
    printf("Pleace enter the number of sides:\n");
    scanf("%d",&SideNum);
    for(int i = 1; i<= SideNum;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        ListNode *t = (ListNode *)malloc(sizeof(ListNode));
        t->x = x,t->y = y,t->w = w;
        t->xnext = sides[x].first;
        t->ynext = sides[y].first;
        sides[x].first = t;
        sides[y].first = t;
    }

    Dijkstra(1);
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
