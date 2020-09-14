//
// Created by wtZhou on 2020/9/11.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 要达到顺时针旋转90的效果，需要如下两步骤
        // 先转置
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix[0].size();j++){  /// 矩阵的转置这一块没有写好
                swap(matrix[i][j],matrix[j][i]);
        }
        // 再按列对换
        for(int i=0;i<matrix.size()/2;i++){
            for(int j=0;j<matrix[0].size();j++){
                swap(matrix[j][i],matrix[j][matrix.size()-1-i]);
            }
        }
    }
};

int main(){
    vector<vector<int>> matrix;
    //{1,2,3},{4,5,6},{7,8,9}
    vector<int> m({1,2,3});
    vector<int> m2({4,5,6});
    vector<int> m3({7,8,9});
    matrix.push_back(m);matrix.push_back(m2);matrix.push_back(m3);
    Solution solu;
    solu.rotate(matrix);
    return 0;
}