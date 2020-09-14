//
// Created by wtZhou on 2020/8/28.
//

#include <iostream>
#include <string>
using namespace std;
int main(){
    int T;
    cin>>T;
    int count = 1;
    while(count<=T){
        cout<<"Case #"<<count<<":"<<endl;
        int n,m;
        cin>>n>>m;
        int map[n][n];
        int x = 0,y=0;
        int curdir = 1;
        for(int i=0;i<m;i++){
            string c;
            cin>>c;
            if(c == "L"){
                curdir=curdir%4+1;
            }
            else if(c == "R"){
                curdir=curdir-1;
                if(curdir==0){
                    curdir=4;
                }
            }
            else if(c == "G"){
                int step;
                cin>>step;
                if(curdir==1){
                    if(y-step>=0){
                        y=y-step;
                    }
                    else{
                        y=0;
                    }
                }
                else if(curdir==2){
                    if(x-step>=0){
                        x=x-step;
                    }
                    else{
                        x=0;
                    }
                }
                else if(curdir==3){
                    if(y+step<n){
                        y=y+step;
                    }
                    else{
                        y=n-1;
                    }
                }
                else{
                    if(x+step<n){
                        x=x+step;
                    }
                    else{
                        x=n-1;
                    }
                }
            }
            else if(c == "P"){
                cout<<x<<" "<<y<<endl;
            }
            else{}
        }
        count++;
    }
    return 0;
}