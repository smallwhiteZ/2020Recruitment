//
// Created by wtZhou on 2020/9/8.
//

///  字符串处理比较麻烦，没有顺好如何去解决这个问题。。

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;


int main()
{
    //vector<pair<char,string>> ss;
//    unordered_map<char,string> ss;
//    for(int i=0;i<26;i++){
//        //string s;
//        ss.insert('a'+i,0b1 + i);
//        //itoa(1+i,s,2);
//    }
//    for(int i=0;i<26;i++){
//        ss.insert('A'+i,0b011011 +i);
//    }
//    for(int i=0;i<10;i++){
//        ss.insert('0'+i,0b110101 +i);
//    }
//    cout<<ss['A'];
    string s;
    cin>>s;
    int i=0;
    if(s.empty()){
        cout<<"0";
    }
    else if(s.size()<=6){
        long long ans=0;
        int len=s.size();
        for(int i=0;i<len;i++){
            char tmp=s[len-1-i];
            string tmps;
//            string tmps=ss[tmp];
//            for(int k=0;k<tmps.size();k++){
//                //string t=tmp;
//            }
            if(tmp>='a' && tmp<='z'){
                for()
            }

        }
    }
    else{

    }
    return 0;
}