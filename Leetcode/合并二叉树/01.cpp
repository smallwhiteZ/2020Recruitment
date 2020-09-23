//
// Created by wtZhou on 2020/9/23.
//


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *cur1=t1, *cur2=t2, *cur3=NULL;
        //TreeNode *cur3 = new TreeNode();
        if(cur1 && cur2){
            cur3 = new TreeNode();
            cur3->val = cur2->val + cur1->val;
        }
        else if(cur1 && !cur2){
            cur3=new TreeNode();
            cur3->val = cur1->val;
        }
        else if(!cur1 && cur2){
            cur3 = new TreeNode();
            cur3->val = cur2->val;
        }
        else if(!cur1 && !cur2){
            return NULL;
        }
        if(cur3){
            // 问题出现在cur1->left 和 cur2->left没有提前判断下cur1和cur2是否为NULL
            // cur3->left = mergeTrees(cur1->left, cur2->left);
            // cur3->right = mergeTrees(cur1->right, cur2->right);
            if(cur1 && cur2){
                cur3->left = mergeTrees(cur1->left,cur2->left);
                cur3->right = mergeTrees(cur1->right,cur2->right);
            }
            else if(cur1 && !cur2){
                cur3->left = mergeTrees(cur1->left,NULL);
                cur3->right = mergeTrees(cur1->right,NULL);
            }
            else if(!cur1 && cur2){
                cur3->left = mergeTrees(NULL,cur2->left);
                cur3->right = mergeTrees(NULL,cur2->right);
            }
        }
        return cur3;
    }
};