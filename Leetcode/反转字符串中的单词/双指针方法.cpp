//
// Created by wtZhou on 2020/8/30.
// 这是在题解中看到的双指针的方法，空间复杂度为O（1）
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if(s.size()==0){
            return s;
        }
        int left=0,right=0,next=0;
        while(right<s.size()){
            while(right< s.size() && s[right]!=' '){ // 仍然需要加上 right < s.size()，不然会超出字符串的边界
                right++;
            }
            next=right+1;
            right--;
            while(left<right){
                swap(s[left++],s[right--]);
            }
            left=next;
            right=left;
        }
        return s;
    }
};

int main(){
    string s="Let's take LeetCode contest";
    Solution solu;
    cout<<solu.reverseWords(s);
    return 0;
}