//
// Created by wtZhou on 2020/9/24.
//

// 首先这一题没有想到使用空间O（1）的情况来求解，
// 使用了常规的vector存储，hash计数，最后输出，
// 并且调试了很久，购买了LeetCode会员才知道问题出在哪

#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void traversal(TreeNode* root,vector<int> &vec){
        if(root){
            traversal(root->left,vec);
            vec.push_back(root->val);
            traversal(root->right,vec);
        }
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> m;
        vector<int> vec;
        vector<int> ans;
        traversal(root,vec);
        int max=0;
        for(int i=0;i<vec.size();i++){
            m[vec[i]]++;
            if(max<m[vec[i]]){
                max=m[vec[i]];
            }
        }

        // 在这边花了不多时间
        for(int i=0;i<vec.size();i++){  // 只有两项, 因此i<m.size不对的
            if(max==m[vec[i]]){
                if(ans.empty() || vec[i]!=ans[ans.size()-1]) {
                    ans.push_back(vec[i]);
                }
                // ans.push_back(vec[i]);
            }
        }
        return ans;
    }
};

int main(){
    Solution solu;
//    TreeNode *tr2 = new TreeNode(2); tr2->left=NULL;tr2->right=NULL;
//    TreeNode *tr = new TreeNode(2); tr->left=tr2;tr->right=NULL;
//    TreeNode *t=new TreeNode(1); t->left=NULL;t->right=tr;

    TreeNode *tl = new TreeNode(1); tl->left=NULL;tl->right=NULL;
    TreeNode *tr = new TreeNode(2);tr->right=NULL;tr->right=NULL;
    TreeNode *t = new TreeNode(1);t->left=tl;t->right=tr;
    solu.findMode(t);
    return 0;
}