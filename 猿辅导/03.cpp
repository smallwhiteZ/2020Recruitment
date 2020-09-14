//
// Created by wtZhou on 2020/9/12.
//

#include <iostream>
#include <string>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        string s1,s2,s3;
        int K;
        cin>>s1>>s2>>s3;
        cin>>K;
        int i=0,lens1=s1.size();
        int j=0,lens2=s2.size();
        int k=0,lens3=s3.size();
        int cnt=0;
        bool ltag=false, rtag=false;
        while(k<lens3){
            ltag=false,rtag=false;
            while(k<lens3 && i<lens1 && s3[k]==s1[i]){
                i++;
                k++;
                ltag=true;
            }
            if(ltag){
                cnt++;
            }
            while(k<lens3 && j<lens2 && s3[k]==s2[j]){
                j++,k++;
                rtag=true;
            }
            if(rtag){
                cnt++;
            }
            if(!ltag && !rtag){
                break;
            }
        }
        if(k==lens3){
            if(cnt<=K){
                cout<<"1";
            }
            else{
                cout<<"0";
            }
        }
        else{
            cout<<"0";
        }
        if(T!=0){
            cout<<endl;
        }
    }
    return 0;
}

/*
1
ac bb abbc 3
 */