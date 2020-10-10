//
// Created by wtZhou on 2020/9/29.
//

/**
 * 参考了一位的大神的解法：
 * 后序遍历为 左右中， 则将前序遍历（中左右），先产生一个变种（中右左），然后再反转一下，即可变成左右中
**/

#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        while(root || !st.empty()){
            while(root){
                ans.push_back(root->val);
                st.push(root);
                root=root->right;
            }
            root = st.top();
            st.pop();
            if(root->left){
                root=root->left;
            }
            else{
                root=NULL; ///  这一步很重要，在回顾前序遍历的非递归过程中，这一步为NULL想了一会，但是终究不是一个一蹴而就的写法
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};