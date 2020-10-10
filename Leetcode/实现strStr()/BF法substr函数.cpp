//
// Created by wtZhou on 2020/10/3.
//
/// BF法

class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenhay=haystack.size();
        int lennee=needle.size();
        if(lennee==0){
            return 0;
        }
        for(int i=0;i<=lenhay-lennee;i++){
            if(haystack.substr(i,lennee)==needle){  /// 这个substr使用的感觉真的爽，substr(pos初始的位置,len字符串的长度)
                return i;
            }
        }
        return -1;
    }
};