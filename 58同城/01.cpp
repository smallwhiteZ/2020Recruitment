//
// Created by wtZhou on 2020/8/31.
//
// 58同城第3题 同时 也是剑指offer 46题
// 这一题没有进行了，以下的代码不一定正确

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

//// 这种解法是错误的
//int fun(string s){
//    if(s==""){
//        return 0;
//    }
//    int len=s.size();
//    long long countone=0;
//    long long counttwo=0;
//    for(int i=0;i<len-1;i++){
//        int a=(s[i]-'0');
//        int b=(s[i+1]-'0');
//        int num=a*10+b;
//        if(num>=0&&num<=25){
//            countone++;
//        }
//    }
//
//    int j=0;
//    while(j<len-1){
//        int a=(s[j]-'0');
//        int b=(s[j+1]-'0');
//        int num=a*10+b;
//        if(num>=0&&num<=25){
//            counttwo++;
//            j+=2;
//        }
//        else{
//            j++;
//        }
//    }
//    return pow(2,counttwo)-counttwo+countone;
//}

int fun(string s){
    if(s==""){
        return 0;
    }
    int len=s.size();
    int dp[len+1];
    dp[0]=1;
    if((s[0]-'0')==1 || (s[0]-'0')==2 && ((s[1]-'0')>=0&&(s[1]-'0'))<=6){
        dp[1]=2;
    }
    else{
        dp[1]=1;
    }
    for(int i=2;i<=len;i++){
        dp[i]=0;
        dp[i]+=dp[i-1]; // 是不是该这么写？？？ 不是这么写的，需要更改
//        if((s[i]-'0')==0){
//            dp[i]=dp[i-1];
//        }
//        else{
//            dp[i]+=dp[i-1];
//        }
        if((s[i-1]-'0')==1 || (s[i-1]-'0')==2 && ((s[i]-'0')>=0&&(s[i]-'0'))<=6){
            dp[i]+=dp[i-2];
        }
    }
    return dp[len];
}

int main(){
    string s="1215803";
    cout<<fun(s);
    return 0;
}
