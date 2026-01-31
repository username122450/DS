#include<stdio.h>
#include<stdlib.h>

//This is the code for Heap Sort --260201

void swap(int *nums,int i,int j){
    int swap = nums[i];
    nums[i] = nums[j];
    nums[j] = swap;
}

void upAdjust(int *nums,int i){//向上调整:用于边输入边维护堆
    int fa ;
    while(i/2 >=1 ){
        fa = i/2;
        if(nums[fa] < nums[i]){
            swap(nums,i,fa);
            i = fa;
        }else break;
    }
}

void downAdjust(int *nums,int i,int n){//向下调整:用于维护堆的i位置的子树
    int ch ;
    while( 2*i <= n ){
        ch = 2 * i;
        if(ch+1 <=n && nums[ ch ] < nums[ ch+1 ]) ch++;
        if(nums[ch] > nums[i]){
            swap(nums,i,ch);
            i = ch;
        }else break;
    }
}

int main(){
    int num;
    printf("Please enter the quantity of these numbers:");
    scanf(" %d", &num);
    int *nums = (int *)malloc(sizeof(int )* (num+1));
    for(int i = 1;i <= num;i++){
        scanf(" %d",&nums[i]);
        upAdjust(nums,i);
    }
    printf("Input completed!\n");

    // for(int i = num/2 ;i >= 1;i--){
    //     downAdjust(nums,i,num);//在上面使用upAdjust时这里的调整属于多余操作
    // }

    for(int i = num ;i > 1 ;i--){
        swap(nums,1,i);
        downAdjust(nums,1,i-1);
    }

    printf("Sorting completed!\n");
    for(int i = 1;i <= num;i++){
        printf("%d ",nums[i]);  
    }
    printf("\n");
    printf("Output completed!\n");

    return 0;
}