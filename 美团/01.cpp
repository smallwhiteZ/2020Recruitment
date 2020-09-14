//
// Created by wtZhou on 2020/8/22.
//

#include <string>
#include <iostream>
#include <math.h>
using namespace std;

//int main(){
//    int n,k;
//    cin>>n>>k;
//    int arr[100000];
//    for(int i=0;i<n;i++){
//        cin>>arr[i];
//    }
//    int count=0;
//    //bool flag[100000][100000]={false};
//    for(int i=0;i<n;i++){
//        for(int j=i+1;j<n;j++){
//            if((arr[i]+arr[j])%k == 0){
//                count++;
//            }
//        }
//    }
//    long long
//    cout<<pow(2,n)-count*
//
//
//
//
//}
typedef long long ll;
const int mod=1e9+7;
int main()
{
    int n,k;
    int arr[100000];
    int max = 0,min=100001;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(max<arr[i]){
            max=arr[i];
        }
        if(min>arr[i]){
            min=arr[i];
        }
    }
    ll dp[n][k];
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            ll w=(max-j+k)/k-(min-j+k)/k;
            for(int t=0;t<k;k++){
                dp[i+1][(t+j)%k]=(dp[i+1][(t+j)%k]+dp[i][t]*w)%mod;
            }
        }
    }
    cout<<dp[n][0]<<endl;
    return 0;
}

