#include<stdio.h>
#include<stdlib.h>

typedef struct TNode{
    int lflag;
    struct TNode *l;
    char data;
    struct TNode *r;
    int rflag;
}BTNode, *Tree;
//链式线索化二叉树节点结构

Tree InitTree(char data){
    Tree t = (Tree)malloc(sizeof(BTNode));
    t->data = data;
    t->lflag = t-> rflag = 0;
    t->l = t->r = NULL;
    return t;
}

BTNode *Find(Tree t,char father){
    if(t == NULL) return NULL;
    if(t ->data == father) return t;
    BTNode *p = NULL;
    if( t->l != NULL && t->lflag ==0 ){
        p = Find(t->l,father);
        if(p != NULL) return p;
    }
    if(t->r != NULL && t->rflag ==0){
        p = Find(t->r,father);
        if(p != NULL) return p;
    }
    return NULL;
}

void Insert(Tree t, char data,char father,int flag){
    if(t == NULL) return ;
    BTNode *p = Find(t,father);
    if(p == NULL) {
        printf("父节点未找到，插入失败\n");
        return ;
    }
    BTNode *s = (BTNode *)malloc(sizeof(BTNode));
    s->data = data;
    s->lflag = s->rflag = 0;
    s->l = s->r = NULL;
    
    if(flag == 0) p->l = s; 
    else p->r = s;
    printf("插入%c  ",data);
}


void visit(BTNode *p){
    if(p == NULL){
        printf("节点为空，访问错误\n");
        return ;
    }
    printf("%c  ",p->data);
}

void ThreadedInorder(Tree t){
    if(t->l != NULL && t->lflag != 1) ThreadedInorder(t->l);
    visit(t);
    if(t->r != NULL && t->rflag != 1) ThreadedInorder(t->r);

}

void FindRelationship(Tree t,char data){
    BTNode *pre = NULL;
    BTNode *p =Find(t,data);
    if(p ->lflag == 1){
        printf("%c的前驱是%c  ",data,p->l->data);
    }else{
        pre = p-> l ;
        if(pre == NULL) printf("%c没前驱  ",data);
        else {
            while(pre ->r != NULL && pre->rflag == 0) pre = pre -> r;
            printf("%c的前驱是%c  ",data,pre -> data);}
    }
    if(p->rflag == 1)  printf("后继是%c\n",p->r->data);
    else{
        pre = p->r;
        if(pre == NULL) printf("没后继\n");
        else{
            while(pre ->l != NULL && pre->lflag == 0) pre = pre -> l;
            printf("后继是%c\n",pre ->data);
        }
    }
    
}

int main() {
    Tree root = InitTree('A');
    
    Insert(root, 'B', 'A', 0);  
    Insert(root, 'E', 'A', 1);  
    Insert(root, 'C', 'B', 1);
    Insert(root, 'F', 'E', 1);  
    Insert(root, 'D', 'C', 0);  
    Insert(root, 'G', 'F', 0);
    Insert(root, 'H', 'G', 0);
    Insert(root, 'K', 'G', 1);

    printf("插入完成\n");

    ThreadedInorder(root);
    printf("线索化完成\n");

    FindRelationship(root,'B');

    
    
    return 0;
}