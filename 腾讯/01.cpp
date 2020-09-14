//
// Created by wtZhou on 2020/8/23.
//

#include <stack>
#include <iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    int lens = s.size();
    if(lens<=0 || lens>200){
        return -1;
    }
    int stack[4]={0};
    for(int i=0;i<lens;i++){
        char c = s[i];
        switch(c){
            case '(': stack[0]++;break;
            case '[': stack[1]++;break;
            case ')':
                stack[2]++;
                if(stack[0]>0){
                    stack[0]--;
                    stack[2]--;
                }
                break;
            case ']':
                stack[3]++;
                if(stack[1]>0){
                    stack[1]--;
                    stack[3]--;
                }
                break;
        }
    }
    int ans=0;
    for(int i=0;i<4;i++){
        ans+=stack[i];
    }
    cout<<ans;
    return 0;
}