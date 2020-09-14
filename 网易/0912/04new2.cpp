//
// Created by wtZhou on 2020/9/12.
//

#include <cstdio>
#include <queue>
using namespace std;
#define MAX_N 100
bool flag=true;//记录答案
bool G[MAX_N][MAX_N];//邻接矩阵
int m,n,Col[MAX_N+5];//记录边数、结点数和结点的颜色
queue<int>Q;//定义队列进行拓展
void Bfs(int x){
    Q.push(x);//初始结点入队
    Col[x]=0;//颜色为0
    while(!Q.empty()){
        int p=Q.front();
        Q.pop();
        for(int i=1;i<=n;i++)
            if(G[p][i]){//枚举相连结点
                if(Col[i]==Col[p])//根据判定，相同颜色则不为二分图
                    flag=false;//记录答案
                else if(Col[i]==-1){
                    Col[i]=!Col[p];//与之相反的颜色
                    Q.push(i);//入队拓展
                }
            }
    }
}
int main(){
    while(scanf("%d",))
    scanf("%d",&m); // m边数
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u][v]=G[v][u]=true;
    }
    memset(Col,-1,sizeof Col);//初始状态都为-1
    for(int i=1;i<=n;i++)//需要枚举每个结点，考虑多个连通块的情况
        if(Col[i]==-1)
            Bfs(i);
    if(!flag)   puts("False");
    else puts("True");
}