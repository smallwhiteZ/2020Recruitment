//
// Created by wtZhou on 2020/9/12.
//

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> aa,vector<vector<bool>>& flag,int i, int j, int zx,int zy, int& tmp,int& ans){
    if(i==zx && j==zy){
        if(tmp<ans){
            ans=tmp;
        }
    }
    else{
        for(int t=i;t<aa.size();t++){
            for(int s=j;s<aa.size();s++){
                if(!flag[t][s]){
                    if(t+1<aa.size() && !flag[t+1][s]){// 右边
                        tmp+=aa[t+1][s];
                        flag[t+1][s]=true;
                        dfs(aa,flag,t+1,s,zx,zy,tmp,ans);
                        flag[t+1][s]=false;
                        tmp-=aa[t+1][s];
                    }
                    if(t-1>=0 && !flag[t-1][s]){ // 左边
                        tmp+=aa[t-1][s];
                        flag[t-1][s]=true;
                        dfs(aa,flag,t-1,s,zx,zy,tmp,ans);
                        flag[t-1][s]=false;
                        tmp-=aa[t-1][s];
                    }
                    if(s-1>=0 && !flag[t][s-1]){ // 上边
                        tmp+=aa[t][s-1];
                        flag[t][s-1]=true;
                        dfs(aa,flag,t,s-1,zx,zy,tmp,ans);
                        flag[t][s-1]=false;
                        tmp-=aa[t][s-1];
                    }
                    if(s+1<aa.size() && !flag[t][s+1]){// 下边
                        tmp+=aa[t][s+1];
                        flag[t][s+1]=true;
                        dfs(aa,flag,t,s+1,zx,zy,tmp,ans);
                        flag[t][s+1]=false;
                        tmp-=aa[t][s+1];
                    }
                }
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    //char a[n][n];
    //vector<vector<char>> a;
    //bool flag[n][n];
    //vector<vector<bool>> flag;
    vector<vector<int>> aa;
    vector<vector<bool>> flag;
    int qx,qy,zx,zy;
    cin>>qx>>qy>>zx>>zy;
    for(int i=0;i<n;i++){
        vector<int> qv;
        vector<bool> fl;
        for(int j=0;j<n;j++){
            char q;
            cin>>q;
            if(q=='#' || q=='@'){
                qv.push_back(1000000);
            }
            else{
                qv.push_back(1);
            }
            fl.push_back(false);
        }
        aa.push_back(qv);
        flag.push_back(fl);
    }
    int tmp=0,ans=20000000;
    dfs(aa,flag,qx,qy,zx,zy,tmp,ans);
    cout<<ans;
    return 0;
}
/*
15
0 7 7 7
*5#++B+B+++++$3
55#+++++++###$$
###$++++++#+*#+
++$@$+++$$$3+#+
+++$$+++$+4###+
A++++###$@+$++A
+++++#++$#$$+++
A++++#+5+#+++++
+++$$#$++#++++A
+++$+@$###+++++
+###4+$+++$$+++
+#+3$$$+++$##++
+#*+#++++++#$$+
$####+++++++$##
3$+++B++B++++#5




 */