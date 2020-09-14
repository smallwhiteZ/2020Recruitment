//
// Created by wtZhou on 2020/8/21.
//
#include <iostream>
using namespace std;

//int main(){
//    int T;
//    cin>>T;
//    int a[10001];
//    for(int t=0;t<T;t++){
//        int n;
//        cin>>n;
//        for(int i=0;i<n;i++){
//            cin>>a[i];
//        }
//        //求 a【】最小
//        int ans=0;
//        int min=a[0],min_index=0;
//        for(int j=1;j<n;j++){
//            if(min>a[j]) {
//                min = a[j];
//                min_index=j;
//            }
//        }
//        for(int k=0;k<n;k++){
//            if(k!=min_index){
//                ans+=a[k];
//            }
//        }
//        ans+=(n-2)*min;
//        cout<<ans<<endl;
//    }
//    return 0;
//}
// 算法的思路是错的。。。。

int main(){
    int M,N;
    cin>>M>>N;
    int a[15][200]={0};
    int flag[200]={0};  // flag这一步很精妙
    for(int i=0;i < M; i++){
        for(int j=0;j < N; j++){
            cin>>a[i][j];
            if(flag[j] == 0){
                flag[j] = a[i][j];
            }
        }
    }
    for(int i=0;i<M;i++){
        if(flag[i]==0){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}