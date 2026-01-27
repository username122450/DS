#include<stdio.h>
#include<stdlib.h>

//Exercise on direct insertion sort --260126
int main(){
    int num;
    printf("Please enter the quantity of these numbers:");
    scanf(" %d",&num);
    int *nums = (int *)malloc(sizeof(int) * num);
    
    for(int i= 0;i < num;i++){
        scanf(" %d",&nums[i]);
    }
    printf("Input completed!\n");
    int temp,j;
    for(int i = 1; i< num;i++){
        temp = nums[i];
        for(j = i - 1; j >=0 && nums[j] > temp;j--){
            nums[j+1] = nums[j];
        }
        nums[j+1] = temp;
    }
    printf("Sorting comleted!\n");
    for(int i = 0; i< num; i++){
        printf("%d ",nums[i]);
    }
    printf("Output completed!\n");
    return 0;
}