//
// Created by wtZhou on 2020/9/16.
//
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        vector<int> tmp;
        //vector<bool> isvis;
        for(int i=0;i<matrix.size();i++){
            int j=0;
            int k=i;
            //isvis[i]=false;
            while(k>=0 && j<matrix[0].size()){
                tmp.push_back(matrix[k][j]);
                j++;k--;
            }
            if(i & 1){
                reverse(tmp.begin(),tmp.end()); // reverse前面不需要加上tmp.
            }
            ans.push_back(tmp);
            tmp.clear();  /// 忘了加这个
        }
        vector<int> a;
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[0].size();j++){
                a.push_back(matrix[i][j]);
            }
        }
        return a;
    }
};

int main(){
    Solution solu;
    vector<vector<int>> matrix;
    matrix.push_back({1,2,3});
    matrix.push_back({4,5,6});
    matrix.push_back({7,8,9});
    solu.findDiagonalOrder(matrix);
    return 0;
}