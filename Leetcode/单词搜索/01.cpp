//
// Created by wtZhou on 2020/9/13.
//
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& board,string word,int k,vector<vector<bool>>& isvis,bool& ans,string &tmp,int x,int y){
        if(k==word.size()){
            if(tmp==word){
                ans=true;
            }
            return;
        }
        else{
            for(int i=x;i<board.size();i++){
                for(int j=y;j<board[0].size();j++){
                    if(!isvis[i][j] && word[k]==board[i][j]){
                        isvis[i][j]=true;
                        k++;
                        tmp+=board[i][j];
                        if(k==word.size()){
                            if(tmp==word){
                                ans=true;
                            }
                            return;
                        }
                        if(i-1>=0 && !isvis[i-1][j] && k<word.size() && word[k]==board[i-1][j]){ // 上面
                            dfs(board,word,k,isvis,ans,tmp,i-1,j);
                        }
                        if(i+1<board.size() && !isvis[i+1][j] && k<word.size() && word[k]==board[i+1][j]){ // 下面
                            dfs(board,word,k,isvis,ans,tmp,i+1,j);
                        }
                        if(j-1>=0 && !isvis[i][j-1] && k<word.size() && word[k]==board[i][j-1]){ // 左面
                            dfs(board,word,k,isvis,ans,tmp,i,j-1);
                        }
                        if(j+1<board[0].size() && !isvis[i][j+1] && k<word.size() && word[k]==board[i][j+1]){ // 右面
                            dfs(board,word,k,isvis,ans,tmp,i,j+1);
                        }

                    }
                }
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> isvis;
        for(int i=0;i<board.size();i++){
            vector<bool> is;
            for(int j=0;j<board[0].size();j++){
                is.push_back(false);
            }
            isvis.push_back(is);
        }
        bool ans=false;
        string tmp;
        dfs(board,word,0,isvis,ans,tmp,0,0);
        return ans;
    }
};

int main(){
    Solution solu;
    vector<char> a1;
    a1.push_back('A'),a1.push_back('B'),a1.push_back('C'),a1.push_back('E');
    vector<char> a2;
    a2.push_back('S'),a2.push_back('F'),a2.push_back('C'),a2.push_back('S');
    vector<char> a3;
    a3.push_back('A'),a3.push_back('D'),a3.push_back('E'),a3.push_back('E');
    vector<vector<char>> board;
    board.push_back(a1),board.push_back(a2),board.push_back(a3);
    string word="ABCCED";
    solu.exist(board,word);
    return 0;
}