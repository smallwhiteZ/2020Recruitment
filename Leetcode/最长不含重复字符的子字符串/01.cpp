//
// Created by wtZhou on 2020/9/9.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        string tmp;
        int maxlen=0;
        while(i<s.size()){
            if(tmp.find(s[i])==string::npos){
                tmp+=s[i];
                if(maxlen<tmp.size()){
                    maxlen=tmp.size();
                }
                i++;
            }
            else{
                int j=tmp.find(s[i]);
//                tmp+=s[i];
//                tmp.erase(0,j);
                for(int k=0;k<=j;k++){
                    tmp.erase(0,1);
                }
///                i=j;  这一步其实是没有必要的
            }
            //i++;
        }
        return maxlen;
    }
};

int main(){
    Solution solu;
    string s="pwwkew";
    cout<<solu.lengthOfLongestSubstring(s)<<endl;
}