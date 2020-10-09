//
// Created by wtZhou on 2020/10/5.
//
/// 感触： 首先不会求解，看题解理解了很久才懂。。
/** hard题，难度如下
   1.题意理解时出现困难
   2.看题解后得到计算的方式，需要分成2的幂次方数和非2的幂次方数的分别求解
   3.非2的幂次方数的求解需要另外的递推公式，由2的幂次方数组成
**/


#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    map<int,int> Map;
    int minimumOneBitOperations(int n) {
        Map[0]=0;
        int i=1;
        while(i<=n){
            Map[i]=Map[i/2]*2+1;  /// 这个是由手动推算时得出来的2的幂次方时的规律
            i*=2;
        }
        return helper(n);
    }

    int helper(int n){
        if(Map.count(n)){         /// count是查看map中n存在的个数， find是查看map中n存在的位置
            return Map[n];        /// 2的幂次方数计算的结果容易得到
        }
        int i=1;
        while(i<n){
            i*=2;
        }
        if(i>1) {
            i/=2;
        }
        return helper(i)-helper(n%i); /// 这边是递归， 是递归算出来的，非幂次方数的结果由递归计算得到
    }
};

int main(){
    //int n=6;
    Solution solu;
    for(int i=1;i<=10;i++) {
        cout << solu.minimumOneBitOperations(i)<<endl;
    }
    //cout << solu.minimumOneBitOperations(7)<<endl;
    return 0;
}