//
// Created by wtZhou on 2020/9/25.
//

/// 总结踩过的坑： 1. 首先需要理清思路  2. 在切分左右子树的时候曾尝试后序遍历中的左右子树的下标，但是在一些特殊的子树上没有处理好，
///                                   因此改用 得到长度了之后，借鉴参考答案，直接通过中序遍历的切分情况，得到后序遍历中的下标具体情况

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 思路： 由后序最后得知根节点，则分为将中序遍历分为左半子树和右半子树，然后从中序中找到该节点对应的下边，
        // 以此节点将中序划分为左子树和右子树，将此节点的左边一个索引作为标记，找到后续遍历中对应的下标，划分后序遍历中的
        // 左子树和右子树
        int inor[10000];
        int inorindex =0;
        int postor[10000];
        int postindex = 0;
        for(int i=0;i<inorder.size();i++){
            inor[inorindex++]=inorder[i];
        }
        for(int i=0;i<postorder.size();i++){
            postor[postindex++]=postorder[i];
        }
        TreeNode *root = build(inor, postor,0,inorder.size()-1,0,postorder.size()-1);
        return root;
    }

    TreeNode* build(int* inorder,int* postorder,int ll,int lr,int rl,int rr){
        if(ll>lr || rl>rr){
            return NULL;
        }
        TreeNode *root=new TreeNode(postorder[rr]);
        // int *index_itp = find(inorder+ll,inorder+lr,postorder[rr]);
        // if(rl == rr){  // 加上这一步的目的是什么?
        //     return root;
        // }
        int index_it = ll;
        while(inorder[index_it] != postorder[rr]){
            index_it++;
        }

        // 尝试失败，没有考虑到一些特殊的子树，导致一些下标情况没有考虑到
        // int *post_itp = find(postorder+rl,postorder+rr,inorder[index_it]);
        // int post_it = *post_itp;
        // int post_it = rl;
        // if(index_it>=1){
        //     while(postorder[post_it] != inorder[index_it-1]){
        //         post_it++;
        //     }
        //     root->left = build(inorder, postorder, ll, index_it-1, rl, post_it);
        //     root->right = build(inorder, postorder, index_it+1,lr,post_it+1,rr-1);
        // }
        // else{
        //     root->left = NULL;
        //     root->right = build(inorder, postorder, index_it+1,lr,post_it+1,rr-1);
        // }

        root->left = build(inorder, postorder, ll, index_it-1, rl, rl+index_it-ll-1);
        root->right = build(inorder, postorder, index_it+1,lr,rl+index_it-ll,rr-1);
        return root;
    }
};