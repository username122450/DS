#include<stdio.h>
#include<stdlib.h>

//双向链式结构的线性表（双链表）写法：1.增：（1）头插法；（2）尾插法；（3）中段插入；
//                                 2.删：
//                                 3.查：
//                                 4.改  
typedef struct Node{
    int data;
    struct Node *pre;
    struct Node *next;

}Node,*LinkedList;

LinkedList InitList(){
    LinkedList l = (Node *)malloc(sizeof(Node));
    l->pre = NULL;
    l->next = NULL;
    return l;
}
LinkedList HeadInsert(LinkedList l,int k){
    Node *s = (Node *)malloc(sizeof(Node));
    s->data = k;
    s->next = l->next;
    s->pre = l;
    if(l->next != NULL){
        l->next->pre = s;
    }
    l->next = s;
    
    return l;
}
LinkedList EndInsert(LinkedList l,int k){
    Node *s = (Node *)malloc(sizeof(Node));
    s->data = k;
    s->next = NULL;
    Node *p = l;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = s;
    s->pre = p;
    return l;
}
LinkedList MiddleInsert(LinkedList l,int k,int targer){
    Node *s = (Node *)malloc(sizeof(Node));
    s->data = k;
    Node *p = l->next;
    while(p != NULL && p->data != targer){
        p = p->next;
    }
    if(p == NULL){
        printf("targer值未找到，插入失败\n");
        return l;
    }
    s->next = p->next;
    s->pre = p;
    if(p->next != NULL){
        p->next->pre = s;
    }
    p->next = s;
    return l;
}
Node* Find(LinkedList l, int k){
    Node *p = l->next;
    while(p != NULL && p->data != k){
        p = p-> next;
    }
    if(p == NULL) printf("数据不存在\n");
    
    return p;
}

LinkedList Delete(LinkedList l,int k){
    Node *p = Find(l,k);
    if(p == NULL) {
        printf("删除失败\n");
        return l;
    }
    if(p -> next != NULL){
        p->next->pre = p->pre;
    }
    p->pre->next = p->next;
    free(p);
    p = NULL;
    return l;
}

LinkedList Revise(LinkedList l,int k,int targer){
    Node *p = Find(l,targer);
    if(p == NULL){
        printf("修改失败\n");
        return l;
    }
    p->data = k;
    return l;
}

void Printff(LinkedList l){
    Node *p = l->next;
    while(p != NULL){
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
    Printff(l);
    l = EndInsert(l,4);
    l = EndInsert(l,5);
    Printff(l);
    l = MiddleInsert(l,6,3);
    l = MiddleInsert(l,7,5);
    Printff(l);
    l = Delete(l,3);
    l = Delete(l,4);
    Printff(l);
    l = Revise(l,9,5);
    Printff(l);
    
    
    return 0;
}
