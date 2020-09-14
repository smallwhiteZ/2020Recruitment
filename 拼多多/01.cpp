//
// Created by wtZhou on 2020/9/1.
//

#include <iostream>
using namespace std;
int main(){
    int n=8;
    int arr[200][200]={0};
    if(n%2==0){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i<j && j<n/2){ //...
                    arr[i][j]=2;
                }
                if(j>(n-1)/2 && j<-1*i + n-1){
                    arr[i][j]=1;
                }
                if(i>j && j<=(n-1)/2 && i<=(n-1)/2){
                    arr[i][j]=3;
                }
                if(i>(n-1)/2 && j<(n-1)/2 && j<-1*i + n-1){
                    arr[i][j]=4;
                }
                if(j<=(n-1)/2 && j>(-1*i +n-1)){
                    arr[i][j]=5;
                }
                if(i>j && j>(n-1)/2){
                    arr[i][j]=6;
                }
                if(i<j && i>(n-1)/2){
                    arr[i][j]=7;
                }
                if(i<=(n-1)/2 && j>-1*i +n-1){
                    arr[i][j]=8;
                }
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i<j && j<n/2){ //...
                    arr[i][j]=2;
                }
                if(j>=(n-1)/2 && j<=(-1*i + n-1)){
                    arr[i][j]=1;
                }
                if(i>j && j<=(n-1)/2 && i<=(n-1)/2){// && i<(n-1)/2
                    arr[i][j]=3;
                }
                if(i>=(n-1)/2 && j<=(n-1)/2 && j<=(-1*i + n-1)){
                    arr[i][j]=4;
                }
                if(j<=(n-1)/2 && j>(-1*i +n-1)){  //i>(n-1)/2 && j<(n-1)/2 && j>-1*i +n-1
                    arr[i][j]=5;
                }
                if(i>j && j>=(n-1)/2){
                    arr[i][j]=6;
                }
                if(i<j && i>=(n-1)/2){
                    arr[i][j]=7;
                }
                if(i<=(n-1)/2 && j>(-1*i +n-1)){
                    arr[i][j]=8;
                }
            }
        }
        for(int i=0;i<n;i++){
            arr[i][(n-1)/2]=0;
            arr[(n-1)/2][i]=0;
            arr[i][i]=0;
            arr[i][-1 * i + n - 1]=0;
        }
    }
    // 输出
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j];
            if(j!=n-1){
                cout<<" ";
            }
        }
        if(i!=n-1){
            cout<<endl;
        }
    }
    return 0;
}