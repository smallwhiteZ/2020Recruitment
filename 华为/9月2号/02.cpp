//
// Created by wtZhou on 2020/9/2.
//
// 考到了最基本的深度优先遍历和广度优先遍历，但是我不会编写，还是基础不牢
// 这一题暂时暂停编写

/// 这一题写的慢的原因如下： 1.一开始抗拒深搜和广搜
///                     2.深度编程的熟练度不够，本题想到的广搜，但是熟练度不够，所以卡住了
///                     3.对访问之后的节点再重新设置为0，这一点始终没有考虑到

/// 这一题虽然手动写出来了，但是还是有点心虚

#include <iostream>
#include <string>
using namespace std;

struct queue{
    int i,j;
};

int main(){
    int M,N;
    cin>>M>>N;
    string s[M];
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            char c;
            cin>>c;
            s[i]+=c;
        }
    }
    queue qu[10000];
    int front=0,tail=0;
    int cnt=0;
    void bfs(queue *qum,int &front,int &tail,string s[]);
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(s[i][j]=='S'){
                qu[front].i=i;
                qu[front].j=j;
                //s[i][j]='H';
                front++; /// 进队

                cnt++;

                bfs(qu,front,tail,s);
            }
        }
    }
    cout<<cnt;
    return 0;
}

void bfs(queue *qu,int &front,int &tail,string s[]){
    if(front<=tail){
        return;
    }
    while(front>tail){
        int i=qu[tail].i;
        int j=qu[tail].j;
        tail++;
        int M=s->size();
        int N=s[0].size();
        s[i][j]='H'; /// 这里应该这样
        if(i-1>=0 && s[i-1][j]=='S'){ // 上面
            //s[i-1][j]='H'; // 这里不应该加入进去
            qu[front].i=i-1;
            qu[front].j=j;
            front++;
        }
        if(j-1>=0 && s[i][j-1]=='S'){// 左面
            //s[i][j-1]='H';
            qu[front].i=i;
            qu[front].j=j-1;
            front++;
        }
        if(i+1<M && s[i+1][j]=='S') // 下面
        {
            //s[i+1][j]='H';
            qu[front].i=i+1;
            qu[front].j=j;
            front++;
        }
        if(j+1<N && s[i][j+1]=='S'){ // 右边
            //s[i][j+1]='H';
            qu[front].i=i;
            qu[front].j=j+1;
            front++;
        }
    }
}

/*
//
4 5
SSHHH
SSHHH
HHSHH
HHHSS
 */