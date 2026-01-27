#include<stdio.h>
#include<stdlib.h>

//Exerices on direct Shell sort -- 260126

int main(){
    int num;//The number of array elements
    printf("Please enter the quantity of these numbers:");
    scanf(" %d",&num);
    int *nums = (int *)malloc(sizeof(int) * num);
    for(int i = 0; i < num; i++){
        scanf(" %d",&nums[i]);
    }
    printf("Input completed!\n");
    int factor, i, j,temp;
    // This "factor" refers to the step size.
    for(factor = num/2; factor >= 1;factor /= 2){
        for(i = factor; i < num ;i++){
            temp = nums[i];
            for( j = i-factor;j >= 0 && nums[j] > temp;j -= factor){
                nums[j+factor] = nums[j];
            }
            nums[j+factor] = temp;
        }
    }
    printf("Sorting completed!\n");
    for(int i = 0;i < num;i++){
        printf("%d ",nums[i]);
    }
    printf("Output completed!\n");
    return 0;
}
