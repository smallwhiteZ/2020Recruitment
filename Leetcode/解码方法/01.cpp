//
// Created by wtZhou on 2020/9/12.
//
/// 还是思考的不好，把思路理清楚之后就好，而不是像下面写的那么冗杂，而且不对


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0){
            return 0;
        }
        int len=s.size();
        vector<int> dp(len,0);
        if(len >= 1){
            if(s[0]=='0'){
                dp[0]=0;
            }
            else{
                dp[0]=1;
            }
        }
        if(len>=2 && (s[0]=='1' && s[1]=='0'|| s[0]=='2' && s[1]=='0')){
            dp[1]=1;
        }
        else if(len>=2 && ((s[0]=='1' && s[1]!='0') || s[0]=='2'&& (s[1]>='1'&&s[1]<='6'))){
            dp[1]=2;
        }
        else{
            dp[1]=dp[0];
        }
        for(int i=2;i<len;i++){
            if(s[i]=='0' || s[i-1]=='0'){
                dp[i]=dp[i-1];
            }
            else if(s[i-1]== '1' && (s[i]>='1' && s[i]<='9')){
                dp[i]=dp[i-1]+dp[i-2];
            }
            else if(s[i-1]=='2' && (s[i]>='1' && s[i]<='6')){
                dp[i]=dp[i-1]+dp[i-2];
            }
            else{
                dp[i]=dp[i-1];
            }
        }
        return dp[len-1];
    }
};

int main(){
    string s="27";
    Solution solu;
    solu.numDecodings(s);
    return 0;
}