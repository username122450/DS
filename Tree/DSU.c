#include<stdlib.h>
#include<stdio.h>

//并查集：Find     Union

typedef struct{
    int *set;
    int *seth;
}Set;

Set *InitSet(){
    Set *set = (Set *)malloc(sizeof(Set));
    set->set = (int *)malloc(sizeof(int ) * 105);
    for(int i = 0;i < 105; i++){
        set->set[i] = i;
    }
    set->seth = (int *)malloc(sizeof(int )*105);
    for(int i = 0;i < 105; i++){
        set->seth[i] = 1;
    }
    return set;
}

int Find(Set *set,int data){
    if(set->set[data] == data) return data;
    int fx = Find(set,set->set[data]);
    set->set[data] = fx;
    return fx;
}

void Union(Set *set,int data01,int data02){
    int f1 = Find(set,data01);
    int f2 = Find(set,data02);
    if(set->seth[f1] >= set->seth[f2]) {
        set->set[f2] = f1;
        if(set->seth[f1] == set->seth[f2] + 1) set->seth[f1] ++;
    }
    else set->set[f1] = f2;
}

int main(){
    Set *set = InitSet();
    int n,op;
    scanf("%d",&n);
    int x,y;
    for(int i = 0 ; i < n ; i++){
        scanf("%d %d %d",&op,&x,&y);
        if(op == 0){
            if(Find(set,x) == Find(set,y)) printf("yes\n");
            else printf("no\n");
        }else Union(set,x,y);
    }
    return 0;
    
}