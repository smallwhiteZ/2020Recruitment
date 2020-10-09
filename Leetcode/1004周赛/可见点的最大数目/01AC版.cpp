//
// Created by wtZhou on 2020/10/5.
//
/**
 * 1.迟迟没有AC的原因：
 *  1.1 原点(0,0)的情况需要额外考虑，无法在atan2中表现出来
 *  1.2 有一些逆时针扫描不到的情况，需要进行顺时针扫描的情况，因此需要给pos数组每个元素加上2*PI
 *  1.3 double相等，不能使用==，而是采用 delta < 1e-8来表示
 *  1.4 在比较的时候，不是简单的双重循环，而是需要采用双指针（快慢指针）的方式滑动窗口，不然会TL
 **/

#define PI 3.1415926
#define Eilpson 1e-8
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int l_x=location[0];
        int l_y=location[1];
        vector<double> pos;
        int ans=0;
        for(int i=0;i<points.size();i++){
            points[i][0]-=l_x;
            points[i][1]-=l_y;
            if(points[i][0]==0 && points[i][1]==0){
                ans++;
            }else if(points[i][0]==0 && points[i][1]!=0){ /// 可以直接按照下面注释的方式进行处理
                if(points[i][1]>0){
                    pos.push_back(90*PI/180);
                }
                else if(points[i][1]<0){
                    pos.push_back(270*PI/180);
                }
            }else{
                pos.push_back(atan2(points[i][1],points[i][0]));  /// 弧度值
            }
            // if(points[i][0]==0 && points[i][1]==0){
            //     ans++;
            // }else{
            //     pos.push_back(atan2(points[i][1],points[i][0]));  /// 弧度值
            // }
        }
        double ang=angle*PI/180;
        int tmp=0;
        int ans2=0;
        sort(pos.begin(),pos.end());
        int len=pos.size(); /// 需要先记录一下pos.size
        for(int i=0;i<len;i++){
            pos.push_back(pos[i]+2*PI); /// 这一步巧妙的解决了angle逆时针扫描不到，但是顺时针扫描能够扫描到的情况
        }
        // for(int i=0;i<pos.size();i++){
        ///     tmp=i+1;  /// 这个是超时的原因，这个双指针才是双指针（快慢指针）
        //     while(tmp<pos.size() && (fabs(pos[i]-pos[tmp]-2*PI)<Eilpson || fabs(pos[i]-pos[tmp])<=ang)){
        //         //(fabs(angle[j] - angle[i] - acos(-1.0)*ang/180) < 1e-8 || angle[j] - angle[i] < acos(-1.0)*ang/180)) {
        //             // pos[i]+ang>=pos[tmp]+Eilpson
        //         tmp++;
        //     }
        //     if(tmp-i>ans2){
        //         ans2=tmp-i;
        //     }
        // }
        for(int i=0,tmp=0;i<pos.size();i++){
            //tmp=i+1;
            while(tmp<pos.size() && (fabs(pos[i]-pos[tmp]-2*PI)<Eilpson || fabs(pos[i]-pos[tmp])<=ang)){
                //(fabs(angle[j] - angle[i] - acos(-1.0)*ang/180) < 1e-8 || angle[j] - angle[i] < acos(-1.0)*ang/180)) {
                // pos[i]+ang>=pos[tmp]+Eilpson
                tmp++;
            }
            if(tmp-i>ans2){
                ans2=tmp-i;
            }
        }
        return ans+ans2;
    }
};
