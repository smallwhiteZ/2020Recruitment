//
// Created by wtZhou on 2020/9/3.
//

///给你一个由'1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
///
///岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
///
///此外，你可以假设该网格的四条边均被水包围。

#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<char>> &a,int row,int col){
    int i=a.size();
    int j=a[0].size();
    a[row][col]='0'; /// 为啥是这样的？
    if(row-1>=0&&a[row-1][col]=='1') { /// 上面
        dfs(a,row-1,col);
    }
    if(col-1>=0&&a[row][col-1]=='1'){  ///左面
        dfs(a,row,col-1);
    }
    if(row+1<i&&a[row+1][col]=='1') { /// 下面
        dfs(a,row+1,col);
    }
    if(col+1<j&&a[row][col+1]=='1') { /// 右边
        dfs(a,row,col+1);
    }
}

int numIslands(vector<vector<char>>& grid) {
    if(!grid.size()){
        return 0;
    }
    int cnt=0;
    int nr=grid.size();
    int nc=grid[0].size();
    for(int i=0;i<nr;i++){ /// 看下是不是i<grid.size()的问题
        for(int j=0;j<nc;j++){
            if(grid[i][j]=='1'){
                cnt++;
                dfs(grid,i,j);
            }
            /// bfs(grid,i,j); 不是放在这儿的
        }
    }
    return cnt;
}

int main(){
    vector<vector<char>> a;
    return 0;
}