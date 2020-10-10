//
// Created by wtZhou on 2020/10/3.
//

#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0){
            return 0;
        }
        int ans=haystack.find(needle); /// string 的 find函数
        if(ans==haystack.npos){ /// string .npos 为特定的没有找到的返回值
            return -1;
        }
        else{
            return ans;
        }
    }
};