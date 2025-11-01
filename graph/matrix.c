#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//邻接矩阵实现有向，无向，有权，无权的图的存储
int flag[105];

typedef struct{
    char *v;
    int len;
    int **matrix;
    int isWeight;
    int isDirection;
}Matrix;

Matrix *InitMatrix(int len,int isWeight,int isDirection){
    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
    matrix->v = (char *)malloc(sizeof(char ) * 105);
    matrix->len = len;
    matrix->isDirection = isDirection;
    matrix->isWeight = isWeight;
    matrix->matrix = (int **)malloc(sizeof(int *) * len);
    for(int i = 0; i < len ;i ++){
        matrix->matrix[i] = (int *)malloc(sizeof(int ) * len);
        if(isWeight == 1) memset(matrix->matrix[i],10001,len);
        else memset(matrix->matrix[i],0,len);
    }
    return matrix;
}

int Find(char *graph,char data,int len){
    for(int i= 0; i < len ; i++){
        if(graph[i] == data) return i;
    }
    return -1;
}

void DFS(Matrix *matrix,int x){
    flag[x] = 1;
    printf("%c",matrix->v[x]);
    for(int i = 0;i<matrix->len;i++){
        if(matrix->matrix[x][i] == 1 && flag[i]== 0){
            DFS(matrix,i);
        }
    }
}

int main(){
    
    int len;
    printf("请输入点的个数：\n");
    scanf("%d",&len);
    
    int isDirection,isWeight;
    printf("有向输入1，有权输入1，空格隔开\n");
    scanf("%d %d",&isDirection,&isWeight);
    Matrix *matrix = InitMatrix(len,isWeight,isDirection);
    printf("输入点：\n");
    for(int i = 0; i < len;i++){
        scanf(" %c",&matrix->v[i]);
    }
    int num;
    printf("输入边的数量：\n");
    scanf("%d",&num);
    if(isDirection == 1 && isWeight == 1){
        //有向有权图
        for(int i = 1; i<= num;i++){
            printf("输入第%d条边的描述：\n",i);
            char x,y;
            int weight;
            getchar();
            scanf("%c %c %d", &x,&y,&weight);
            int xi = Find(matrix->v,x,len);
            int yi = Find(matrix->v,y,len);
            printf("%c :%d\n",x,xi);
            printf("%c :%d\n",y,yi);
            matrix->matrix[xi][yi] = weight;
        }
    }else if(isDirection == 1 && isWeight == 0){
        //有向无权图
        for(int i = 1; i<= num;i++){
            printf("输入第%d条边的描述 ：\n",i);
            char x,y;
            scanf(" %c %c\n", &x,&y);
            int xi = Find(matrix->v,x,len);
            int yi = Find(matrix->v,y,len);
            matrix->matrix[xi][yi] = 1;
        }
    }else if(isDirection == 0 && isWeight == 1){
        //无向有权图
        for(int i = 1; i<= num;i++){
            printf("输入第%d条边的描述：\n",i);
            char x,y;
            int weight;
            scanf(" %c %c %d\n", &x,&y,&weight);
            int xi = Find(matrix->v,x,len);
            int yi = Find(matrix->v,y,len);
            matrix->matrix[xi][yi] = weight;
            matrix->matrix[yi][xi] = weight;
        }
    }else{
        printf("无向无权图\n");
        for(int i = 1; i<= num;i++){
            printf("输入第%d条边的描述：\n",i);
            char x,y;
            getchar();
            scanf("%c %c",&x,&y);
            int xi = Find(matrix->v,x,len);
            printf("%c %d\n",x,xi);
            int yi = Find(matrix->v,y,len);
            printf("%c %d\n",y,yi);
            matrix->matrix[xi][yi] = 1;
            matrix->matrix[yi][xi] = 1;
        }
    }
    DFS(matrix,0);
    return 0;
}
/*
4
0 0
a b c d
5
a b
a c
a d
b c
d c

*/
