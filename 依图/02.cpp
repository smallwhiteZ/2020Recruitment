//
// Created by wtZhou on 2020/8/28.
// 该算法只能过60%，需要优化，但是暂时不知道何从下手
//
#include <iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int arr[100000];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int count=0;
    int yushu=1e8 +7;
    for(int i=0;i<N;i++){
        for(int j=i+2;j<N;j++){
            if(abs(arr[i])<abs(arr[j])){
                for(int k=i+1;k<j;k++){
                    if(abs(arr[k])>abs(arr[i]) && abs(arr[k])>abs(arr[j])){
                        count=(count+1)%yushu;
                    }
                }
            }
        }
    }
    cout<<count;
    return 0;
}