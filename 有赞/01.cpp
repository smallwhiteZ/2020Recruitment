//
// Created by wtZhou on 2020/9/11.
//

#include <string>
#include <iostream>
#include <map>
using namespace std;

struct alphbet{
    char al;
    int count=0;
};

int main(){
    string l,r;
    cin>>l;
    char c;
    cin>>c;
    cin>>r;
    alphbet sum[26];
    for(int i=0;i<26;i++){
        sum[i].al='a'+i;
        sum[i].count=0;
    }

    for(int i=0;i<l.size();i++){
        if(l[i]>='a' && l[i]<='z'){
            string tmp;
            int k=i;
            while(k+2<l.size() && l[k+2]>='0' && l[k+2]<='9'){
                tmp+=l[k+2];
                k++;
            }
            int t=0;
            for(int j=tmp.size()-1;j>=0;j--){
                t=t*10+j;
            }
            sum[k].count=t;
            i=k;
        }
        else{
            i++;
        }
    }
    for(int i=0;)
    return 0;
}