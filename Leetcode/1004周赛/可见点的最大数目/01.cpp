//
// Created by wtZhou on 2020/10/4.
//

#include <cmath>
#include <iostream>
using namespace std;

#define PI 3.1415926
#define Eilpson 1e-6
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int l_x=location[0];
        int l_y=location[1];
        vector<double> pos;
        for(int i=0;i<points.size();i++){
            points[i][0]-=l_x;
            points[i][1]-=l_y;
            pos.push_back(atan2(points[i][1],points[i][0]));  /// 弧度值 , 没有考虑到在原点的情况，需要额外考虑
        }
        double ang=angle*PI/180;
        int ans=0;
        int tmp=0;
        sort(pos.begin(),pos.end());
        for(int i=0;i<pos.size();i++){
            tmp=i+1; /// 这个是双重循环，但是不是快慢指针的意思，因为会出现超时的情况
            while(tmp<pos.size() && pos[i]+ang>=pos[tmp]){ ///
                tmp++;
            }
            if(tmp-i>ans){
                ans=tmp-i;
            }
        }
        return ans;
    }
};
