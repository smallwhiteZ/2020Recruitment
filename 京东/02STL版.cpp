//
// Created by wtZhou on 2020/8/28.
// 此次使用STL版的目的是 能够采用 list数据结构 代替繁琐的 链表的 增删改查
//

#include <iostream>
#include <list>
using namespace std;
int main(){
    int m;
    cin>>m;
    list<int> mylist;
    list<int>::iterator f=mylist.begin();
    while(m--){
        int in;
        cin>>in;
        if(in == 1){
            int a,b;
            cin>>a>>b;
            //mylist.insert(it,a,b); // insert参数是在it位置插入a个b，不是在a位置插入b
            list<int>::iterator it = f;
            advance(it,a);
            mylist.insert(it,b);
        }
        else if(in==2){
            int a;
            cin>>a;
            list<int>::iterator first=mylist.begin();
            advance(first,a); // 迭代器 增加，能够指向后面的位置
            mylist.erase(first); // 链表删除元素
        }
        else if(in==3){
            int cou=0;
            for(list<int>::iterator it=mylist.begin();it != mylist.end();it++){ // 遍历
                cout<<*it;
                if(cou++!=mylist.size()){
                    cout<<" ";
                }
            }
        }
        else{}
    }
    return 0;
}