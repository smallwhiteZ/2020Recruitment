//
// Created by wtZhou on 2020/9/5.
//
///  主要的问题时体现在vector<queue<int>> 的问题上
///  虽然在内存查看vector<queue<int>> 中无法查看queue的细节，但是并不影响运行的过程，不清楚为啥这样

#include <queue>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    int N,M;
    cin>>N>>M;
    vector<int> price(N,0);   /// 货物的单价
    for(int i=0;i<N;i++){
        cin>>price[i];
    }
    vector<stack<int>> box;
    for(int i=0;i<N;i++){
        box.push_back(stack<int>());
        for(int j=0;j<=100;j++){
            box[i].push(price[i]);
        }
    }
    for(int i=0;i<M;i++){
        int opcnt;
        cin>>opcnt;
        int totalleft=0,totalright=0;
        int totalsumleft=0,totalsumright=0;
        for(int j=0;j<opcnt;j++){
            string op;
            cin>>op;
            if(op.substr(0,3)=="lef"){
                string op2;
                cin>>op2;
                char tmp=op2[0];
                int c;
                switch (tmp) {
                    case 't':  // take
                        cin>>c;
                        totalleft=box[c-1].top();
                        box[c-1].pop();
                        if(j==opcnt-1){
                            totalsumleft+=totalleft;
                            totalleft=0;
                        }
                        break;
                    case 'r': // return
                        cin>>c;
                        box[c-1].push(totalleft);
                        totalleft=0;
                        if(j==opcnt-1){
                            totalsumleft+=totalleft;
                            totalleft=0;
                        }
                        break;
                    case 'k': // keep
                        totalsumleft+=totalleft;
                        totalleft=0;
                        break;
                }
            }
            else if(op.substr(0,3)=="rig"){
                string op2;
                cin>>op2;
                char tmp=op2[0];
                int c;
                switch (tmp) {
                    case 't':  // take
                        cin>>c;
                        totalright=box[c-1].top();
                        box[c-1].pop();
                        if(j==opcnt-1){
                            totalsumright+=totalright;
                            totalright=0;
                        }
                        break;
                    case 'r': // return
                        cin>>c;
                        box[c-1].push(totalright);
                        totalright=0;
                        if(j==opcnt-1){
                            totalsumright+=totalright;
                            totalright=0;
                        }
                        break;
                    case 'k': // keep
                        totalsumright+=totalright;
                        totalright=0;
                        break;
                }
            }
        }
        cout<<totalsumleft+totalsumright;
        if(i != opcnt-1){
            cout<<endl;
        }
    }
    return 0;
}

/*
5 3
1 2 3 4 5
5
left take 1
right take 2
left return 3
right keep
right take 4
6
left take 5
right take 1
left return 2
right return 3
left take 5
left return 4
10
left take 1
left keep
left take 2
left keep
left take 3
left keep
left take 4
left keep
left take 5
left keep
 */