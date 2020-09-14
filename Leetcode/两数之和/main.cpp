//
// Created by wtZhou on 2020/8/19.
//
#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    returnSize = (int *)malloc(2*sizeof(int));
    for(int i=0;i<numsSize-1;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                returnSize[0]=i;
                returnSize[1]=j;
                break;
            }
        }
    }
    return returnSize;
}
int main(){
    int nums[4]={2, 7, 11, 15}, target=9;
    int *ans=twoSum(nums,4,9,ans);
    printf("%d\t%d\t",ans[0],ans[1]);
    return 0;
}

//int summax(int L)
//{
//    if(L==1){
//        return 1;
//    }
//    if(L==2){
//        return 2;
//    }
//    //summax=summax+summax(L-1);
//    long sum=0;
//    for(int i=1;i<L;i++) {
//        return (sum += summax(i));
//    }
//}