//
// Created by wtZhou on 2020/8/21.
//
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0, right=0;
        unordered_map<char, int> window;
        int ans=0;
        while(right<s.size()){
            char temp = s[right];
            window[temp]++;
            right++;
            while(window[temp]>1) { // window[s[right]] 没有想到,并且 需要temp记录当前right的值
                window[s[left]]--; // 这边非常巧妙
                left++;
                //ans = max(ans, right - left);
            }
            //ans = max(ans, right - left); // 在left移动的时候才是更新ans的时候（错误的思想）
            ans = max(ans, right - left);
        }
        return ans;
    }
};

int main(){
    string s="abcabcbb";
    string s2="bbbb";
    string s3="pwwkew";
    Solution solu;
    int ans=solu.lengthOfLongestSubstring(s);
    cout<<ans;
    return 0;
}
/*
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 */
