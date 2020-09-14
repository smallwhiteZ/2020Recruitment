//
// Created by wtZhou on 2020/8/31.
//

// 归并排序递归实现

#include <iostream>
using namespace std;

struct ListNode {
 	int val;
 	struct ListNode *next;
};


class Solution {
public:
    /**
     *
     * @param l1 ListNode类
     * @param l2 ListNode类
     * @return ListNode类
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // write code here
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode *HEAD;
        if(l1->val<=l2->val){
            //return mergeTwoLists(l1->next,l2); // 不是这么编程的。。。
            HEAD=l1;
            HEAD->next=mergeTwoLists(l1->next,l2);
        }
        else{
            //return mergeTwoLists(l1,l2->next);
            HEAD=l2;
            HEAD->next=mergeTwoLists(l1,l2->next);
        }
        return HEAD; // 不懂如何编程递归程序
    }
};

int main(){
    ListNode *l1=new ListNode();
    l1->next=NULL,l1->val=1;

    //ListNode *l2=NULL;
    ListNode *l2=new ListNode();
    l2->next=NULL,l2->val=1;

    Solution solu;
    ListNode *l3=solu.mergeTwoLists(l1,l2);
    while(l3){
        cout<<l3->val<<" ";
        l3=l3->next;
    }
    return 0;
}