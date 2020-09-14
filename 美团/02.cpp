//
// Created by wtZhou on 2020/8/22.
//
#include <algorithm>
#include <iostream>
using namespace std;
//struct A{
//    int index;
//    int value;
//};

class A{
public:
    int index;
    int value;
    A(int i,int va){
        index = i;
        value = va;
    }
};

int compare(const int *p1,const int *p2){
    return *p1 - *p2;
}

//vector<b>;
//void combination(int m,int n,int a) {
//    for(int i=0;i<m;i++){
//        cout<< a[i]<< " ";
//    }
////    if (m == 0) {
////        for (int i = 0; i < b.size(); i++)
////            cout << b[i];
////        return;
////    }
//    for (int i = m; i < n; i++) {
//        if (selected[i] == 1)continue;
//        b.push_back(a[i]);//这次选的是第i个数
//        selected[i] = 1;
//        combination(m - 1, n, i);
//        b.pop_back();
//        selected[i] = 0;
//    }
//}

int fun(int n,int m){
    cin>>n>>m;
    int v[100000];
    int w[100000];
    A a = new A(-1,-1);
    for(int i=0;i<n;i++){
        cin>>v[i];
        cin>>w[i];
        a[i].index=i;
        a[i].value=v[i]+2*w[i];
    }
    qsort(a.,n,4,compare);

//    int minlast = 0, maxlast=0;
//    bool min,max;
//    for(int i=0;i<n;i++){
//        if(a[m-1].value == a[i].value) {
//            minlast = i;
//            break;
//        }
//    }
//    for(int i= minlast+1;i<n;i++) {
//        if (a[m - 1].value != a[i].value) {
//            maxlast = i - 1;
//        }
//    }
//    combination(maxlast-minlast+1,m-minlast, a->value);

    for(int i=0;i<m;i++){
        cout<<a[i].index;
        if(i!=m-1){
            cout<<' ';
        }
    }
    return 0;
}