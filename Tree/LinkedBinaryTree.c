#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char data;
    struct Node *l;
    struct Node *r;
}BTNode,*BTree;

BTree InitTree(char data){
    BTree t = (BTNode *)malloc(sizeof(BTNode));
    t->data = data;
    t->l = t->r = NULL;
    return t;
}

BTNode *Find(BTree t,char father){
    if(t->data == father){
        return t;
    }
    BTNode *p ;
    if(t->l != NULL){
        p = Find(t->l,father);\
        if(p != NULL){
            return p;
        }
    }
    if(t->r != NULL){
        p = Find(t->r,father);
        if(p != NULL){
            return p;
        }
    }
    return NULL;
}



void Insert(BTree t,char data,char father,int flag){
    BTNode *s = (BTNode *)malloc(sizeof(BTNode));
    s->data = data;
    s->l = s->r = NULL;
    BTNode *p = Find(t,father);
    if(p == NULL){
        return ;
    }
    if(flag == 0){
        p->l = s;
    }else{
        p->r = s;
    }
    printf("%c插入成功\n",data);
}

void Delete(BTree t){
    free(t);
}

int main() {
    BTree root = InitTree('A');
    
    Insert(root, 'B', 'A', 0);  
    Insert(root, 'C', 'A', 1);  
    Insert(root, 'D', 'B', 0);  
    Insert(root, 'E', 'B', 1);  
    
    Delete(root);
    
    return 0;
}