//
// Created by wtZhou on 2020/8/27.
//

#include <iostream>
using namespace std;
int main(){
    int n;
    int a[100][200]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=n;j>=i;j--){
            cout<<" ";
        }
        for(int j=0;j<=2*i;j++){
            cin>>a[i][n-i+j];
        }
    }
    int MAx=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<2*n;j++){
            int temp = a[i][j];
            int temp2 = max(temp+a[i-1][j-1],a[i][j]+a[i-1][j]);
            a[i][j]=max(temp2,temp+a[i-1][j+1]);
            if(MAx<a[i][j]){
                MAx=a[i][j];
            }
        }
    }
    cout<<MAx;
    return 0;
}