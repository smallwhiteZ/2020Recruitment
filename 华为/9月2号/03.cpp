//
// Created by wtZhou on 2020/9/2.
//
// 动态规划题--与背包问题相似
// 该问题是每个物品只能取一次，取或者不取，因此是0-1背包问题，还有完全背包问题和多重背包问题

#include <iostream>
#include <algorithm>
using namespace std;

struct box{
    int w;
    int v;
};

int main(){
    int K,N;
    cin>>K>>N;
    box b[N];
    for(int i=0;i<N;i++){
        int w;
        cin>>w;
        b[i].w=w;
    }
    for(int i=0;i<N;i++){
        int v;
        cin>>v;
        b[i].v=v;
    }


    /// dp[i][j] 表示为 当背包容量为j时，前i的物品的价值
    /// dp[i][j]=max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]) 左边为不选这个物品，右边是选择这个物品
//    int dp[1000][1000]={0};
//    int maxv=0;
//    for(int i=1;i<N;i++){ /// 物品的数量
//        for(int j=0;j<=K;j++){ /// 背包的容量
//            if(j>=b[i].w){
//                dp[i][j]=max(dp[i-1][j],dp[i-1][j-b[i].w]+b[i].v);
//                maxv = max(maxv,dp[i][j]);
//            }
//            else{ /// 放不下的时候，就是i-1的物品的最大价值
//                dp[i][j]=dp[i-1][j];
//            }
//        }
//    }


    /// 下面的是空间复杂度为o（n）的优化情况
    /// dp[i]=max(dp[i-w[i]]+v[i],dp[i])
    //int maxv=0;
    int dp[1000]={0};
    for(int i=0;i<N;i++){
        for(int j=K;j>=0;j--){ /// for(int j=0;j<=K;j++) 这里是有问题的  /// 这边与完全背包的区别就体现了出来，完全背包这里采用正序遍历
            if(j>=b[i].w){
                dp[j]=max(dp[j],dp[j-b[i].w]+b[i].v); // j指的背包的容量
                //maxv=max(maxv,dp[j]);
            }
            else{
                dp[j]=dp[j]; // 这一段可以不加
            }
        }
    }
    //cout<<maxv;
    cout<<dp[K]; /// 输出dp[K]的话，就是满足占用最大空间的价值最大化 /// 需要注意到，背包问题有很多变形，问题的变种有很多，因此需要看清题意才行
    return 0;
}
