//
// Created by wtZhou on 2020/9/3.
//
/// 结构体根据某个属性来排序是通过compare的重写来实现的

#include <iostream>
#include <algorithm>
using namespace std;

struct stu{
    int cnt;
    int col;
    int index;
};

int comp(const void *a, const void *b){
    return ((stu *)b)->cnt - ((stu *)a)->cnt;
}

int main(){
    int N;
    cin>>N;
    stu st[N];
    for(int i=0;i<N;i++){
        int cnt,col;
        cin>>cnt>>col;
        st[i].index=i+1;
        st[i].cnt=cnt;
        st[i].col=col;
    }
    mergesort(st,N,sizeof(stu),comp);
    stu red[3];
    stu blue[3];
    int redcnt=0,bluecnt=0;
    for(int i=0;i<N && (redcnt<3 || bluecnt<3);i++){
        if(st[i].col==1){
            red[redcnt++]=st[i];
        }
        if(st[i].col==2){
            blue[bluecnt++]=st[i];
        }
    }
    if(redcnt<3){
        if(bluecnt>=3){
            int anscnt=0;
            for(int i=0;i<3;i++){
                anscnt += blue[i].cnt;
            }
            //cout<<blue[2].index<<
            int min=blue[0].index > (blue[1].index>blue[2].index ? blue[2].index : blue[1].index) ?
                    (blue[1].index>blue[2].index ? blue[2].index : blue[1].index): blue[0].index;
            int max=blue[0].index < (blue[1].index<blue[2].index ? blue[2].index : blue[1].index) ?
                    (blue[1].index<blue[2].index ? blue[2].index : blue[1].index): blue[0].index;
            int mid;
            for(int i=0;i<3;i++){
                if(blue[i].index != min && blue[i].index!=max){
                    mid = blue[i].index;
                }
            }
            cout<<min<<" "<<mid<<" "<<max<<endl;
            cout<<2<<endl;
            cout<<anscnt;
            return 0;
        }
        else{
            cout<<"null";return 0;
        }
    }
    if(bluecnt<3){
        if(redcnt>=3){
            int anscnt=0;
            for(int i=0;i<3;i++){
                anscnt += red[i].cnt;
            }
            //cout<<blue[2].index<<
            int min=red[0].index > (red[1].index>red[2].index ? red[2].index : red[1].index) ?
                    (red[1].index>red[2].index ? red[2].index : red[1].index): red[0].index;
            int max=red[0].index < (red[1].index<red[2].index ? red[2].index : red[1].index) ?
                    (red[1].index<red[2].index ? red[2].index : red[1].index): red[0].index;
            int mid;
            for(int i=0;i<3;i++){
                if(red[i].index != min && red[i].index!=max){
                    mid = red[i].index;
                }
            }
            cout<<min<<" "<<mid<<" "<<max<<endl;
            cout<<1<<endl;
            cout<<anscnt;return 0;
        }
        else{
            cout<<"null";return 0;
        }
    }
    int ansred=0,ansblue=0;
    for(int i=0;i<3;i++){
        ansred+=red[i].cnt;
        ansblue+=blue[i].cnt;
    }
    if(ansblue>ansred){
        int min=blue[0].index > (blue[1].index>blue[2].index ? blue[2].index : blue[1].index) ?
                (blue[1].index>blue[2].index ? blue[2].index : blue[1].index): blue[0].index;
        int max=blue[0].index < (blue[1].index<blue[2].index ? blue[2].index : blue[1].index) ?
                (blue[1].index<blue[2].index ? blue[2].index : blue[1].index): blue[0].index;
        int mid;
        for(int i=0;i<3;i++){
            if(blue[i].index != min && blue[i].index!=max){
                mid = blue[i].index;
            }
        }
        cout<<min<<" "<<mid<<" "<<max<<endl;
        cout<<2<<endl;
        cout<<ansblue;
    }
    else if(ansblue<ansred){
        int min=red[0].index > (red[1].index>red[2].index ? red[2].index : red[1].index) ?
                (red[1].index>red[2].index ? red[2].index : red[1].index): red[0].index;
        int max=red[0].index < (red[1].index<red[2].index ? red[2].index : red[1].index) ?
                (red[1].index<red[2].index ? red[2].index : red[1].index): red[0].index;
        int mid;
        for(int i=0;i<3;i++){
            if(red[i].index != min && red[i].index!=max){
                mid = red[i].index;
            }
        }
        cout<<min<<" "<<mid<<" "<<max<<endl;
        cout<<1<<endl;
        cout<<ansblue;
    }
    else{
        int minred = red[0].index > (red[1].index>red[2].index ? red[2].index : red[1].index) ?
                     (red[1].index>red[2].index ? red[2].index : red[1].index): red[0].index;
        int minblue= blue[0].index > (blue[1].index>blue[2].index ? blue[2].index : blue[1].index) ?
                    (blue[1].index>blue[2].index ? blue[2].index : blue[1].index): blue[0].index;
        if(minred<minblue){
            int min=red[0].index > (red[1].index>red[2].index ? red[2].index : red[1].index) ?
                    (red[1].index>red[2].index ? red[2].index : red[1].index): red[0].index;
            int max=red[0].index < (red[1].index<red[2].index ? red[2].index : red[1].index) ?
                    (red[1].index<red[2].index ? red[2].index : red[1].index): red[0].index;
            int mid;
            for(int i=0;i<3;i++){
                if(red[i].index != min && red[i].index!=max){
                    mid = red[i].index;
                }
            }
            cout<<min<<" "<<mid<<" "<<max<<endl;
            cout<<1<<endl;
            cout<<ansblue;
        }
        else{
            int min=blue[0].index > (blue[1].index>blue[2].index ? blue[2].index : blue[1].index) ?
                    (blue[1].index>blue[2].index ? blue[2].index : blue[1].index): blue[0].index;
            int max=blue[0].index < (blue[1].index<blue[2].index ? blue[2].index : blue[1].index) ?
                    (blue[1].index<blue[2].index ? blue[2].index : blue[1].index): blue[0].index;
            int mid;
            for(int i=0;i<3;i++){
                if(blue[i].index != min && blue[i].index!=max){
                    mid = blue[i].index;
                }
            }
            cout<<min<<" "<<mid<<" "<<max<<endl;
            cout<<2<<endl;
            cout<<ansblue;
        }
    }
    return 0;
}