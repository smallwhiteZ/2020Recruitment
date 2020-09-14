//
// Created by wtZhou on 2020/8/19.
//

#include <iostream>
using namespace std;

int main(){
    int M,N;
    cin>>M>>N;
    //char arr[1001][1001];
    int a[1002001][2];
    int count=0;
    for(int i=0;i<M;i++){
        for(int j=i;j<M-i-1;j++) {
            a[count][0] = i;
            a[count][1] = j;
            count++;
        }
        for(int m=i;m<M-i-1;m++){
            a[count][0]=m;
            a[count][1]=M-i-1;
            count++;
        }
        for(int n=M-i-1;n>i;n--){
            a[count][0]=M-i-1;
            a[count][1]=n;
            count++;
        }
        for(int k=M-i-1;k>i;k--){
            a[count][0]=k;
            a[count][1]=i;
            count++;
        }
    }
//    for(int i=0;i<count;i++){
//        cout<<"["<<a[i][0]<<","<<a[i][1]<<"]";
//    }
    int ans[1001][2]={0};
    int index=0;
    cout<<"[";
    for(int cou=1;cou<=count;cou++){
        //int temp=(cou-1000000*(cou/1000000)-100000*(cou/100000)-10000*(cou/10000)-1000*(cou/1000)-100*(cou/100))/10;
        int temp = (cou/10)%10;
        if(temp%2 && cou%10==7){
            //cout<<"["<<a[cou][0]-1<<","<<a[cou][1]-1<<"]";
            ans[index][0]=a[cou-1][0];
            ans[index][1]=a[cou-1][1];
            index++;
        }

    }
    for(int t=0;t<index;t++){
        cout<<"["<<ans[t][0]<<","<<ans[t][1]<<"]";
        if(t!=index-1){
            cout<<",";
        }
    }
    cout<<"]";
    return 0;
}
//
//总结：
//1. 回形数组用一位数组表示的时候下表要清晰，走了很多弯路
//2. 判断十位数为奇数(有什么更快的计算方式)且个位数为7的