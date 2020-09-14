//
// Created by wtZhou on 2020/9/3.
//
// 熟悉一下STL中的queue的常用使用方法，还有涉及到pair

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int numIslands(vector<vector<char>>& grid) {
    if(grid.empty()){
        return 0;
    }
    int nr=grid.size();
    int nc=grid[0].size();
    int cnt=0;
    queue<pair<int,int>> qu;
    for(int r=0;r<nr;r++){
        for(int c=0;c<nc;c++){
            if(grid[r][c]=='1'){
                cnt++;
                grid[r][c]='0';
                qu.push({r,c});
                while(!qu.empty()){
                    pair<int,int> tmp=qu.front();
                    /// grid[tmp.first][tmp.second]='0'; /// 如果在出队的时候弹出的话，遍历的次数会变多，有些case会超出时间限制
                    qu.pop();
                    int i=tmp.first,j=tmp.second;
                    if(i-1>=0 && grid[i-1][j]=='1'){ // 上面
                        qu.push({i-1,j});
                        grid[i-1][j]='0';
                    }
                    if(j-1>=0 && grid[i][j-1]=='1'){ // 左面
                        qu.push({i,j-1});
                        grid[i][j-1]='0';
                    }
                    if(i+1<nr && grid[i+1][j]=='1'){ // 下面
                        qu.push({i+1,j});
                        grid[i+1][j]='0';
                    }
                    if(j+1<nc && grid[i][j+1]=='1'){ // 右面
                        qu.push({i,j+1});
                        grid[i][j+1]='0';
                    }
                }
            }
        }
    }
    return cnt;
}

int main(){
    return 0;
}