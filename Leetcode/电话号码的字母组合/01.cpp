//
// Created by wtZhou on 2020/10/10.
//
/// 自己在做的时候没有做出来，但是这是基础的回溯算法，也感觉到需要采用二重循环以及需要一个标志标致路径的当前的下标
/// 在借鉴到了正确的题解之后，发现不需要在dfs中进行二重循环，而是在里面的for循环的j初始化是之前没有想到的

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> alph;
        if(digits.size()==0){
            return alph;
        }
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
        for(int i=0;i<alph.size();i++){
            string tmp;
            dfs(alph, ans, i,tmp);
        }
        return ans;
    }

    void dfs(vector<string> alph, vector<string>& ans, int k, string &tmp){
        if(tmp.size() == alph.size()){
            ans.push_back(tmp);
            return;
        }
        for(int j=k;j<alph[k].size();j++){
            tmp.push_back(alph[k][j]);
            dfs(alph, ans,k,tmp);
            tmp.pop_back();
        }
    }
};

int main(){
    Solution solu;
    string digits="23";
    solu.letterCombinations(digits);
    return 0;
}