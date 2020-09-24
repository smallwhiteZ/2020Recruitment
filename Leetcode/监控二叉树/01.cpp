//
// Created by wtZhou on 2020/9/23.
//

#include <iostream>
using namespace std;

// * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int ans=0;
    int traversal(TreeNode* root) {  //traversal
        /* 思路：
        1. 后序遍历
        2. 状态转移条件
            2.1  状态变量 0有覆盖, 1有摄像头, 2无覆盖
            2.2 1. left==0 && right==0  root=2;
                2. left==0 && right==1  root=0
                3. left==0 && right==2  root=1
                4. left==1 && right==0  root=0
                5. left==1 && right==1  root=0
                6. left==1 && right==2  root=1
                7. left==2 && right==0  root=1
                8. left==2 && right==1  root=1
                9. left==2 && right==2  root=1
        */

        if(root==NULL){
            return 0;
        }
        int i=traversal(root->left);   // 粗心了，写成了 int i = minCameraCover(root->left)
        int j=traversal(root->right);
        if(i==0 && j==0){
            return 2;
        }
        else if(i==0 && j==1){
            return 0;
        }
        else if(i==0 && j==2){
            ans++;
            return 1;
        }
        else if(i==1 && j==0){
            return 0;
        }
        else if(i==1 && j==1){
            return 0;
        }
        else if(i==1 && j==2){
            ans++;
            return 1;
        }
        else if(i==2 && j==0){
            ans++;
            return 1;
        }
        else if(i==2 && j==1){
            ans++;
            return 1;
        }
        else if(i==2 && j==2){ // 2 2
            ans++;
            return 1;
        }
        else{
            return -1;
        }
    }

    int minCameraCover(TreeNode* root){
        //ans=0;
        if (traversal(root)==2){ // 这一步是必须要的，因为到根节点，当左右子树的状态为0，0 ，此时根节点为2，然后就退出了，但是那样不符合条件
            ans++;
        }
        return ans;
    }
};

int main(){
    TreeNode *t1=new TreeNode(0); t1->left=NULL; t1->right=NULL;
    TreeNode *t2=new TreeNode(0); t2->left=NULL; t2->right=t1;
    TreeNode *t3=new TreeNode(0); t3->left=t2; t3->right=NULL;
    TreeNode *t4=new TreeNode(0); t4->left=t3; t4->right=NULL;
    TreeNode *t5=new TreeNode(0); t5->left=t4; t5->right=NULL;

    Solution solu;
    solu.minCameraCover(t5);
    return 0;
}