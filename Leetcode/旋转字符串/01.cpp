//
// Created by wtZhou on 2020/9/15.
//
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        bool ans=false;
        string tmp=A;
//        for(auto it=A.rbegin();it!=A.rend();it--){ /// string的逆序遍历的函数写的不对
//            tmp+=*it;
//        }
//        string ttt(tmp.rbegin(),tmp.rend()); ///真要写的话是这样表达出来的
        if(A== "" && B==""){
            return true;
        }
        if(A!="" || B==""){
            return false;
        }
        while(tmp!=B){
            char t=tmp[tmp.size()-1];
            /// tmp.erase(tmp.end());    /// 这一步为啥不对？？
            tmp.erase(tmp.end()-1); /// 或者是 tmp.pop_back()  或者是 tmp=tmp.substr(0,tmp.length()-1);
            tmp.insert(tmp.begin(),t);
            if(tmp==A){
                break;
            }
        }
        if(tmp==B){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    string A="abcde", B="cdeab";
    Solution solu;
    solu.rotateString(A,B);
    return 0;
}