//
// Created by wtZhou on 2020/9/5.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> ansint;
    void trackback(int& cnt,vector<int> tmp,vector<int>& res,vector<bool>& tmpb,int k){
//        if(cnt==k){
//            ansint=res;
//            return;
//        }
        if(res.size()==tmp.size()){
            cnt++;
            if(cnt==k){
                ansint=res;
            }
            return;
        }
        else{
            for(int i=0;i<tmp.size();i++){
                if(tmpb[i]==false){
                    // swap(string[left],swap[n-1]);
                    res.push_back(tmp[i]);  /// 为什么这边会出现问题??
                    tmpb[i]=true;
                    trackback(cnt,tmp,res,tmpb,k);
                    //swap(string[left],swap[n-1]);
                    res.pop_back();
                    tmpb[i]=false;
                }
            }
        }
    }

    // 采用全排列的方法，然后得到第k个后返回
    string getPermutation(int n, int k) {
        string ans;
        int cnt=0;
        vector<int> tmp;
        vector<bool> tmpb(n,false);
        for(int i=0;i<n;i++){
            tmp.push_back(i+1);
        }
        vector<int> res;
        trackback(cnt,tmp,res,tmpb,k);
        for(int i=0;i<ansint.size();i++){
            ans+=to_string(ansint[i]);
        }
        return ans;
    }
};

int main(){
    Solution solu;
    cout<<solu.getPermutation(3,3)<<endl;
    return 0;
}