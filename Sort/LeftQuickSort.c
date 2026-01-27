#include<stdio.h>
#include<stdlib.h>

//This is the code for Left Quick Sort -- 260127

void QSort(int *nums,int l,int r){
    if(l < r){
        int temp = nums[l];
        int i = l,j = r;
        while(i < j){
            while(i < j && nums[j] > temp) j--;
            if(i < j){
                nums[i] = nums[j];
                i++;
            }
            while(i < j && nums[i] < temp) i++;
            if(i < j){
                nums[j] = nums[i];
                j--;
            }
        }
        nums[i] = temp;
        QSort(nums,l,i-1);
        QSort(nums,i+1,r);
    }
}

int main(){
    int num;
    printf("Please enter the quantity of these numbers:");
    scanf(" %d", &num);
    int *nums = (int *)malloc(sizeof(int )* num);
    for(int i = 0;i < num;i++){
        scanf(" %d",&nums[i]);
    }
    QSort(nums,0,num-1);
    printf("Sorting completed!\n");
    for(int i = 0;i < num;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
    printf("Output completed!\n");
    return 0;
}