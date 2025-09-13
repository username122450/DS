#include<stdio.h>
#include<stdlib.h>
#define max 1024

//根据二叉树的关系查找父子



char* InitTree(char data){
    char *t = (char *)malloc(sizeof(char) * max);
    t[1] = data;
    return t;
}

int Find(char *t,char father){
    int i ;
    for(i = 0;i < max; i++){
        if(t[i] == father) return i;
    }
    return -1;
}

int main(){
    int TreeNum;
    scanf("%d",&TreeNum);
    getchar();
    char data;
    scanf("%c",&data);
    char *t = InitTree(data);
    char father;
    int flag;
    for(int i = 1;i < TreeNum -1; i++){
        getchar();
        scanf("%c %c %d",&data,&father,&flag);
        int fatherIndex = Find(t,father);
        if(fatherIndex == -1){
            printf("插入失败，原因：父节点不存在\n");
            continue;
        }
        if(2 * fatherIndex + flag < max){
            t[2 * fatherIndex + flag] = data;
        }else{
            printf("插入失败，原因：数组位数不支持\n");
            continue;
        }

    }
    free(t);

    
    return 0;
}