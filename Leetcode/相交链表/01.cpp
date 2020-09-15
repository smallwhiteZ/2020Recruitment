//
// Created by wtZhou on 2020/9/15.
//
/// 学习了unordered_map的用法，
/// unordered_map<***，***> 必须是两个，有键值的意思key-value
/// 寻找某个键的函数是 .find(键值)

#include <unordered_map>
using namespace std;

//Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> um;
        ListNode* cur=headA;
        while(cur){
            um[cur]=1;
            cur=cur->next;
        }
        ListNode* curB=headB;
        while(curB){
            if(um.find(curB)!= um.end()){
                return curB;
            }
            curB=curB->next;
        }
        return NULL;
    }
};