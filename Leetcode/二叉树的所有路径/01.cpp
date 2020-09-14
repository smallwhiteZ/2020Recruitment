//
// Created by wtZhou on 2020/9/4.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//vector<string> ans;
//string tmp;
//
//vector<string> binaryTreePaths(TreeNode* root,string &tmp) {
//    if(root==NULL){
//        return ans;
//    }
//    if(root->left==NULL && root->right==NULL){
//        ans.push_back(tmp);
//        //tmp.clear();
//        tmp.pop_back();
//        return ans;
//    }
//    else{
//        tmp.push_back((char)(root->val));
//        tmp.push_back(binaryTreePaths(root->left,tmp));
//        tmp.push_back(binaryTreePaths(root->right,tmp));
//    }
//}

void constructTreePaths(TreeNode* root, string tmp, vector<string> &ans){  // 这里的参数不是string &tmp
    if(root){
        tmp += to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(tmp);
        }
        else{
            tmp+="->";
            constructTreePaths(root->left,tmp,ans);
            constructTreePaths(root->right,tmp,ans);
        }
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    constructTreePaths(root,"",ans);
    return ans;
}

int main(){

}