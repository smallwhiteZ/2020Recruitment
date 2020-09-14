//
// Created by wtZhou on 2020/9/12.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int len=s.size();
        if(len==0) {
            return 0;
        }
        if(s[0]=='0') return 0;
        int cur=1,pre=1; // 这里 cur和pre指示出只和前两项有关
        for(int i=1;i<len;i++){
            int tmp=cur;
            if(s[i]=='0'){
                if(s[i-1]=='1' || s[i-1]=='2'){
                    cur=pre;
                }
                else{
                    return 0;
                }
            }
            else{
                if(s[i-1]=='1' || s[i-1]=='2' && s[i]>='1' && s[i]<='6'){
                    cur=cur+pre;
                }
//                else{
//                    cur=tmp;
//                }
            }
            pre=tmp;
        }
        return cur;
    }
};

int main(){
    string s="27";
    Solution solu;
    solu.numDecodings(s);
    return 0;
}