#include<stdio.h>
#include<stdlib.h>
//双向循环链式结构的线性表写法:1.增：（1）头插法；（2）尾插法；（3）中段插入；
//                                 2.删：
//                                 3.查：
//                                 4.改  
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *pre;
}Node,*LinkedList;

LinkedList InitList(){
    LinkedList l = (Node *)malloc(sizeof(Node));
    l->next = l;
    l->pre = l;
    return l;
}

LinkedList HeadInsert(LinkedList l,int k){
    Node *s = (Node *)malloc(sizeof(Node));
    s->data = k;
    s->next = l->next;
    s->pre = l;
    l->next->pre = s;
    l->next = s;
    return l;
}

LinkedList EndInsert(LinkedList l,int k){
    Node *s = (Node *)malloc(sizeof(Node));
    s->data = k;
    s->next = l;
    l->pre->next = s;
    l->pre = s;
    return l;
}

LinkedList MiddleInsert(LinkedList l,int k,int target){
    Node *s = (Node *)malloc(sizeof(Node));
    s->data = k;
    Node *p = l->next;
    while(p != l && p->data != target){
        p = p->next;
    }
    if(p == l){
        printf("元素不存在，插入失败\n");
        return l;
    }
    s->next = p->next;
    s->pre = p;
    p->next->pre = s;
    p->next = s;
    return l;
}

Node* Find(LinkedList l, int k){
    Node *p = l->next;
    while( p != l && p -> data != k){
        p = p ->next;
    }
    if(p == l){
        printf("元素不存在\n");
        return NULL;
    }

    return p;
}

LinkedList Delete(LinkedList l,int k){
    Node *p = Find(l,k);
    if(p == NULL){
        printf("删除失败\n");
        return l;
    }
    p->pre->next = p->next;
    p->next->pre = p->pre;
    free(p);
    p = NULL;

    return l;
}


LinkedList Revise(LinkedList l, int newval, int oldval){
    Node *p = Find(l,oldval);
    if(p == NULL) {
        printf("替换失败\n");
        return l;
    }
    p->data = newval;
    return l;
}

void Printf(LinkedList l){
    Node *p = l->next;
    while(p != l){
        printf("%d  ",p->data);
        p = p->next;
    }
    printf("\n");
    return ;
}
int main(){
    LinkedList l = InitList();
    l = HeadInsert(l,1);
    l = HeadInsert(l,2);
    l = HeadInsert(l,3);
    Printf(l);
    l = EndInsert(l,4);
    l = EndInsert(l,5);
    Printf(l);
    l = MiddleInsert(l,6,1);
    l = MiddleInsert(l,7,4);
    Printf(l);
    l = Delete(l,7);
    l = Delete(l,1);
    Printf(l);
    l = Revise(l,8,2);
    Printf(l);
    return 0;
}