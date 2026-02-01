#include<stdio.h>
#include<stdlib.h>

//This is the code for Merge Sort --260202

void MergeSort(int *nums,int l,int r){
    if(l < r){
        int mid = (l+r)/2;
        MergeSort(nums,l,mid);
        MergeSort(nums,mid+1,r);
        int i = l,y = mid+1;
        int *t = (int *)malloc(sizeof(int) * (r-l+1));
        int s = 0;
        while(i <= mid && y <= r){
            if(nums[i] < nums[y]) {
                t[s++] = nums[i++];
            }else{
                t[s++] = nums[y++];
            }
        }
        while(i <= mid){
            t[s++] = nums[i++];
        }
        while(y <= r){
            t[s++] = nums[y++];
        }
        for(int z = 0;z < s;z++){
            nums[l+z] = t[z];
        }
        free(t);
        t = NULL;
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
    printf("Input completed!\n");

    MergeSort(nums,0,num-1);

    printf("Sorting completed!\n");
    for(int i = 0;i < num;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
    printf("Output completed!\n");
    free(nums);
    nums = NULL;

    return 0;
}