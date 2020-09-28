//
// Created by wtZhou on 2020/9/28.
//
//
//给你一个正整数数组 nums，你需要从中任选一些子集，然后将子集中每一个数乘以一个 任意整数，并求出他们的和。
//
//假如该和结果为1，那么原数组就是一个「好数组」，则返回 True；否则请返回 False。

/// 数学题，需要知道   裴蜀定理，方能求解出

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        if(nums.size()==0){
            return false;
        }
        if(nums.size()==1){
            return nums[0]==1;
        }
        for(int i=0;i<nums.size()-1;i++){ /// 没有想到通过这样的方式 计算出整个数组的最大公约数
            nums[i+1]=gcd(nums[i], nums[i+1]);
        }
        if(nums[nums.size()-1]==1){   /// 计算出数据的最大公约数之后，判断是否为1，是则满足条件
            return true;
        }
        else{
            return false;
        }
    }

    int gcd(int a, int b){
        if(b!=0){
            int m=a%b;
            a=b;
            b=m;
            return gcd(a,b);
        }
        else{
            return a;
        }
    }
};