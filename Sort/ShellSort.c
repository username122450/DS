#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    scanf("%d",&num);
    int array[num + 1];
    for(int i = 1; i <= num;i++){
        scanf("%d",&array[i]);
    }
    int f = num /2;
    while(f > 0){
        int j,t;
        for(int i = 1 + f;i <= num;i++){
            int t = array[i];
            for(j = i - f; j > 0 && array[j] >t; j-=f){
                array[j+f] = array[j];
            }
            array[j + f] = t;
        }
        f /= 2;
    }

    for(int i = 1; i <= num;i++){
        printf("%d ",array[i]);
    }

    return 0;
}