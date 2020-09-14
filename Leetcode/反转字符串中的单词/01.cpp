//
// Created by wtZhou on 2020/8/30.
// 想了一个最暴力的方法，使用了 reverse函数，使得代码量没有那么复杂
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans,temp;
        //vector<char> temp;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                temp+=s[i];
            }
            else{
                reverse(temp.begin(),temp.end()); // 字符串反串函数
                ans+=temp;
                ans+=' ';
                temp.clear();
            }
        }
        reverse(temp.begin(),temp.end()); // 添加这一块的原因是最后一个字符串在上面循环中不会进行处理
        ans+=temp;
        //ans+=' ';
        //temp.clear();
        return ans;
    }
};

int main(){
    string s="Let's take LeetCode contest";
    Solution solu;
    cout<<solu.reverseWords(s);
    return 0;
}