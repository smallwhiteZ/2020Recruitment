//
// Created by wtZhou on 2020/8/31.
// 在特殊的情况花费比较多的时间
//
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
        if (!l1) {  // 这两种的情况需要单独考虑
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode *curl1 = l1, *curl2 = l2;
        ListNode *precurl1 = curl1, *precurl2 = curl2;
        while (curl1 && curl2) {
            if (curl1->val <= curl2->val) {
                while (curl1 && curl1->val <= curl2->val) { // 这个while循环本意是直接到>的边界，但是貌似没有必要
                    precurl1 = curl1;
                    curl1 = curl1->next;
                }
                if (precurl1) {
                    precurl1->next = curl2;
                }
            } else {
                while (curl2 && curl1->val > curl2->val) {
                    precurl2 = curl2;
                    curl2 = curl2->next;
                }
                if (precurl2) {
                    precurl2->next = curl1;
                }
            }
        }

        if (curl1 && precurl2) { // precurl2为空比较尴尬 {1}{}
            precurl2->next = curl1;
        }

//        注释的代码是为了解决一开始有个链表为空的情况，发现处理起来不方便，因此注释掉，单独在链表一开始的地方就进行判断
//        if(curl1){
//            if(precurl2){
//                precurl2->next=curl1;
//            }
//            else{ // {}{1}
//                //
//            }
//        }
//        else{
//            if(precurl2){
//                return l2;
//            }
//            else{
//                //
//            }
//        }

        if (curl2 && precurl1) { // {}{1}
            precurl1->next = curl2;
        }
        if (l1->val <= l2->val) {
            return l1;
        }
        else{
            return l2;
        }

//        注释的代码是为了解决一开始有个链表为空的情况，发现处理起来不方便，因此注释掉，单独在链表一开始的地方就进行判断
//        if(curl2){
//            if(precurl1){
//                precurl1->next=curl2;
//            }
//            else{
//                //
//            }
//        }
//        else{
//            if(precurl1){
//                return l1;
//            }
//            else{
//                //
//            }
//        }
//        if(l1->val<=l2->val){
//            return l1;
//        }
//        else{
//            return l2;
//        }
//    }

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