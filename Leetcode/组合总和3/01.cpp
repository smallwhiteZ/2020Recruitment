//
// Created by wtZhou on 2020/9/11.
//
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

class Solution {
public:
    void backtrack(int index,int res,int k,int n,vector<vector<int>>& ans,vector<int> &tmp){
        if(tmp.size()==k && accumulate(tmp.begin(),tmp.end(),0)==n){ /// 学习一下accumulate函数（STL求和函数）
//            int sum=0;
//            for(int t=0;t<k;t++){
//                sum+=tmp[t];
//            }
//            accumlate(tmp.begin(),tmp.end())
//            if(sum==n){
//                ans.push_back(tmp);
//            }
            ans.push_back(tmp);
        }
        else{
            //for(int i=0;i<k;i++){
            for(int j=index;j<=9;j++){  /// 肯定不能从j=1开始
                if(res>=j){
                    tmp.push_back(j);
                    backtrack(j+1,res-j,k,n,ans,tmp);
                    tmp.pop_back();
                }
                else{
                    break;
                }
            }
            //}
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        vector<vector<int>> ans;
        backtrack(1,n,k,n,ans,tmp);
        return ans;
    }
};

int main(){
    Solution solu;
    solu.combinationSum3(3,7);
    return 0;
}