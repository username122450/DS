#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//哈夫曼树

typedef struct Node{
    int weight;//权重
    int f;//父节点下标
    int l,r;//左右子树下标
}HuffmanNode,*Tree;

void Find(HuffmanNode *tree, int *x,int *y,int n){
    int min = 0;
    for(int i = 0; i < n;i++){
        if(tree[i].f == -1){
            min = i;
            break;
        }
    }
    for(int i = min; i < n; i++){
        if(tree[i].f == -1 && tree[i].weight < tree[min].weight){
            min = i;
        }
    }
    *x = min;
    for(int i = 0;i < n;i++){
        if(tree[i].f == -1 && i != *x){
            min = i;
            break;
        }
    }
    for(int i = min;i< n;i++){
        if(tree[i].f == -1 && i != *x && tree[i].weight < tree[min].weight){
            min = i;
        }
    }
    *y = min;
}

HuffmanNode *InitTree(int frequency[],int n){
    int num = 2 * n - 1;
    HuffmanNode *tree = (HuffmanNode *)malloc(sizeof(HuffmanNode) * num);
    for(int i = 0; i  < n ; i++){
        tree[i].f = -1;
        tree[i].weight = frequency[i];
        tree[i].l = tree[i].r = -1;
    }
    for(int i = n; i < num ; i++){
        int x = 0,y = 0;
        Find(tree,&x,&y,i);
        tree[i].f = -1;
        tree[i].weight = tree[x].weight + tree[y].weight;
        tree[i].l = y;
        tree[i].r = x;
        tree[x].f = i;
        tree[y].f = i;
    }
    return tree;
}

char **CreateCode(Tree tree,int n){
    printf("指针模拟开二维数组\n");
    char *temp = (char *)malloc(sizeof(char) *n);
    int start = 0;
    temp[n-1] = '\0';
    //指针模拟申请二维数组
    char **Code = (char **)malloc(sizeof(char *) * n);
    memset(Code,0,sizeof(char*) * n);
    int p,pf;
    for(int i = 0;i < n; i++){
        start = n-1;
        p = i;
        pf = tree[p].f;
        while(pf != -1){
            if(tree[pf].l == p) temp[--start] = '0';
            else temp[--start] = '1';
            p = pf;
            pf = tree[p].f;
        }
        Code[i] = (char *)malloc(sizeof(char) * (n-start));
        strcpy(Code[i],&temp[start]);
    }
    return Code;
}

int main(){
    int n;
    scanf("%d",&n);
    char elements[105];
    int frequency[105];
    getchar();
    printf("元素：\n");
    for(int i = 0; i < n; i++){
        scanf("%c",&elements[i]);
    }
    printf("频率\n");
    for(int i = 0;i < n; i++){
        scanf("%d",&frequency[i]);
    }
    Tree tree = InitTree(frequency,n);
    char **HuffmanCode = CreateCode(tree, n);
    printf("编码\n");
    for(int i = 0; i< n;i++){
        if(i == 0) printf("%c\n",elements[i]);
        printf("%c的编码：%s\n",elements[i],HuffmanCode[i]);
    }
    return 0;
}
/*
4
5408
1 1 1 2
*/
//printf("%c:%s\n",elements[i],HuffmanCode[i]);

