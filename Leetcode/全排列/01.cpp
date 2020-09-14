//
// Created by wtZhou on 2020/9/4.
//

#include <iostream>
#include <vector>
using namespace std;

//int cnt=0;
//void trackback(vector<vector<int>> &ans,vector<int> &nums,int i)
//{
//    if(i==nums.size()-1){  // 这个判断条件需要修改
//        //ans.push_back()
//        vector<int> tmp;
//        for(int j=0;j<nums.size();j++){
//            tmp.push_back(nums[j]);
//        }
//        ans.push_back(tmp);
//        return;
//    }
////    if(i<nums.size()-1){      /// 用这个判断来交换的话不好
////        swap(nums[i],nums[i+1]);
////    }
///
///   少了push和pop的过程

//    trackback(ans,nums,i+1);
//    if(i<nums.size()-1){
//        swap(nums[i],nums[i+1]);
//    }
//}

vector<vector<int>> res;
void trackback(vector<int> &nums,vector<int> &current, vector<bool> &nums1){  /// 从网上下载下来的答案，仅供学习
    if(current.size()==nums.size())
    {
        res.push_back(current);
    }
    else{
        for(int i=0;i<nums.size();i++){
            if(nums1[i]== true){
                current.push_back(nums[i]);
                nums1[i]= false;
                trackback(nums,current,nums1);
                nums1[i]=true;
                current.pop_back(); // 退出来的这个操作是没有想到
            }
            //trackback(nums,current,nums1);
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    //vector<vector<int>> ans;
    vector<int> cur;
    vector<bool> nums1(nums.size(),true);
    trackback(nums,cur,nums1);
    return res;
}

int main(){
    vector<int> n={1,2,3};
    vector<vector<int>> a=permute(n);
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[0].size();j++){
            cout<<a[i][j]<<',';
        }
        cout<<endl;
    }
    return 0;
}