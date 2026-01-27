#include<stdio.h>
#include<stdlib.h>

//This is the code for Three Reference Quick Sort --260128

int getMid(int *nums,int l,int r,int mid){
    if(nums[l] > nums[mid] && nums[mid] > nums[r] || nums[r] > nums[mid] && nums[mid] > nums[l]) 
        return mid;
    else if(nums[l] < nums[mid] && nums[l] > nums[r] || nums[r] > nums[l] && nums[mid] < nums[l])
        return l;
    else return r;
}

void QSort(int *nums,int l,int r){
    if(l < r){
        int midIndex= getMid(nums,l,r,(l+r)/2);
        int temp = nums[midIndex];
        nums[midIndex] = nums[r];
        nums[r] = temp;
        int i = l,j = r;
        while(i < j){
            while(i < j && nums[i] < temp)i++;
            if(i < j){
                nums[j] = nums[i];
                j--;
            }
            while(i < j && nums[j] > temp) j--;
            if(i < j){
                nums[i] = nums[j];
                i++;
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

    free(nums);
    nums = NULL;
    return 0;
}