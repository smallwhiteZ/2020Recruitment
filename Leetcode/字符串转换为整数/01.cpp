//
// Created by wtZhou on 2020/8/29.
//
/// 下面的代码在负数的部分是错误的


#include <iostream>
#include <string>
#include <math.h>
using namespace std;
//#define int_max (pow(2,31)-1)
//#define int_min (-1 * pow(2,31))

class Solution {
public:
    int myAtoi(string str) {
        int int_max = pow(2,31)-1;
        int int_min = -1 * pow(2,31);
        int ans=0;
        int index = 0;
        while(str[index] == ' '){index++;}
        if(str[index]>='0'&&str[index]<='9'){
            int i=index;
            //int ans=0;
            string s2;
            while(str[i]>='0'&&str[i]<='9'){
                s2 = s2+str[i];
                i++;
            }
            for(int j=0;j<s2.size();j++){
                // ans = ans*10 + s2[j]-'0'; // 为啥这么傻逼
                if(ans>int_max/10 || (ans==int_max/10 && (s2[j]-'0')>7)){
                    return int_max;
                }
                else{
                    ans = ans*10 + s2[j]-'0'; // 为啥这么傻逼
                }
            }
        }
        else if(str[index]=='+'){
            int i=index+1;
            //int ans=0;
            string s2;
            while(str[i]>='0'&&str[i]<='9'){
                s2 = s2+str[i];
                i++;
            }
            for(int j=0;j<s2.size();j++){
                // ans = ans*10 + s2[j]-'0'; // 为啥这么傻逼
                if(ans>int_max/10 || (ans==int_max/10 && (s2[j]-'0')>7)){
                    return int_max;
                }
                else{
                    ans = ans*10 + s2[j]-'0'; // 为啥这么傻逼
                }
            }
        }

        /// 在负数的部分，存在bug，int_min的部分不正确，最终还是通过long来解决
        /// 下面的代码不正确
        else if(str[index]=='-'){
            int i=index+1; // 下一个指标
            //int ans=0;
            string s2;
            while(str[i]>='0'&&str[i]<='9'){
                s2 = s2+str[i];
                i++;
            }
            for(int j=0;j<s2.size();j++){
                // ans = ans*10 + s2[j]-'0';
                if(ans>int_max/10 || (ans==int_max/10 && (s2[j]-'0')>8)){
                    return int_min;
                }
                else{
                    ans = ans*10 + s2[j]-'0';
                }
            }
            ans *= -1;
        }
        else{
            //ans=0;
        }
        return ans;
    }
};

int main(){
    string s="42";
    string s2="   -42";
    string s3="2147483646";
    Solution solu;
    cout<<solu.myAtoi(s3);
    return 0;
}