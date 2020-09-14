//
// Created by wtZhou on 2020/9/11.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
void backtrack(string A,string B,string &tmp,string &ans,vector<bool> &tt){
    if(tmp.size()==A.size()){
        if(A<tmp){
            if(ans==""){
                ans=tmp;
            }
            else if(tmp<ans){
                ans=tmp;
            }
        }
    }
    else{
        for(int i=0;i<B.size();i++){
            if(!tt[i]){
                if(tmp=="" || tmp>=A.substr(0,tmp.size())){  // 2 >=232
                    tt[i]=true;
                    tmp.push_back(B[i]);
                    backtrack(A,B,tmp,ans,tt);
                    tt[i]=false;
                    tmp.pop_back();
                }
            }
        }
    }
}
int main(){
    string A,B;
    int N;
    cin>>N;
    cin>>A>>B;
    string tmp,ans;
    //string t2 = A.substr(0,1);
    vector<bool> tt(N,false);
    backtrack(A,B,tmp,ans,tt);
    if(ans==""){
        cout<<"-1";
    }
    else{
        cout<<ans;
    }
    return 0;
}
/*
3
123
322

3
421
123

3
232
223

 */