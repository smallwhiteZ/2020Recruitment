//
// Created by wtZhou on 2020/9/4.
//
#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int len=cost.size();
    vector<int> dp(len,0);
    dp[0]=cost[0];
    dp[1]=cost[1];
    for(int i=2;i<len;i++){
        dp[i]=min(dp[i-1]+cost[i],dp[i-2]+cost[i]);
    }
    return min(dp[len-1],dp[len-2]);  // 这一步比较关键
}

int main(){
    vector<int> demo={1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout<<minCostClimbingStairs(demo);
    return 0;
}