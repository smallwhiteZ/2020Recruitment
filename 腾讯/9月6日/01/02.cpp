//
// Created by wtZhou on 2020/9/6.
//

#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int maxlen=0;
void dfs(int i,vector<int> &visit,vector<int> &res_vec){
    if(i>=visit.size()){
        vector<int> new_vec;
        for(int j=0;j<visit.size();j++)
            if(visit[j]==1)
                new_vec.push_back(res_vec[j]);
        if (new_vec.empty() || new_vec.size() & 1) {
            //
        }
        else {
            int kl = (new_vec.size() - 1) / 2;
            int kr = kl + 1;
            if (new_vec[kl] == new_vec[kr]) {
                while (kl >= 1 && kr + 1 < new_vec.size()) {
                    if (new_vec[kl] < new_vec[kl - 1] && new_vec[kr] < new_vec[kr + 1]) {
                        kr++;
                        kl--;
                    }
                }
                if (kl == 0 && kr == new_vec.size() - 1) {
                    int curlen = new_vec.size();
                    if (curlen > maxlen) {
                        maxlen = curlen;
                    }
                }
            }
        }
        return;
    }
    visit[i]=0;
    dfs(i+1,visit,res_vec);
    visit[i]=1;
    dfs(i+1,visit,res_vec);
}

int main()
{
    int T;
    cin>>T;
    while(T--) {
        vector<int> visit;
        vector<int> res_vec;
        int n;
        cin >> n;
        int num;
        for (int i = 1; i <= n; i++) {
            cin >> num;
            visit.push_back(1);
            res_vec.push_back(num);
        }
        dfs(0, visit, res_vec);
        cout << maxlen<<endl;
        maxlen=0;
    }
    return 0;
}