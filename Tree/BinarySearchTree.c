#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *l;
    struct Node *r;
}BSTNode,*Tree;

Tree InitTree(int data){
    Tree t = (Tree)malloc(sizeof(BSTNode));
    t->l = t->r = NULL;
    t->data = data;
    return t;
}

BSTNode *CreatNewNode(int data){
    BSTNode *s = (BSTNode *)malloc(sizeof(BSTNode));
    s->data = data;
    s->l = s->r = NULL;
    return s;
}

BSTNode *Find(Tree t,int data){
    if(t == NULL){
        printf("树空\n");
        return NULL;
    }
    BSTNode *p = t;
    while(p != NULL && p->data != data){
        if(data < p->data) p = p->l;
        else p = p->r;
    }
    return p;
}

BSTNode *Find_recursion(Tree t,int data){
    if(t == NULL){
        printf("树空\n");
        return NULL;
    }
    if(t->data == data) return t;
    if(data < t->data){
        return Find_recursion(t->l,data);
    }else{
        return Find_recursion(t->r,data);
    } 
}

BSTNode *Insert (Tree t,int data){
    BSTNode *s = CreatNewNode(data);
    if(t == NULL){
        return s;
    }
    BSTNode *p = t;
    BSTNode *pre = NULL;
    while(p != NULL ){
        pre = p;
        if(data < p->data)p = p->l;
        else if(data == p->data) {
            printf("插入失败\n");
            free(s);
            return t;
        }
        else p = p-> r;
    }
    if(data < pre->data) pre->l = s;
    else pre ->r = s;
    return t;
}

BSTNode *Insert_recursion(Tree t,int data){
    if(t == NULL){
        BSTNode *s = CreatNewNode(data);
        return s;
    }
    if(t->data == data) {
        printf("插入失败\n");
        return t;
    }
    
    if(t->data > data){
        t->l = Insert_recursion(t->l,data);
    }else if(t->data < data){
        t->r = Insert_recursion(t->r,data);
    }
    return t;
}

void InOrder(Tree t){
    if(t == NULL) return ;
    InOrder(t->l);
    printf("%d  ",t->data);
    InOrder(t->r);
}

Tree Delete(Tree t,int data){
    if(t == NULL){
        printf("这是空树\n");
        return t;
    }
    BSTNode *p = t;
    BSTNode *pre = NULL;
    while(p != NULL && p->data != data){
        pre = p;
        if(data < p->data) p = p->l;
        else p = p->r;
    }
    if(p == NULL){
        printf("元素%d未找到，删除失败\n",data);
        return t;
    }

    if(p -> l !=NULL && p->r != NULL){
        BSTNode *ch = p->r;
        BSTNode *chf = p;
        while(ch->l != NULL){
            chf = ch;
            ch = ch->l;
        }
        p->data = ch->data;
        p = ch;
        pre = chf;

    }
    BSTNode *ch = NULL;
    if(p->l != NULL) ch = p->l;
    else ch = p->r;
    if(pre != NULL){
        if(data<pre->data)pre->l = ch;
        else pre->r = ch;
    }else{
        t = ch;
    }
    free(p);
    return t;
    
}

Tree Delete_recursion(Tree t,int data){
    if(t == NULL){
        printf("空树，删除失败\n");
        return t;
    }
    if(data < t->data) t->l = Delete_recursion(t->l,data);
    else if(data > t->data) t->r = Delete_recursion(t->r,data);
    else{
        if(t->l != NULL && t->r != NULL){
            BSTNode *p = t->r;
            while(p ->l != NULL){
                p = p->l;
            }
            t->data = p->data;
            t->r = Delete_recursion(t->r,p->data);
        }else{
            BSTNode *p = t;
            if(t->l != NULL) t = t->l;
            else t = t->r;
            free(p);
            p = NULL;
        }
    }
    return t;
}


int main(){
    Tree root  = NULL;
    root = Insert_recursion(root,4);
    root = Insert_recursion(root,2);
    root = Insert_recursion(root,3);
    root = Insert_recursion(root,1);
    root = Insert_recursion(root,6);
    root = Insert_recursion(root,5);
    root = Insert_recursion(root,8);
    root = Insert_recursion(root,7);

    InOrder(root);
    printf("\n");

    Delete_recursion(root,3);
    InOrder(root);
    printf("\n");
    return 0;
}