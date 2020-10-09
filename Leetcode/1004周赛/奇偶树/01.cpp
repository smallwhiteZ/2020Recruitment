//
// Created by wtZhou on 2020/10/4.
//

/// 比赛的时候没有写出来的原因是没有熟练掌握层序遍历的每一层的划分方法,
/// 以下代码不能够运行，原因是： 只是将队列不断进队，没有考虑到出队，因此很快出现了 heap-buffer-overflow 的问题，解决的办法就是添加出队的
/// 操作，然后代码的细节需要进行修改

#include <queue>
#include <iostream>
using namespace std;

///Definition for a binary tree node.
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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> qu;
        if(!root){
            return false;
        }
        qu.push(root);
        int cnt=0;
        int fcnt=0;
        int cnts=1;
        int floor=0;
        while(!qu.empty()){
            TreeNode *t=qu.front();
            cnt++;
            if(cnt==cnts){
                vector<TreeNode*> arr;
                while(!qu.empty()){
                    arr.push_back(qu.front());
                    qu.pop();
                }
                if((floor&1)==0){
                    for(int i=cnt;i<=cnts;i++){
                        if((arr[i]->val)%2==0){
                            return false;
                        }
                        if(i<=cnts-1 && arr[i]->val <= arr[i+1]->val){
                            return false;
                        }
                    }
                }
                else{
                    for(int i=cnt;i<=cnts;i++){
                        if((arr[i]->val)%2==1){
                            return false;
                        }
                        if(i<=cnts-1 && arr[i]->val >= arr[i+1]->val){
                            return false;
                        }
                    }
                }
                for(int i=0;i<arr.size();i++){
                    qu.push(arr[i]);
                }
                floor++;
            }

            if(t->left){
                qu.push(t->left);
                fcnt++;
            }
            if(t->right){
                qu.push(t->right);
                fcnt++;
            }
            if(cnt==cnts){
                cnts+=fcnt;
                fcnt=0;
            }
        }
        return true;
    }

};