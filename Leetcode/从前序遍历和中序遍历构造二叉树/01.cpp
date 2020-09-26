//
// Created by wtZhou on 2020/9/26.
//
/// 由二叉树遍历构造二叉树的变种还有很多，主要还是思路，是不是掌握

#include <vector>
#include <iostream>
using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 思路： 从前序和中序遍历构造二叉树
        //      1. 从前序的“第一个”结点为根，然后到中序找哪个是这个根节点，然后确定左子树的长度大小，然后剩余的就是右子树的长度大小
        return build(preorder, inorder, 0, preorder.size()-1, 0 , inorder.size()-1);
    }
    TreeNode* build(vector<int> preorder, vector<int> inorder, int ll, int lr, int rl, int rr){
        if(ll>lr || rl>rr){
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[ll]);
        int index_in=rl;
        while(inorder[index_in] != preorder[ll]){
            index_in++;
        }
        root->left = build(preorder, inorder, ll+1, ll+1+(index_in-rl-1) , rl, index_in-1);
        root->right = build(preorder, inorder, ll+1+(index_in-rl),lr, index_in+1, rr);
        return root;
    }
};

int main(){
    Solution solu;
    vector<int> preorder={3,9,20,15,7};
    vector<int> inorder ={9,3,15,20,7};
    solu.buildTree(preorder,inorder);
    return 0;
}