//
// Created by wtZhou on 2020/10/4.
//
/**
 * 解法总结：
 * 1.暴力枚举所有的特征值
 * 2.排序 + 选取特征值
 * 3.计数数组后缀和--这个方法没有想到
 */

#include <vector>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {  /// 计数数组后缀和方法
        int n=nums.size();
        vector<int> arr(n+1,0);  /// arr[i]记录的是大于等于 i的个数
        for(int num:nums){
            arr[min(n,num)]++; /// 这一步有意思
        }
        for(int i=n;i>=0;i--){ /// 由后往前这一步也是非常精妙
            if(i<n){
                arr[i]+=arr[i+1];
            }
            if(arr[i]==i){
                return i;
            }
        }
        return -1;
    }
};