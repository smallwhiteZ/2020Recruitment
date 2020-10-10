//
// Created by wtZhou on 2020/10/10.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int ran=rand()%14;
    vector<int> arr(n,k);
    arr[ran]=0;
    int m=(ran+1)%n;
    for(int i=0;i<k;i=(i+1)%n){
        arr[(m+i)%n]++;
    }
//
//    for(int i=0;i<n;i++){
//        cout<<arr[i]<<" ";
//    }
//    cout<<endl;
    int t=(m+k)%n;
    while(arr[t]!=0){
        int cnt=arr[t%n];
        arr[t%n]=0;
        for(int i=0;i<cnt;i++){
            arr[(t+1+i)%n]++;
        }
//        for(int i=0;i<n;i++){
//            cout<<arr[i]<<" ";
//        }
//        cout<<endl;
        t=(t+cnt+1)%n;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}