//
// Created by wtZhou on 2020/8/27.
//

#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct Node{
    int val;
    Node *next=NULL;
}LinkNode;

int main(){
    int m;
    int op;
    LinkNode *f = new(LinkNode);
    LinkNode *first=f;
    LinkNode *cur= first->next;
    for(int i=0;i<m;i++){
        cin>>op;
        if(op == 1){
            int in1,in2;
            cin>>in1>>in2;
            int cou=in1;
            cur = first->next;
            while(cou>=1){
                if(cur){
                    LinkNode *t = new(LinkNode);
                    t->val=in2;
                    cur->next=t;
                }
                else{
                    LinkNode *t = new(LinkNode) ;
                    t->val=in2;
                    first->next=t;
                }
                cou--;
            }
        }
        if(op==2){
            int in1;
            cin>>in1;
            cur = first->next;
            LinkNode *pret = cur;
            while(in1){
                pret = cur;
                cur = cur->next;
                in1--;
            }
            LinkNode *p= cur->next;
            if(p){
                pret->next=p;
                //free(cur);
                delete cur;
            }
            else{
                pret->next=NULL;
                //free(cur);
                delete cur;
            }
        }
        if(op==3){
            cur = first->next;
            while(cur){
                cout<<cur->val;
                cur = cur->next;
                if(cur){
                    cout<<" ";
                }
            }
        }
    }
    return 0;
}
