//
// Created by wtZhou on 2020/10/10.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<string> route4,route6;
    route4={"宜山路","虹桥路","延安西路","中山公园","金沙江路","曹杨路","镇坪路","中潭路","上海火车站","宝山路","海伦路","临平路","大连路",
            "杨树浦路","浦东大道","世纪大道","浦电路","蓝村路","塘桥","南浦大桥","西藏南路","鲁班路","大木桥路","东安路","上海体育场",
            "上海体育馆"};
    route6={"航津路","外高桥保税区","洲海路","五洲大道","东靖路","巨峰路","五莲路","博兴路","金桥路","云山路","德平路","北洋泾路","民生路"
            ,"源深体育中心","世纪大道","浦电路","蓝村路","儿童医学中心"};
    string ori,des;
    cin>>ori>>des;
    int len4=route4.size();
    //cout<<len4<<endl;
    int len6=route6.size();
    //cout<<len6<<endl;
    int i=0;
    bool flag_ori=false;
    for(i=0;i<len4;i++){
        if(route4[i]==ori){
            flag_ori=true;
            break;
        }
    }
    int j=0;
    for(j=0;j<len6 && !flag_ori;j++){
        if(route6[j]==ori){
            flag_ori=false;
            i=0;
            break;
        }
    }
    bool flag_des=false;
    if(flag_ori){ /// 起点在4号线
        int k=0;
        for(k=0;k<len4;k++){
            if(route4[k]==des){
                flag_des=true;
                break;
            }
        }
        int m=0;
        for(m=0;m<len6 && !flag_des;m++){
            if(route6[m]==des){
                flag_des=false;
                k=0;
                break;
            }
        }
        if(flag_des){ /// 起终点都在4号线上
            if(abs(i-k)<=len4/2){
                cout<<abs(i-k)+1;
            }
            else{
                cout<<len4-abs(i-k)+1;
            }
        }else{ /// 起点在4号线，终点在6号线上
            if(des!="儿童医学中心"){
                int tmp=abs(15-i);
                if(tmp>len4/2){
                    tmp=len4-tmp;
                }
                cout<<tmp+abs(14-m)+1;
            }
            else{
                int tmp=abs(17-i);
                if(tmp>len4/2){
                    tmp=len4-tmp;
                }
                cout<<tmp+1+1;
            }
        }

    }else{  /// 起点在6号线上
        if(des!="儿童医学中心"){
            int k=0;
            for(k=0;k<len4;k++){
                if(route4[k]==des){
                    flag_des=true;
                    break;
                }
            }
            int m=0;
            for(m=0;m<len6 && !flag_des;m++){
                if(route6[m]==des){
                    flag_des=false;
                    k=0;
                    break;
                }
            }
            if(flag_des){ /// 起点在6号，终点在4号
                if(abs(15-k)<=len4/2){
                    cout<<abs(15-k)+abs(14-j)+1;
                }
                else{
                    cout<<len4-abs(15-k)+abs(14-j)+1;
                }
            }else{ /// 起点在6号线，终点在6号线上
                cout<<abs(j-m)+1;
            }

        }else{
            cout<<abs(len6-1-j)+1;
        }

    }
    return 0;
}
// 博兴路 塘桥 11
// 上海火车站 世纪大道 8
// 上海火车站 中山公园 6
// 源深体育中心 塘桥 5
// 西藏南路 民生路 8
// 儿童医学中心 杨树浦路 6
// 德平路 儿童医学中心 8
// 儿童医学中心 民生路 6
// 大木桥路 儿童医学中心 7

//route4={"宜山路","虹桥路","延安西路","中山公园","金沙江路","曹杨路","镇坪路","中潭路","上海火车站","宝山路","海伦路","临平路","大连路",
//        "杨树浦路","浦东大道","世纪大道","浦电路","蓝村路","塘桥","南浦大桥","西藏南路","鲁班路","大木桥路","东安路","上海体育场",
//        "上海体育馆"};
//route6={"航津路","外高桥保税区","洲海路","五洲大道","东靖路","巨峰路","五莲路","博兴路","金桥路","云山路","德平路","北洋泾路","民生路"
//        ,"源深体育中心","世纪大道","浦电路","蓝村路","儿童医学中心"};