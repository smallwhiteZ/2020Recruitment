//
// Created by wtZhou on 2020/9/5.
//
///  主要的问题时体现在vector<queue<int>> 的问题上
///

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
        //price[i]=i;
        cin>>price[i];
    }
    //vector<int> op[N];
//    queue<int> pri[N+1];
//    for(int i=1;i<=N;i++){
//        for(int j=0;j<100;j++){
//            pri[i].push(price[i-1]);
//        }
//    }
    vector<stack<int>> box;
//    for(int i=0;i<N;i++){
//        stack<int> pri;
//        for(int j=0;j<=100;j++){
//            pri.push(price[i]);
//        }
//        box.push_back(pri); /// 问题体现在这里
//    } /// 该box里面存的是queue，里面的首元素不是1，而是一个100个1组成的栈的整体

    for(int i=0;i<N;i++){
        box.push_back(stack<int>());
        for(int j=0;j<=100;j++){
            box[i].push(price[i]);
        }
        //box.push_back(pri); /// 问题体现在这里
    }


//    for(int i=0;i<N;i++){
//        for(int j=0;j<10;j++){
//            cout<<box[i].front();
//            box[i].pop();
//        }
//    }

    //int total=0;
    //vector<int> total;
    for(int i=0;i<M;i++){
        int opcnt;
        cin>>opcnt;
        //vector<int> totalleft;
        //vector<int> totalright;
//        for(int i=0;i<N;i++){ ////
//            stack<int> tmm=box[i];
//            for(int j=0;j<10;j++){
//                cout<<tmm.top();
//                //tmm.pop();
//                //box[i].pop();
//                int tt=tmm.top();
//                tmm.pop();
//                tmm.push(tt);
//            }
//        }
                        cout<<endl;
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
//                cin>>c;
                switch (tmp) {
                    case 't':  // take
                        //c=*(op.end())-'0';
                        cin>>c;
                        //totalleft.push_back(box[c-1].front());
                        totalleft=box[c-1].top();
                        box[c-1].pop();
                        if(j==opcnt-1){
                            totalsumleft+=totalleft;
                            totalleft=0;
                            //totalleft.clear();
                        }
                        break;
                    case 'r': // return
                        //c=*(op.end())-'0';
                        //int shoulide=total.front(); //
                        //total.pop_back();
                        cin>>c;
                        box[c-1].push(totalleft);
                        totalleft=0;
                        if(j==opcnt-1){
                            totalsumleft+=totalleft;
                            totalleft=0;
                            //totalleft.clear();
                        }
                        //totalleft=0;  /// 这里赋值0应该放在上面
                        break;
                    case 'k': // keep
                        totalsumleft+=totalleft;
                        totalleft=0;
                        //totalleft.clear();
//                        for(int i=0;i<N;i++){ ////
//                            for(int j=0;j<10;j++){
//                                cout<<box[i].front();
//                                box[i].pop();
//                            }
//                        }
//                        cout<<endl;
                        break;
                }
            }
            else if(op.substr(0,3)=="rig"){
                string op2;
                cin>>op2;
                char tmp=op2[0];
                int c;
//                cin>>c;
                switch (tmp) {
                    case 't':  // take
                        //c=*(op.end())-'0';
                        cin>>c;
                        totalright=box[c-1].top();
                        box[c-1].pop();
                        if(j==opcnt-1){
                            totalsumright+=totalright;
                            totalright=0;
                        }
                        break;
                    case 'r': // return
                        //c=*(op.end())-'0';
                        //int shoulide=total.front(); //
                        //total.pop_back();
                        cin>>c;
                        box[c-1].push(totalright);
                        //totalright.pop_back();
                        totalright=0;
                        if(j==opcnt-1){
                            totalsumright+=totalright;
                            totalright=0;
                        }
                        //totalright=0;  /// 赋值0应该放在if上面
                        break;
                    case 'k': // keep
                        totalsumright+=totalright;
                        totalright=0;
                        //totalright.clear();
                        break;
                }
            }
        }
        cout<<totalsumleft+totalsumright<<endl;
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