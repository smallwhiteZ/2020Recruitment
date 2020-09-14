//
// Created by wtZhou on 2020/9/8.
//
// 盒子的个数

#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    unordered_map<int,int> a;
    int n;
    cin>>n;
    int ai=0;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>ai;
        if(a.count(ai) != 0){
            a[ai]++;
        }
        else{
            a.insert(pair<int,int>({ai,1}));
        }
        if(ans < a[ai]){
            ans=a[ai];
        }
    }
    cout<<ans;
    return 0;
}