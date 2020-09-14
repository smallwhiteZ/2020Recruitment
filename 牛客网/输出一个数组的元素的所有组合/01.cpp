//
// Created by wtZhou on 2020/8/30.
//
// 做这一题的目的是因为知道这是一道经典的回溯问题，并且而是可以采用深度优先遍历来实现，
// 鉴于对于这一块的内容不熟悉，特地来复习实现一下

#include <iostream>
using namespace std;

void swap(int *a,int *b){
    //int temp=0;
    int temp=*a;
    *a=*b;
    *b=temp;
}

// 递归的程序如何编程出来？
void fun(int a[],int len,int index){
    if(index==len){
        for(int i=0;i<len;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    for(int i=index;i<len;i++){ // 不会编这个啊。。。。
        swap(&a[i],&a[index]);
        fun(a,len,index+1); // 回溯的方式理解起来好难。。。
        swap(&a[i],&a[index]);
    }
}

int main(){
    int a[5]={1,2,3,4,5};
    fun(a,5,0);
    return 0;
}



