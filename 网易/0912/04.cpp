//
// Created by wtZhou on 2020/9/12.
//
/// 第4题是二分图的最大匹配，采用匈牙利算法，于是找到网上的程序，有了04new，04new2，04new3，
/// 经过调试，04new可以运行，但是不知道放到oj上能不能过

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int ans=0;
void backtrack(vector<int> male,vector<int> female, vector<bool>& mal,vector<bool>& fem,int &tmp,vector<int> cur,int n,int pei[n][2]){
    if(cur.size()==n){

    }
    for(int i=0;i<male.size();i++){
        if(!mal[i]){
            for(int j=0;j<female.size();j++){
                if(!fem[j]){
                    for(int k=0;k<n;k++){
                        if(i==pei[k][0] && j==pei[k][1]){
                            mal[i]=true;
                            fem[j]=true;
                            tmp++;
                        }
                    }
                }
            }
        }
        else{

        }
    }
}

int main(){
    string c;
    vector<int> male;
    vector<bool> mal(100000,false);
    vector<int> female;
    vector<int> fem(100000,false);
    while(getline(cin,c)){
        int t=c[0]-'0';
        male.push_back(t);
        mal[t]=false;
    }
    while(getline(cin,c)){
        int t=c[0]-'0';
        female.push_back(t);
        fem[t]=false;
    }
    int n;
//    vector<pair<int,int>> pei;
//    for(int i=0;i<n;i++){
//        int m,f;
//        cin>>m>>f;
//        pair<int,int>
//        pei.push_back()
//    }
    int pei[n][2];
    for(int i=0;i<n;i++){
        int m,f;
        cin>>m>>f;
        pei[i][0]=m,pei[i][1]=f;
    }
    int ans=0;
    for(int i=0;i<male.size();i++){
        if(!mal[i]){
            for(int j=0;j<female.size();j++){
                if(!fem[j]){
                    for(int k=0;k<n;k++){
                        if(i==pei[k][0] && j==pei[k][1]){
                            mal[i]=true;
                            fem[j]=true;

                        }
                    }
                }
            }
        }
    }

}