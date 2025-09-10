#include<stdio.h>
#include<stdlib.h>
#define max 20

struct {
    char data;
    int fi;
}t[max];

int len = 0;

void InitTree(char data){
    t[0].data = data;
    t[0].fi = -1;
    len++;
}

int Find(char fi){
    int i;
    for(i = 0; i < len ;i++){
        if(t[i].data == fi)
            break;
    }
    return i;
}

void Insert(char data,char fi){
    if(len == max){
        printf("数组满\n");
        return ;
    }
    int father;
    if((father = Find(fi)) == len){
        printf("双亲节点未找到\n");
        return ;
    }
    t[len].data = data;
    t[len++].fi = father;
    
}

void getChile(char data){
    int index = Find(data);
    int chileNum = 0;
    for(int i = 1; i< len;i++){
        if(t[i].fi == index){
            printf("%c ",t[i].data);
            chileNum++;
        }
    }
    if(chileNum == 0) printf("这是叶子节点");
    else printf("是%c的儿子节点",data);
    printf("\n");

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
    printf("寻找儿子节点\n");
    getChile('A');
    return 0;
}
/*
13
A
B A
C A
D A
E B
F B
G C
H D
I D
J D
K E
L E
M H
G*/