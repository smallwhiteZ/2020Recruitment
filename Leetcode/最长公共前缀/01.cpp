//
// Created by wtZhou on 2020/9/10.
//

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if(strs.size()==0){
            return "";
        }
        int minmax=19999999;
        for(int i=0;i<strs.size();i++){
            if(minmax>strs[i].size()){  //
                minmax=strs[i].size();
            }
        }
        for(int i=0;i<minmax;i++){
            char c=strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(c!=strs[j][i]){
                    return ans;
                }
            }
            ans+=c;
        }
        return ans;
    }
};

int main(){
    Solution solu;
    vector<string> strs;
    string s1="flower";string s2="flow";string s3="flight";
    strs.push_back(s1);strs.push_back(s2);strs.push_back(s3);
    cout<<solu.longestCommonPrefix(strs);
    return 0;
}