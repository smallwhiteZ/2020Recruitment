//
// Created by wtZhou on 2020/9/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn = 10005;
int edge[maxn][maxn];//edge[i][j] == 1 代表i，j可以匹配
int vis[maxn];//用来记录该点是否被访问过
int cx[maxn], cy[maxn];//用来记录x集合中匹配的y元素是哪个
int nx, ny;//nx表示x集合的顶点个数， ny表示y集合的顶点个数

int line(int u){
    int v;
    for(v = 0; v < ny; v++){
        if(edge[u][v] && !vis[v]){
            vis[v] = 1;
            if(cy[v] == -1 || line(cy[v])){//如果y集合中的v没有匹配或v已经匹配，但从cy[v]中可以找到一条增广路
                cx[u] = v;//找到增广路，修改匹配
                cy[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int maxmatch(){
    int sum = 0, i;
    memset(cx, 0xff, sizeof(cx));//初始值为-1表示两个集合中都没有匹配的元素
    memset(cy, 0xff, sizeof(cy));
    for(i = 0; i <= nx; i++){
        if(cx[i] == -1){//还没被匹配就执行内部代码
            memset(vis, 0, sizeof(vis));//重置标记为未访问
            sum += line(i);//以 i 为起点开始查找增广路，返回true ，匹配数+1
        }
    }
    return sum;
}
int main(){
    int x, y, t;
    string c;
    vector<int> male;
    int max=0;
    //vector<bool> mal(100000,false);
    vector<int> female;
    //vector<int> fem(100000,false);
    string tm;
    int cou=0;
    while(getline(cin,tm)){
        //int cou=0;
        for(int i=0;i<tm.size();i++){
            if(tm[i]!=' '){
                if(max<(tm[i]-'0')){
                    max=tm[i]-'0';
                }
            }
            cou++;
        }
        if(cou==2*tm.size()){
            break;
        }
    }
///    while(getline(cin,tm)){  ？？？？？？
//        tm=c[0]-'0';
//        female.push_back(tm);
//        //fem[t]=false;
//        if(max<tm){
//            max=tm;
//        }
//    }
    nx=max+1,ny=max+1;
    while(scanf("%d", &t) && t){
        //scanf("%d%d", &nx, &ny);
        memset(edge, 0, sizeof(edge));
        for(int i = 0; i < t; i++){
            scanf("%d%d", &x, &y);
            edge[x][y] = 1;
        }
        int sum = maxmatch();
        printf("%d\n", sum);
    }

//    string c;
//    while(getline(cin,c)){
//        int t=c[0]-'0';
//        cx[t]=t;
//        mal[t]=false;
//    }
//    while(getline(cin,c)){
//        int t=c[0]-'0';
//        female.push_back(t);
//        fem[t]=false;
//    }
    return 0;
}

/*
5
3 3
0 4
0 3
1 3
1 4
2 5

0 1 2
3 4 5
6
0 4
0 3
1 3
1 4
2 5
2 4

 */
