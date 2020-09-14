//
// Created by wtZhou on 2020/9/2.
//
/// 我也不知道怎么做，没读懂下面main函数的代码

/// 容斥原理：容斥原理，求所有m的集合，在这个集合的所有数，求一下lcm（最小公倍数），如果|集合|是奇数，ans+=n/lcm，否则ans-=n/lcm

#include <iostream>
#include <algorithm>
using namespace std;

long long pw(long long a,long long b){
    long long ans;
    while(b>0){
        if(b&1){
            ///ans *= ans*a;
            ans *= a;
        }
        a*=a;
        b>>=1; ///b/=2; // b>>1
    }
    return ans;
}

long long gcd(long long m, long long n){
    long long tmp;
    while(n){
        tmp=m%n;
        m=n;
        n=tmp;
    }
    return m;
}

int main(){
    long long N,M;
    cin>>N>>M;
    int arr[20];
    for(int i=0;i<M;i++){
        cin>>arr[i];
    }
    long long ed =pw(2,M);
    long long ans=N; /// 到底是啥意思
    for(int i=0;i<ed;i++){ /// 为什么是这个区间？
        long long cnt=0;
        long long tmp=1;
        for(int j=0;j<M;j++){
            if((i & (i<<j)) != 0){ /// 是啥意思？j
                cnt++;
                tmp = tmp / gcd(tmp,arr[j]) * arr[j]; ///  ?????
            }
        }
        if(cnt%2==1){
            ans -= (N / tmp);
        }
        else{
            ans += (N / tmp);
        }
    }
    cout<<(N-ans);
    return 0;
}