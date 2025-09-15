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

//链式队列节点的结构体声明
typedef struct Node02{
    BTNode *data;
    struct Node02 *next;
}QNode,*QHNode;

//链式队列的结构体声明
typedef struct {
    QHNode front;
    QHNode rear;
}Queue;

//链式队列的初始化
Queue* InitQUeue(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = (QHNode)malloc(sizeof(QNode));
    q->front->next = NULL;
    return q;
}

//链式队列入队使用尾插法
void Push(Queue* q,BTNode *element){
    QNode *s = (QNode *)malloc(sizeof(QNode));
    s->data = element;
    s->next = NULL;
    q->rear->next = s;
    q->rear = s;
    // printf("%c入队\n",element->data);
}

int isEmpty(Queue *q){
    if(q->front == q->rear) return 1;
    return 0;
}

//二叉树广度遍历，元素出队时将元素的左右子节点入队
void Pop(Queue* q){
    if(isEmpty(q) == 1) {
        printf("队空\n");
        return ;
    }
    QNode *s = q->front->next;
    q->front->next = s->next;
    if(q->front->next == NULL){
        q->rear = q->front;
    }
    printf("%c  ",s->data->data);
    if(s->data->l != NULL){
        Push(q,s->data->l);
    }
    if(s->data->r != NULL){
        Push(q,s->data->r);
    }
    
    free(s);
    s = NULL;
}

//链式二叉树基于链式队列的广度优先遍历
void QueueTraverse(BTree t){
    Queue *q = InitQUeue();
    Push(q,t);
    while(isEmpty(q) != 1){
        Pop(q);
    }
    printf("循环完毕\n");
}

//先序遍历
void Preorder(BTree t){
    if(t == NULL) return ;
    printf("%c  ",t->data);
    Preorder(t->l);
    Preorder(t->r);
}

//中序遍历
void Inorder(BTree t){
    if(t == NULL) return ;
    Inorder(t->l);
    printf("%c  ",t->data);
    Inorder(t->r);
}

//后序遍历
void Postorder(BTree t){
    if(t == NULL) return ;
    Postorder(t->l);
    Postorder(t->r);
    printf("%c  ",t->data);
}

int main() {
    BTree root = InitTree('A');
    
    Insert(root, 'B', 'A', 0);  
    Insert(root, 'E', 'A', 1);  
    Insert(root, 'C', 'B', 1);
    Insert(root, 'F', 'E', 1);  
    Insert(root, 'D', 'C', 0);  
    Insert(root, 'G', 'F', 0);
    Insert(root, 'H', 'G', 0);
    Insert(root, 'K', 'G', 1);

    // QueueTraverse(root);
    Preorder(root);
    printf("\n");
    Inorder(root);
    printf("\n");
    Postorder(root);
    printf("\n");
    
    Delete(root);
    
    return 0;
}





