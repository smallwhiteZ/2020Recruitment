//
// Created by wtZhou on 2020/9/22.
//

// sum的保存节点之前的和，不能简单考虑成 加上最接近他的小于的节点的值，
//    5
//  3   7
// 1 4 6  8
// 考虑上面这棵树，按照自己的想法就是5保存是7节点的值，但是实际上不是这样的，而是加上6节点的值
// 基于这样的考虑，采用一个全局变量sum是比较方便的

// 下面给出非递归的版本的解法，递归的在leetcode

#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        TreeNode *cur = root;
        stack<TreeNode*> st;
        int sum = 0;

//        卡在中序遍历的非递归写法上，重要的想好这里面的细节和节点的遍历过程
//        while(cur || !st.empty()){
//            while(cur){
//                st.push(cur);
//                cur = cur->right;
//            }
//            cur = st.top();  // 出现死循环的情况，因为cur一直在重新指向之前访问的节点
//
//            // 实际的操作
//            sum += cur->val;
//            cur->val = sum;
//            //
//
//            st.pop();
//            if(cur->left){
//                // st.push(cur->left);
//                cur = cur->left;
//            }
//        }

        while(cur){
            st.push(cur);
            cur = cur->right;
        }
        while(!st.empty()){
            cur = st.top();
            st.pop();
            sum += cur->val;
            cur->val = sum;
            cur = cur->left;
            while(cur){
                st.push(cur);
                cur = cur->right;
            }
        }
        return root;
    }
};