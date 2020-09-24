//
// Created by wtZhou on 2020/9/24.
//
// 以下代码是错误的，具体的错误在代码中的注释中，没有办法a所有的case

#include <string>
using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int maxlen = max(first.size(),second.size());
        int minlen = min(first.size(),second.size());
        if((maxlen - minlen)>=2){
            return false;
        }
        int flag=0;
        if(first.size()>=second.size()){
            int i=0,j=i; // 添加j是为了解决删除一个字符的情况
            while(i<first.size()){
                if(j<second.size() && first[i]==second[j]){
                    i++;j++;
                }
                else{
                    i++;
                    flag++;
                }
                if(flag>1 || j <= second.size()){  // 添加j<... 是为了解决 ab 和 bc
                    // flag总是不能很好的解决一些特别的case的，最主要的还是思路没有搞清
                    return false;
                }
            }
        }
        else{
            int i=0,j=i;
            while(i<second.size()){
                if(j<first.size() && first[j]==second[i]){
                    i++;j++;
                }
                else{
                    i++;
                    flag++;
                }
                if(flag>1 || j <= first.size()){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    string a="a";
    string b="b";
    Solution solu;
    solu.oneEditAway(a, b);
    return 0;
}