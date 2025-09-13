#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    char data;
    struct Node *son;
    struct Node *bro;
}TNode,*Tree;

Tree InitTree(char data){
    Tree t = (Tree)malloc(sizeof(TNode));
    t->data = data;
    t->son = NULL;
    t->bro = NULL;
    return t;
}

TNode* Find(Tree t,char father){
    if(t->data == father){
        return t;
    }
    TNode *p  = NULL;
    if(t->bro != NULL){
        p = Find(t->bro,father);
        if(p != NULL){
            return p;
        }
    }
    if(t->son != NULL){
        p = Find(t->son,father);
        if(p != NULL){
            return p;
        }
    }
    return NULL;

}

void Insert(Tree t,char data, char father){
    TNode *p = Find(t,father) ;
    TNode *s = (TNode *)malloc(sizeof(TNode));
    s->data = data;
    if(p == NULL){
        printf("双亲结点错误，未查找到\n");
        return ;
    }
    s->bro = NULL;
    s->son = NULL;
    if(p->son == NULL){
        p->son = s;
    }
    p = p->son;
    while(p->bro != NULL){
        p = p->bro;
    }
    p->bro = s;
}
