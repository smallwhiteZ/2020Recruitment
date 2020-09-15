//
// Created by wtZhou on 2020/9/15.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& board, int& pos){
        if(pos==spaces.size()){/// 等于什么？？？
            ans=true;
            return;
        }
        else{
            /// 下面的循环怎么走
            auto [i,j]=spaces[pos];
            for(int k=0; k<9 && !ans; k++){
                if(!ans && !line[i][k] && !column[j][k] && !block[i/3][j/3][k]){
                    line[i][k]=true; column[j][k]=true; block[i/3][j/3][k]=true;
                    pos++;board[i][j]='1'+k;
                    dfs(board,pos);
                    pos--;//board[i][j]='.';
                    line[i][k]=false; column[j][k]= false; block[i/3][j/3][k]= false;
                }
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(line,false,sizeof(line)); /// 为啥是sizeof(line)
        memset(column,false,sizeof(column));
        memset(block,false,sizeof(block));
        ans=false;
        int pos=0;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int tmp=board[i][j]-'0';
                    line[i][tmp-1]=true;
                    column[j][tmp-1]=true;
                    block[i/3][j/3][tmp-1]=true;
                }
                else{
                    spaces.push_back({i,j});
                }
            }
        }
        dfs(board,pos);

    }

private:
    bool line[9][9];
    bool column[9][9];
    bool block[3][3][9];
    bool ans;
    vector<pair<int,int>> spaces; /// 这个遗漏了
};