//
// Created by wtZhou on 2020/8/28.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size()==1){// 添加这一块是因为超时
            return s;
        }
        if(numRows==1){ // 添加这一块是因为超时
            return s;
        }
        string temp[numRows];
        int lens = s.size();
        int count=0;
        while(count<lens){
            for(int i=0;count<lens && i<numRows-1;i++){  // 需要添加count<lens 不然会出现字符串的后面有添加“”字符串
                //string t=(string)(s[i]);
                //temp[i].append();
                temp[i] = temp[i] + s[count++];
            }
            for(int j=numRows-1;count<lens && j>0;j--){
                temp[j]= temp[j]+s[count++];
            }
        }
        string ans;
        for(int i=0;i<numRows;i++){
            ans.append(temp[i]);
        }
        return ans;
    }
};

int main(){
    //string s="LEETCODEISHIRING";
    string s2="PAYPALISHIRING";
    int numrows = 3;
    Solution solu;
    cout<<"\"";
    cout<<solu.convert("A",1);
    cout<<"\"";
    return 0;
}