#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char data;
    struct Node *l;
    struct Node *r;
}BTree,*Tree;

Tree InitTree(char data){
    Tree t = (BTree *)malloc(sizeof(BTree));
    t->data = data;
    t->l = t->r = NULL;
    return t;
}

BTree *Find(Tree t,char father){
    if(t->data == father) return t;
    BTree *p = NULL;
    if(t->l != NULL){
        p = Find(t->l,father);
        if(p != NULL) return p;
    }
    if(t-> r != NULL){
        p = Find(t->r, father);
        if(p != NULL) return p;
    }
    return NULL;
}

void Insert(Tree t,char data, char father,int flag){
    BTree *s = (BTree *)malloc(sizeof(BTree));
    s->data = data;
    s->l = s->r = NULL;
    BTree *fa = Find(t,father);
    if(fa == NULL){
        printf("父元素未找到，插入失败\n");
        return ;
    }
    if(flag == 0){
        fa->l = s;
        return ;
    }
    else if(flag == 1){
        fa->r = s;
    }
    else{
        printf("未找到%d位置\n",flag);
    }
}

//非递归版先序中序后序写法(栈)

typedef struct Node1{
    BTree *data;
    struct Node1 *next;
}SNode,*Stack;

Stack InitStack(){
    Stack s = (Stack)malloc(sizeof(SNode));
    s->next = NULL;
    return s;
}

void Push(Stack stack,BTree *p){
    SNode *s = (SNode *)malloc(sizeof(SNode));
    s->data = p;
    s->next = stack->next;
    SNode *t = stack;
    stack->next = s;
}

BTree *GetElement(Stack stack){
    if(stack ->next ==NULL) {
        printf("当前栈空\n");
        return NULL;
    }
    return stack->next->data;
}

int isEmpty(Stack stack){
    if(stack ->next == NULL) {
        printf("栈空\n");
        return 1;
    }
    return 0;
}

void Pop(Stack stack){
    if(isEmpty(stack) == 1) return ;
    stack->next = stack->next->next;
}

void Visit(BTree *p){
    printf("%c  " , p->data);
}

void Preorder(Tree tree){
    Stack stack = InitStack();
    BTree *p = tree;
    if(tree == NULL) {
        printf("树空\n");
        return ;
    }
    while(p != NULL ||isEmpty(stack) == 0 ){
        if(p == NULL){
            p = GetElement(stack)->r;
            Pop(stack);
        }else{
            Visit(p);
            Push(stack,p);
            p = p->l;
        }
    }
    printf("\n先序遍历完成\n");
}

void Inorder(Tree tree){
    Stack stack = InitStack();
    BTree *p = tree;
    if(tree == NULL) {
        printf("树空\n");
        return ;
    }
    while(p != NULL ||isEmpty(stack) == 0){
        if(p == NULL){
            p = GetElement(stack);
            Visit(p);
            p = p->r;
            Pop(stack);
        }else{
            Push(stack,p);
            p = p -> l;
        }
    }
    printf("\n中序遍历完成\n");
}

void Postorder(Tree tree){
    Stack stack = InitStack();
    BTree *p = tree;
    BTree *pre = NULL;
    if(tree == NULL) {
        printf("树空\n");
        return ;
    }
    while(p != NULL ||isEmpty(stack) == 0){
        if(p == NULL){
            BTree *temp = GetElement(stack);
            if( pre != temp -> r && temp -> r != NULL  ){
                p = temp->r;
            }else{
                Visit(temp);
                pre = temp;
                Pop(stack);
            }

        }else{
            Push(stack ,p);
            pre = p;
            p = p->l;
        }
    }
    printf("\n后序遍历完成\n");
}



int main() {
    BTree *root = InitTree('A');
    
    Insert(root, 'B', 'A', 0);  
    Insert(root, 'E', 'A', 1);  
    Insert(root, 'C', 'B', 1);
    Insert(root, 'F', 'E', 1);  
    Insert(root, 'D', 'C', 0);  
    Insert(root, 'G', 'F', 0);
    Insert(root, 'H', 'G', 0);
    Insert(root, 'K', 'G', 1);

    Preorder(root);

    Inorder(root);

    Postorder(root);
    
    return 0;
}