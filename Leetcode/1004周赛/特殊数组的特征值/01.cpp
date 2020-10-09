//
// Created by wtZhou on 2020/10/4.
//

/// 虽然通过了，但是里面的代码逻辑花了很久才全部跑通， 这个一道easy题，不知道为什么花了这么久
#include <vector>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int len=nums.size();
        if(len==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int i=0;
        int tmp=nums[i];
        int pre=-1;
        while(i<len){
            if(tmp==len-i){
                if(tmp!=pre){
                    return tmp;
                }
                else{
                    pre=nums[i];
                    i++;
                    if(i<len) {
                        tmp=nums[i];
                    }
                }
            }
            else if(tmp>len-i){
                if(tmp>pre){
                    tmp--;
                }
                else{
                    pre=nums[i];
                    i++;
                    if(i<len) {
                        tmp=nums[i];
                    }
                }
            }
            else{
                i++;
                pre=tmp;
                if(i<len) {
                    tmp=nums[i];
                }
                //tmp++;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums={3,6,7,7,0};
    Solution solu;
    int ans=solu.specialArray(nums);
    return 0;
}