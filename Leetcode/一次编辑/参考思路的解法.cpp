//
// Created by wtZhou on 2020/9/24.
//

// 思路： 1. 长度差超过2，直接false
//       2. 长度想同的时候，当发现不相同字符的时候，跳过该字符，比较后面的字符串是否想同
//       3. 长度相差为1的时候，当发现不同的时候，跳过更长的字符串的字符，然后接着对比两个字符串后面的字符（直接截取子字符串进行比较这一步我没有想到）

#include <string>
using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int maxlen = max(first.size(), second.size());
        int minlen = min(first.size(), second.size());
        int error = maxlen - minlen;
        if(error>=2){
            return false;
        }
        if(error==1){
            if(first.size()>=second.size()){
                int i=0,j=i;
                while(first[i]==second[j]){
                    i++,j++;
                }
                if(j<second.size()){
                    i++;
                    string ta = first.substr(i,first.size()-i);
                    string tb = second.substr(j, second.size()-j);
                    if(ta == tb){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
            }
            else{
                int i=0,j=i;
                while(first[i]==second[j]){
                    i++,j++;
                }
                if(j<first.size()){
                    j++;
                    string ta = first.substr(i,first.size()-i);
                    string tb = second.substr(j, second.size()-j);
                    if(ta == tb){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        if(error==0){
            int i=0,j=i;
            while(first[i]==second[j]){
                i++,j++;
            }
            if(j<second.size()){
                i++, j++; // 跳过不相同的部分
                string ta = first.substr(i,first.size()-i);
                string tb = second.substr(j, second.size()-j);
                if(ta == tb){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};