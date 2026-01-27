#include<stdio.h>
#include<stdlib.h>

//This is the code for bubble sort -- 260127

int main(){
    int num;
    printf("Please enter the quantity of these numbers:");
    scanf(" %d", &num);
    int *nums = (int *)malloc(sizeof(int )* num);
    for(int i = 0;i < num;i++){
        scanf(" %d",&nums[i]);
    }
    printf("Input completed!\n");
    int j,temp,state;
    for(int i = num-1 ;i > 0;i--){
        state = 0;
        for(j = 0; j< i;j++){
            if(nums[j] > nums[j+ 1]){
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
                state = 1;
            }
        }
        if(state != 1) break;
    }
    printf("Sorting completed!\n");
    for(int i = 0;i < num;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
    printf("Output completed!\n");
    return 0;

}
