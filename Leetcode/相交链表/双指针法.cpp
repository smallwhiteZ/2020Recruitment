//
// Created by wtZhou on 2020/9/15.
//

/// leetcode题解三： 时间O(A+B), 空O(1)
/// 虽然链表A和B的长度不同，但是 A+B和B+A的长度相同，因此各从A和B向后出发，到达各自的终点，再接着从B和A的起点出发，因此最终一点会相遇

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA=headA,*curB=headB;
        while(curA != curB){
            if(curA){
                curA=curA->next;
            }
            else{
                curA=headB;
            }
            if(curB){
                curB=curB->next;
            }
            else{
                curB=headA;
            }
        }
        return curA;
    }
};