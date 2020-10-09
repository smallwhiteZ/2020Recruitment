//
// Created by wtZhou on 2020/10/4.
//

/**
 * 学习了层序遍历如何保存处理每一层节点的方法,具体实现的方式就是每次处理的时候记录一下当前队列的长度，
 * 然后使用for循环，再每次记录队列的位置

**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root==NULL){
            return false;
        }
        queue<TreeNode*> qu;
        qu.push(root);
        int floor=0;
        vector<TreeNode*> vec;
        while(!qu.empty()){
            int n=qu.size();         /// 每次开始一层的节点进行访问的时候，记录一下队列的长度，就是该层的长度，解决了我的疑惑
            for(int i=0;i<n;i++){    /// 然后对队列里面的元素进行访问，并且保证了一层的长度不变
                if(floor%2==0){
                    //odd, increase
                    TreeNode *cur=qu.front();
                    qu.pop();
                    if(cur->val%2==0){
                        return false;
                    }
                    vec.push_back(cur);
                    if(cur->left){
                        qu.push(cur->left);
                    }
                    if(cur->right){
                        qu.push(cur->right);
                    }
                }
                else{
                    //even,decrease
                    TreeNode *cur=qu.front();
                    qu.pop();
                    if(cur->val%2==1){
                        return false;
                    }
                    vec.push_back(cur);
                    if(cur->left){
                        qu.push(cur->left);
                    }
                    if(cur->right){
                        qu.push(cur->right);
                    }
                }
            }
            if(floor%2==0){
                for(int i=0;i<vec.size()-1;i++){
                    if(vec[i]->val>=vec[i+1]->val){
                        return false;
                    }
                }
            }
            else{
                for(int i=0;i<vec.size()-1;i++){
                    if(vec[i]->val<=vec[i+1]->val){
                        return false;
                    }
                }
            }
            floor++;
            vec.clear();
        }
        return true;
    }
};