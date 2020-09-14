//
// Created by wtZhou on 2020/9/4.
//
///  还是需要复习

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<string> binaryTreePaths(TreeNode *root){
    vector<string> ans;
    queue<TreeNode*> qu;
    //string tmp;

    ///
    queue<string> qustring; /// 没有想到使用 string的队列
    if(root){
        //tmp+= to_string(root->val); /// 先处理节点
        qu.push(root);
        qustring.push(to_string(root->val));  ///
        while(!qu.empty()){
            TreeNode *p=qu.front();
            string tmp = qustring.front();
            qu.pop();
            qustring.pop();
            if(p->left==NULL && p->right==NULL){
                ans.push_back(tmp); ////  层序遍历的细节还需研究研究
                ///qustring.pop();
                /// tmp.pop_back();  /// 退出来不知道是不是有效的
                /// tmp.pop_back(); /// 本意是剔除“->”，不清楚能不能实现
            }
            if(p->left){
                //tmp+="->";
                qu.push(p->left);

                qustring.push(tmp+"->"+to_string(p->left->val));
            }
            if(p->right){
                //tmp+="->";
                qu.push(p->right);
                qustring.push(tmp+"->"+to_string(p->right->val));
            }
//            if(p->right || p->left) {
//                tmp += "->";
//            }
        }
    }
    return ans;
}

/// 有问题