#include<stdio.h>
#include<stdlib.h>

//插入排序:稳定的就地排序

int main(){
    int num;
    scanf("%d",&num);
    int *array = (int *)malloc(sizeof(int) * (num + 1));
    for(int i= 1;i <= num;i++){
        scanf("%d",&array[i]);
    }
    for(int i = 2;i <= num ;i++){
        int t = array[i];
        int j;
        for(j = i-1;j > 0 && array[j] > t;j--){
            array[j+1] = array[j];
        }
        array[j+1] = t;
    }
    for(int i = 1; i <= num;i++){
        printf("%d ",array[i]);
    }
    return 0;
}