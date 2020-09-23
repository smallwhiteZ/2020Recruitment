//
// Created by wtZhou on 2020/9/23.
//

//
// Created by wtZhou on 2020/9/22.
//

//给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

// 思路： 双指针法
//      主要是指针的走法没有理清楚。。。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int i=0,j=1;
        while(j<nums.size()){
            if(nums[i] != nums[j]){ // 这一步太妙了吧。。。。
                nums[i+1] = nums[j];
                i++;
            }
            j++;
        }
        return i+1;
    }
};

int main(){
    vector<int> a={0,0,1,1,1,2,2,3,3,4}; //0,0,1,1,1,2,2,3,3,4   1 1 2
    //a.push_back(1);a.push_back(1);a.push_back(2);
    Solution solu;
    solu.removeDuplicates(a);
    for(auto num:a){
        cout<<num<<endl;
    }
    return 0;
}