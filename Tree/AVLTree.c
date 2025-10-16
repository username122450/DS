#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    int h;
    struct Node *l;
    struct Node *r;
}AVLNode ,*AVLTree;

AVLTree CreateNode(int data){
    AVLNode *s = (AVLNode *)malloc(sizeof(AVLNode));
    s->l = s->r = NULL;
    s->h = 1;
    s->data = data;
    return s;
}

int Geth(AVLNode *e){
    if(e == NULL) return 0;
    return e->h;
}

int calculateh(AVLNode *e){
    if(e == NULL) return 0;
    return Geth(e->l) > Geth(e->r) ? Geth(e->l) + 1 : Geth(e->r) +1;
}

AVLNode *RRrotation(AVLNode *e){
    AVLNode *ch = e->r;
    e->r = ch->l;
    ch->l = e;
    e->h = calculateh(e);
    ch->h = calculateh(ch);
    return ch;
}

AVLNode *LLrotation(AVLNode *e){
   AVLNode *ch = e->l;
    e->l = ch->r;
    ch->r = e;
    e->h = calculateh(e);
    ch->h = calculateh(ch);
    return ch;
}

AVLNode *LRrotation(AVLNode *e){
    e->l = RRrotation(e->l);
    return LLrotation(e);
}

AVLNode *RLrotation(AVLNode *e){
    e->r = LLrotation(e->r);
    return RRrotation(e);
}

AVLTree Insert(AVLTree t, int data){
    if(t == NULL) return CreateNode(data);
    if(data < t->data) {
        t->l = Insert(t->l,data);
        if(Geth(t->l->l) - Geth(t->l->r) >= 2) t->l = LLrotation(t->l);
        else if(Geth(t->l->r) - Geth(t->l->l) >= 2)t->l = LRrotation(t->l);
    }
    else if(data > t->data) {
        t->r = Insert(t->r,data);
        if(Geth(t->r->l) - Geth(t->r->r) >= 2) t->r = RLrotation(t->r);
        else if(Geth(t->r->r) - Geth(t->r->l) >= 2) t->r = RRrotation(t->r);
    }
    else printf("元素重复，插入失败\n");
    t->h = calculateh(t);
    return t;
}

AVLTree Delete(AVLTree t,int data){
    if(t == NULL){
        printf("元素未找到\n");
        return t;
    }
    if(data < t->data) {
        t->l = Delete(t->l,data);
        if(Geth(t->r) - Geth(t->l) > 1){
            //RR or RL
            if(Geth(t->r->r) >=Geth(t->r->l) )  t = RRrotation(t);
            else t = RLrotation(t);
        }
    }else if(data > t->data){
        t->r = Delete(t->r,data);
        if(Geth(t->l) - Geth(t->r) > 1){
            if(Geth(t->l->l) >= Geth(t->l->r)) t = LLrotation(t);
            else t = LRrotation(t);
        }
    }else {
        if(t->l !=NULL && t->r != NULL){
            AVLNode *p = t->r;
            while(p->l !=NULL){
                p = p->l;
            }
            t->data = p->data;
            t->r = Delete(t->r,p->data);
        }else{
            AVLTree p = t;
            if(t->l != NULL) t = t->l;
            else t = t->r;
            free(p);
            p = NULL;
        }
    }
    if(t != NULL) t->h = calculateh(t);
    return t;
}

void InOrder(AVLTree t){
    if(t == NULL) return ;
    InOrder(t->l);
    printf("%d  ",t->data);
    InOrder(t->r);
}

int main(){
    AVLTree root  = NULL;
    root = Insert(root,4);
    root = Insert(root,2);
    root = Insert(root,3);
    root = Insert(root,1);
    root = Insert(root,6);
    root = Insert(root,5);
    root = Insert(root,8);
    root = Insert(root,7);

    InOrder(root);
    printf("\n");

    Delete(root,3);
    InOrder(root);
    printf("\n");
    return 0;
}

