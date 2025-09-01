#include<stdio.h>
#include<stdlib.h>

//单向链式结构的线性表（单链表）写法：1.增->（1）头插（1）中段（2）末尾
//                    2.删
//                    3.改
//                    4.查 

typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkList;
//链表初始化
LinkList InitList(){
    Node *s = (Node*)malloc(sizeof(Node));
    s->next = NULL;
    return s;
}
//头插法
void HeadInsert(LinkList l, int k){
    Node *s = (Node*)malloc(sizeof(Node));
    s->data = k;
    s->next = l->next;
    l->next = s;
}
//尾插法
void EndInsert(LinkList l, int k){
	Node *s = (Node*)malloc(sizeof(Node));
    s->data = k;
	s->next = NULL;
	Node *p = l->next;
	while(p != NULL && p->next != NULL){
		p = p->next;
	}
	p->next = s;
}
//中段插入
void MidInsert(LinkList l,int k,int targer){
	Node *s = (Node*)malloc(sizeof(Node));
    s->data = k;
	Node *p = l->next;
	while(p != NULL &&p->data != targer){
		p = p->next;
	}
	s->next = p->next;
	p->next = s;
}

//删除元素
void Delete(LinkList l, int k){
	Node *x = l;
	Node *p = l->next;
	while(p != NULL && p->data != k){
		x = p;
		p = p->next;
	}
	x->next = p->next;
	free(p);
	p = NULL;
}
//查找
Node* Find(LinkList l,int k){
	Node *p = l ->next;
	while(p != NULL && p ->data !=k){
		p = p->next;
	}
	if(p == NULL){
		printf("shu数据不存在\n");
	}
	return p;
}

//替换
void Revise(LinkList l,int k,int targer){
	Node *p = Find(l,targer);
	if(p == NULL){
		printf("未找到");
		return l;
	}
	p->data = k;
}

//输出链表
void Printff(LinkList l){
    Node *p = l-> next;
    while(p != NULL){
        printf("%d  ",p->data);
        p = p->next;
    }
	printf("\n");
}
int main(){
    LinkList l = InitList();
    HeadInsert(l,1);
    HeadInsert(l,2);
    HeadInsert(l,3);
    HeadInsert(l,4);
    Printff(l);
	EndInsert(l, 4);
    EndInsert(l, 5);
    Printff(l);
	MidInsert(l, 6, 2);
    Printff(l); 
	Revise(l, 7, 6);
    Printff(l);
	Delete(l, 1);
    Printff(l);
	Node* s = Find(l,7);
	s == NULL?printf(""):printf("%d\n",s->data);

    return 0;
}