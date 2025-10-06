#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    int h;
    struct Node *l;
    struct Node *r;
}AVLNode ,*AVLTree;

AVLNode *CreateNode(int data){
    AVLNode *s = (AVLNode *)malloc(sizeof(AVLNode));
    s->l = s->r = NULL;
    s->h = 0;
    s->data = data;
    return s;
}

AVLNode *Insert(AVLTree t, int data){
    if(t == NULL) return CreataNode(data);
    if(data < t->data) t->l = Insert(t->l,data);
    else if(data > t->data) t->r = Insert(t->r,data);
    else printf("元素重复，插入失败\n");
    return t;
}

int Geth(AVLNode *e){
    if(e == NULL) return 0;
    return Geth(e->l) > Geth(e->r) ? Geth(e->l) + 1 : Geth(e->r) +1;
}

int isBalancce(AVLNode *e){
    int diff = Geth(e->l) - Geth(e->r);
    if(diff > 1) return -1;
    else if(diff < -1) return 1;
    else return 0;
}

AVLNode *Levorotation(AVLNode *e){
     AVLNode *ch = e->r;
    e->r = ch->l;
    ch->l = e;
    e->h = Geth(e);
    ch->h = Geth(ch);
    return ch;
}

AVLNode *Rightrotation(AVLNode *e){
   AVLNode *ch = e->l;
    e->l = ch->r;
    ch->r = e;
    e->h = Geth(e);
    ch->h = Geth(ch);
    return ch;
}