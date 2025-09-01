#include<stdio.h>
#include<stdlib.h>

//顺序结构的线性表（顺序表）写法：1.增->（1）中段（2）末尾
//                    2.删
//                    3.改
//                    4.查 
#define maxx 20
//结构体声明
typedef struct List {
    int len;
    int *ArrayList;
}Array;
//顺序表初始化
Array InitArray(Array a){
    a.len = 0;
    a.ArrayList = (int *)malloc(sizeof(int) * 10);
    return a;
}
//末尾插入数据
Array EndAdd (Array a,int k){
    if(a.len == maxx){
        printf("线性表已满,添加失败\n");
        return a;
    }
    a.ArrayList[a.len++] =k;
    return a; 
}
//中段插入数据
Array MiddleAdd(Array a, int targer, int k){
    if(targer >= a.len){
        EndAdd(a,k);
    }
    for(int i = a.len; i > targer;i--){
        a.ArrayList[i] = a.ArrayList[i - 1];
    }
    a.ArrayList[targer] = k;
    a.len++;
    return a;
}
//查找数据
int Find(Array a, int k){
    for(int i = 0; i < a.len; i++){
        if(a.ArrayList[i] == k) return i;
    }
    return -1;
}
//删除数据
Array Delect(Array a,int k){
    int index = Find(a, k);
    if(index == -1) {
        printf("元素不存在\n");
        return a;
    }
    for(int i = index; i< a.len - 1 ; i++){
        a.ArrayList[i] = a.ArrayList[i+1];
    }
    a.len--;
    return a;
}
//修改数据
Array Revise(Array a,int k, int targer){
    int index = Find(a,k);
    if(index == -1) {
        printf("数据不存在\n");
        return a;
    }
    a.ArrayList[index] = targer;
    return a;
}
//顺序表输出
void Printff(Array a){
    if(a.len == 0){
        printf("空表\n");
        return ;
    }
    for(int i = 0; i < a.len ; i++){
        printf("%d ",a.ArrayList[i]);
    }
    printf("\n");
}
//主测试函数
int main(){
    Array a;
    a = InitArray(a);
    a = EndAdd(a, 1);
    a = EndAdd(a, 2);
    a = EndAdd(a, 3);
    Printff(a);
    a = MiddleAdd(a,0,8);
    Printff(a);
    a = Delect(a,2);
    Printff(a);
    a = Revise(a,8,7);
    Printff(a);
    printf("%d\n",Find(a,1));
    printf("%d\n",Find(a,2));
    return 0;
}