//
// Created by wtZhou on 2020/9/5.
//

/// 处理 数组下标从0开始 和 数学递推式 的问题
/// 下面代码存在问题

#include <iostream>
using namespace std;

int fun(int a[],int len){
    //double El=0,Er=0;
    //double Dl=0,Dr=0;
    double El[10],Er[10];
    double Dl[10],Dr[10];
    El[0]=a[0],Er[0]=a[0];
    Dl[0]=0,Dr[0]=0;
    double min=100000;
    int minindex=0;
    for(int i=0;i<len-1;i++){
        El[0]=a[0],Dl[0]=0;
        for(int j=1;j<=i;j++){
            El[j]=El[j-1]+(a[j]-El[j-1])/(j+1); // 还是下标的问题
            Dl[j]=Dl[j-1]+(a[j]-El[j-1])*(a[j]-El[j]);
        }
//        Er[i]=a[i],Dr[i]=0;
//        for(int k=i+1;k<len;k++){  /// 做了修改
//            Er[k]=Er[k-1]+(a[k]-Er[k-1])/k;
//            Dr[k]=Dr[k-1]+(a[k]-Er[k-1])*(a[k]-Er[k]);
//        }
        Er[0]=a[i+1],Dr[0]=0;
        for(int k=0;k<len-1-i;i++){
            Er[k]=Er[k-1]+(a[i+1+k]-Er[k-1])/k;
            Dr[k]=Dr[k-1]+(a[i+k+1]-Er[k-1])*(a[i+1+k]-Er[k]);
        }
        if(min>(Dl[i]+Dr[len-2-i])){
            minindex=i+1;
        }
    }
    return minindex;
}

int main(){
    int a[6]={1,1,1,3,3,3};
    cout<<fun(a,6)<<endl;
    return 0;
}