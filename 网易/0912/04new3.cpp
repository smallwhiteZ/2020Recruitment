//
// Created by wtZhou on 2020/9/12.
//

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N  = 510, M = 100010;
int e[M], ne[M], h[N], idx;
int st[N];  //标记已经遍历过的女生
int match[N]; //每一个女生的对象

int n1, n2, m;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x){
    for(int i = h[x]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            st[j] = true;
            if(!match[j] || find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
int main(){
    string c;
    vector<int> male;
    //vector<bool> mal(100000,false);
    vector<int> female;
    //vector<int> fem(100000,false);
    while(getline(cin,c)){
        int t=c[0]-'0';
        male.push_back(t);
        //mal[t]=false;
    }
    while(getline(cin,c)){
        int t=c[0]-'0';
        female.push_back(t);
        //fem[t]=false;
    }

    cin>>m;
    memset(h, -1 ,sizeof h);
    while( m --){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    int res = 0;
    for(int i = 1; i <= n1; i++){
        memset(st, false, sizeof st);
        if(find(i)) res++;
    }

    cout << res;
    return 0;
}
