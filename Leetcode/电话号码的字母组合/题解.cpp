//
// Created by wtZhou on 2020/10/10.
//
/// 以下的代码无法得到正确的结果

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> alph;
        for(int i=0;i<digits.size();i++){
            switch(digits[i]){
                case '2': alph.push_back("abc");break;
                case '3': alph.push_back("def");break;
                case '4': alph.push_back("ghi");break;
                case '5': alph.push_back("jkl");break;
                case '6': alph.push_back("mno");break;
                case '7': alph.push_back("pqrs");break;
                case '8': alph.push_back("tuv");break;
                case '9': alph.push_back("wxyz");break;
            }
        }
        vector<string> ans;
//        for(int i=0;i<alph.size();i++){
//            string tmp;
//            dfs(alph, ans, i,tmp);
//        }
        string tmp;
        dfs(alph,ans,0,tmp);
        return ans;
    }

    void dfs(vector<string> alph, vector<string>& ans, int k, string &tmp){
        // if(tmp.size() == alph.size())
        if(k==alph.size() && tmp.size() == alph.size()){ ///
            ans.push_back(tmp);
            return;
        }
//        for(int j=k;j<alph[k].size();j++){
//            tmp.push_back(alph[k][j]);
//            dfs(alph, ans,k,tmp);
//            tmp.pop_back();
//        }
        for(int i=k;i<alph.size();i++){
            for(int j=0;j<alph[i].size();j++){ /// 为什么是这边是j=0？？？ /// 这个代码无法得到正确的结果，
                tmp.push_back(alph[i][j]);
                dfs(alph,ans,k+1,tmp);
                tmp.pop_back();
            }
        }
    }
};

int main(){
    Solution solu;
    string digits="23";
    solu.letterCombinations(digits);
    return 0;
}