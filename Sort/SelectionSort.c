#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    printf("Please enter the quantity of these numbers:");
    scanf(" %d", &num);
    int *nums = (int *)malloc(sizeof(int )* num);
    for(int i = 0;i < num;i++){
        scanf(" %d",&nums[i]);
    }
    printf("Input completed!\n");

    int j,min,minIndex;
    for(int i = 0; i < num-1;i++){
        min = nums[i];
        minIndex = i;
        for(j = i; j < num;j++){
            if(nums[j] < min) { 
                min = nums[j];
                minIndex = j;
            }
        }
        nums[minIndex] = nums[i];
        nums[i] = min;
    }

    printf("Sorting completed!\n");
    for(int i = 0;i < num;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
    printf("Output completed!\n");
    return 0;
}