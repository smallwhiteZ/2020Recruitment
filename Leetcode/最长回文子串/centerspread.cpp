//
// 采用 中心扩散的方法，能够是的空间复杂度为O(1)
// 需要 细细体会 中心扩散的 思想
// Created by wtZhou on 2020/8/28.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string Centerspread(string s, int left, int right){
        int i=left,j=right,len=s.size();
        while(i>=0 && j<len){
            if(s[i]==s[j]){
                i--,j++;
            }
            else{
                break;
            }
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        int lens=s.size();
        if(lens<2){
            return s;
        }
        //int maxlen=1;
        string maxans;
        for(int i=0;i<lens-1;i++){
            string oddstr = Centerspread(s,i,i);
            string evenstr = Centerspread(s,i,i+1);
            string ans = oddstr.size()>evenstr.size() ? oddstr : evenstr;
            if(maxans.size()<ans.size()){
                maxans = ans;
            }
        }
        return maxans;
    }
};

int main(){
    string s = "babad";
    string s2 = "cbbd";
    Solution solu;
    cout<<solu.longestPalindrome(s)<<endl;
    return 0;
}