#include<stdio.h>
#include<stdlib.h>
#define max 20

typedef struct CNode{
    int childindex;
    struct CNode *bro;
}ChildNode;

struct {
    char data;
    ChildNode *son;
}t[max];

int len;

void InitTree(char data){
    t[len].data = data;
    t[len].son = NULL;
    len++;
}

int getFather(char fdata){
    int i;
    for(i = 0; i < len && i < max;i++){
        if(t[i].data == fdata){
            break;
        }
    }
    return i;
};

void Insert(char data, char fdata){
    if(len > max){
        printf("数组满\n");
        return ;
    }
    t[len].data = data;
    t[0].son = NULL; 
    int fdataIndex = getFather(fdata);
    if(fdataIndex == len) {
        printf("父节点不存在\n");
        return ;
    }
    ChildNode *s = (ChildNode*)malloc(sizeof(ChildNode));
    s->childindex = len;
    s->bro = t[fdataIndex].son;
    t[fdataIndex].son = s;
    len++;
}

int main(){
    int dataNum ;
    scanf("%d",&dataNum);
    getchar();
    char data;
    char fi;
    scanf("%c",&data);
    InitTree(data);
    for(int i = 0; i < dataNum - 1;i++){
        getchar();
        scanf("%c %c",&data,&fi);
        Insert(data,fi);
        printf("%c\n",data);
    }
    return 0;
}


