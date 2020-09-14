//
// Created by wtZhou on 2020/9/6.
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
//
//void dfs(char a[],int n,char b[],int k){
//    int i,j;
//    if(n == strlen(a)){
//        for(i=0;i<k;i++)
//            cout<<b[i];
//        cout<<endl;
//        return ;
//    }
//    dfs(a,n+1,b,k);
//    b[k] = a[n];
//    k++;
//    dfs(a,n+1,b,k);
//    k--;
//}

void DFS(vector<int> a,int n,vector<int> &b,vector<vector<int>>& asum,int k){
    int i,j;
    vector<int> tmp;
    if(n == a.size()){
        for(i=0;i<k;i++)
            tmp.push_back(b[i]);
        asum.push_back(tmp);
        return;
    }
    DFS(a,n+1,b,asum,k);
    b[k] = a[n];
    k++;
    DFS(a,n+1,b,asum,k);
    k--;
}

int main(){
//    int a[10];
//    cin>>a;
//    int b[10];
//    dfs(a,0,b,0);


    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> a;
        int num;
        for(int i=0;i<n;i++){
            cin>>num;
            a.push_back(num);
        }
        vector<vector<int>> asum;
        vector<int> b;
        DFS(a,0,b,asum,0);
        for(int i=0;i<asum.size();i++){
            for(int j=0;j<asum[i].size();j++){
                cout<<asum[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}

/*
4
9
5 4 3 2 1 2 3 4 5
5
1 2 3 4 5
14
87 70 17 12 14 86 61 51 12 90 69 89 4 65
2

*/