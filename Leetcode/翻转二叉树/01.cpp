//
// Created by wtZhou on 2020/9/16.
//
/// 需要注意的是： 这里的翻转是真实的翻转，而不是输出翻转后的结果

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root){
            // cout<<root->val;
            // invertTree(root->right);
            // invertTree(root->left);
            TreeNode *tmp=root->left;
            root->left=root->right;
            root->right=tmp;
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};