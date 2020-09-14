//
// Created by wtZhou on 2020/9/3.
//
// 写错了，不是简单的dp问题

#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    int a[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>a[i][j];
        }
    }
    int dp[N][N];
    dp[0][0]=0;
    for(int j=1;j<N;j++){
        dp[0][j]=dp[0][j-1]+abs(a[0][j]-a[0][j-1]);
        dp[j][0]=dp[j-1][0]+abs(a[j][0]-a[j-1][0]);
    }
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            int tmpi,tmpj;
            tmpi=dp[i-1][j]+abs(a[i-1][j]-a[i][j]);  /// 不对，因为要求是每次能次能够移动上下左右，不是只能移动向右和向下
            tmpj=dp[i][j-1]+abs(a[i][j-1]-a[i][j]);
            dp[i][j]=min(tmpi,tmpj);
        }
    }
    cout<<dp[N-1][N-1];
    return 0;
}

/*

3
1 2 4
1 3 1
1 2 1

5
1 10 1 1 1
1 1 1 10 1
10 10 10 10 1
10 10 10 10 1
10 10 10 10 1

 */