//
// Created by wtZhou on 2020/9/6.
//

//
// Created by wtZhou on 2020/9/6.
//

#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
//vector<int> visit;
//vector<int> res_vec;
//vector<vector<int>> ans_vec;

int main()
{
    int a[8]={5,4,3,2,2,3,4,5};
    int maxlen=0;
    int kl=7/2;
    int kr=kl+1;
    if(a[kl]==a[kr]){
        while(kl>=1 && kr+1<8){
            if(a[kl]<a[kl-1] && a[kr]<a[kr+1])
            {
                kr++;
                kl--;
            }
        }
        if(kl==0 && kr==7){
            int curlen=8;
            if(curlen>maxlen){
                maxlen=curlen;
            }
        }
    }

    cout<<maxlen;
    return 0;
}
