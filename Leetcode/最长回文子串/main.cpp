//
// Created by wtZhou on 2020/8/22.
//

/*
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：
输入: "cbbd"
输出: "bb"
 */

#include <string>
#include <iostream>
using namespace std;

//class Solution {
//public:
//    int Ishuiwen(string s1){
//        int i=0,j=s1.size()-1;
//        while(i<j){
//            if(s1[i]!=s1[j]){
//                return 0;
//            }
//            i++, j--;
//        }
//        return 1;
//    }
////    string longestPalindrome(string s) {
////        int maxlen=0;
////        string ans,subs;
////        int lens = s.size();
////        for(int i=0;i<lens;i++){
////            for(int j=i+maxlen; j<lens;j++){  // j由j变为j+maxlen为一次优化
////                subs= s.substr(i,j-i+1);
//////                if(Ishuiwen(subs)){     // 这里是可以优化的，优化的形式如下
//////                    if(maxlen<j-i+1){
//////                        ans = subs;  //有待考察 =
//////                        maxlen = j-i+1; // 需要记录长度
//////                    }
//////                }
////                if(maxlen<j-i+1){
////                    if(Ishuiwen(subs)){
////                        ans = subs;
////                        maxlen = j-i+1;
////                    }
////                }
////            }
////        }
//
//        string longestPalindrome(string s) {
//            int maxlen = 0;
//            string ans,subs;
//            bool flag[1000][1000];
//            int lens = s.size();
//            for(int i=1;i<=lens;i++){
//                for(int j=0; j<lens;j++){  // j由j变为j+maxlen为一次优化
//                    //subs= s.substr(i,j-i+1);
//                    // 动态规划
//                    flag[i][j]= i == 1 || i ==2 || flag[i+1][j-1] && s[i]==s[j];
//                }
//            }
//        //cout<<ans;
//        return ans;
//    }
//    // 采用常规方法仍然超时，因此需要采用其他的方法
//    // 动态规划、马拉车算法
//};

// 上面方法为暴力求解，算法复杂度过高

class Solution {
public:
    string longestPalindrome(string s) {
        //bool flag[1000][1000]={false};
        int lens = s.size();
        bool flag[1000][1000] = {false};
        int maxsublen=1, startindex=0;
        for(int i=0;i<lens;i++) {
            //先把主对角线和次对角线进行填充
            flag[i][i] = true;
            if (i < lens-1 && s[i] == s[i + 1]) {
                flag[i][i + 1] = true;
                if(maxsublen<2){
                    // 少了这一块的话，会使得只有2个字符串的情况没有考虑到，也是为啥不会过cbbd的情况
                    maxsublen=2;
                    startindex=i;
                }
            }
        }
        for(int i=lens-2;i>=0;i--){
            //对
            for(int j=lens-1;j>i;j--){
                //cout<< flag[i+1][j-1] << "  " <<s[i]<< "   "<<s[j];
                if(flag[i+1][j-1] && s[i]==s[j]){
                    //cout<< flag[i+1][j-1] << "  " <<s[i]<< "   "<<s[j];
                    flag[i][j]=true;
                    if(maxsublen<j-i+1){
                        maxsublen = j-i+1;
                        startindex = i;
                    }
                }
            }
        }
        return s.substr(startindex,maxsublen);
    }
};

int main(){
    string s = "babad";
    string s2 = "cbbd";
    Solution solu;
    cout<<solu.longestPalindrome(s2)<<endl;
    return 0;
}



