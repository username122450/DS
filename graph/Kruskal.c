#include<stdio.h>
#include<stdlib.h>

//最小生成树的Kruskal算法

//点的数据为点的下标，即1的数据是1，2的数据是2
//边集数组保存边

struct{
    int x;
    int y;
    int w;
}sides[105];

int len;
int minSum;

int f[105];

void InitDSU(){
    for(int i = 1; i <= len; i++){
        f[i] = i;
    }
}

int Find(int x){
    if(f[x] == x) return x;
    else {
        int fx = Find(f[x]);
        f[x] = fx;
        return fx;
    }
}

void Sort(){
    for(int i = 1; i <= len; i++){
        int min = i;
        for(int j = i + 1 ; j<= len;j++){
            if(sides[j].w < sides[min].w) min = j;
        }
        int x = sides[i].x,y = sides[i].y,w = sides[i].w;
        sides[i].x = sides[min].x;
        sides[i].y = sides[min].y;
        sides[i].w = sides[min].w;
        sides[min].x = x;
        sides[min].y = y;
        sides[min].w = w;
        printf("%d %d %d\n",sides[i].x,sides[i].y,sides[i].w);
    }
}

void Kruskal(){
    InitDSU();
    for(int i = 1 ; i <= len ; i++){
        int xf = Find(sides[i].x);
        int yf = Find(sides[i].y);
        if(xf != yf){
            f[yf] = xf;
            minSum += sides[i].w;
            printf("%d  ",sides[i].w);
        }
    }
    printf("\n%d ",minSum);
}

int main(){
    int num;
    printf("Pleace enter the number of sides:\n");
    scanf("%d",&num);
    for(int i = 1;i <= num;i++){
        printf("Please enter the description of the %dth side:",i);
        scanf("%d %d %d",&sides[i].x,&sides[i].y,&sides[i].w);
        len++;
    }
    Sort();
    Kruskal();
    return 0;
}
/*
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