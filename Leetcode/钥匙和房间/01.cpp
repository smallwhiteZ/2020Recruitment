//
// Created by wtZhou on 2020/8/31.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int len=rooms.size();
        bool isvisited[1000]={false};
        int count=0;
        int queue[1000];
        int front=0,tail=0;
        if(rooms[0].size()>0){
            isvisited[0]=true;
            for(int i=0;i<rooms[0].size();i++){
                queue[tail++]=rooms[0][i];
            }
            while(front<tail){
                int t=queue[front++];
                if(!isvisited[t]){
                    isvisited[t]=true;
                    count++;
                }
                for(int i=0;i<rooms[t].size();i++){
                    queue[tail++]=rooms[t][i];
                }
            }
        }
        else{
            return false;
        }

        if(count==len){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    vector<vector<int>> rooms;
    //rooms[0]={1};rooms[1]={2};rooms[2]={3};rooms[3]={};
    vector<int> a[4];
    a[0].push_back(1);
    a[1].push_back(2);
    a[2].push_back(3);
    a[3].push_back()
    rooms.push_back(a[0]);
    rooms.push_back(a[1]);
    rooms.push_back(a[2]);
    rooms.push_back()

    Solution solu;
    cout<<solu.canVisitAllRooms(rooms);
    return 0;
}