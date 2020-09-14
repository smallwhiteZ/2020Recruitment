//
// Created by wtZhou on 2020/9/2.
//
// 常规模拟题，没有涉及到算法
//
// 问题总结:
// 1.一开始出在不会对结构体进行排序，然后使用二维数组进行排序，排序之后记录索引的过程很麻烦
// 在学习到如何对结构体进行排序之后，很多问题都可以迎刃而解

// 2.在进行结构体排序的过程中，无法使用到自带的函数，因此需要手动编写，因此对八大排序的编写是否掌握，有待练习
/// 修正2的观点，可以使用自带的函数，但是在compare参数这一块，需要采用结构体的指定的变量进行修改

#include <iostream>
using namespace std;
struct stu{
    int cnt;
    int col;
    int index;
};

//int comp(const void*a,const void*b)
//{
//    return *(int*)b-*(int*)a;
//}

void bubbleSort(stu st[],int len) {
    for (int i = len-1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if (st[i].cnt > st[j].cnt) { // 在冒泡排序这边卡了一会
                stu tmp = st[i];
                st[i] = st[j];
                st[j] = tmp;
            }
        }
    }
}

int main(){
    int N;
    cin>>N;
    //int red[1024];
    //int blue[1024];
    //int indexred[1024]={0};
    //int indexblue[1024]={0};
    //int cntred=0;
    //int cntblue=0;

    stu st[1024];
    for(int i=0;i<N;i++){
        int cnt,col;
        cin>>cnt>>col;
        st[i].cnt=cnt;
        st[i].col=col;
        st[i].index=i+1;
//        st[]
//        //index[i]=i;
//        if(col==1){
//            red[cntred]=cnt;
//            //indexred[cnt]=i;
//            cntred++;
//        }
//        if(col==2){
//            blue[cntblue]=cnt;
//            //indexblue[cnt]=i;
//            cntblue++;
//        }
    }

    //mergesort(st,0,cntred,comp); // 这边是结构体的排序，因此无法直接使用内置的函数
    //mergesort(blue,0,cntblue,comp);

    bubbleSort(st,N);

    //int rl=0,rr=0;
    //int bl=0,br=0;

    int red[3],blue[3];
    int cntred=0,cntblue=0;
    for(int i=0;i<N && (cntred<3 || cntblue<3);i++){
        if(st[i].col==1){
            red[cntred++]=i;
        }
        else if(st[i].col==2){
            blue[cntblue++]=i;
        }
    }
    if(cntblue<3){
        if(cntred>=3){
            // 输出
            int anscnt=0;
            for(int i=0;i<3;i++){
                anscnt+=st[red[i]].cnt;
            }
            cout<<st[red[2]].index<<" "<<st[red[1]].index<<" "<<st[red[0]].index;
            cout<<endl;
            cout<<1<<endl;
            cout<<anscnt;
            return 0;
        }
        else{
            cout<<"null";
            return 0;
        }
    }
    if(cntred<3){
        if(cntblue>=3){
            // shuchu
            int anscnt=0;
            for(int i=0;i<3;i++){
                anscnt+=st[blue[i]].cnt;
            }
            cout<<st[blue[2]].index<<" "<<st[blue[1]].index<<" "<<st[blue[0]].index;
            cout<<endl;
            cout<<2<<endl;
            cout<<anscnt;
            return 0;
        }
        else{
            cout<<"null";
            return 0;
        }
    }
    int ansred=0,ansblue=0;
    for(int i=0;i<3;i++){
        ansred+=st[red[i]].cnt;
        ansblue+=st[blue[i]].cnt;
    }
    if(ansblue<ansred){
        for(int i=0;i<3;i++){
            cout<<st[red[2-i]].index;
            if(i!=2){
                cout<<' ';
            }
        }
        cout<<endl;
        cout<<1<<endl;
        cout<<ansred;
        return 0;
    }
    else if(ansblue>ansred){
        for(int i=0;i<3;i++){
            cout<<st[blue[2-i]].index;
            if(i!=2){
                cout<<' ';
            }
        }
        cout<<endl;
        cout<<2<<endl;
        cout<<ansblue;
        return 0;
    }
    else{
        if(st[red[2]].index>st[blue[2]].index){
            for(int i=0;i<3;i++){
                cout<<st[blue[i]].index; /// 在输出学生的编号这一块还有问题，在01结构体排序这块有讲到如何修改
                if(i!=2){
                    cout<<' ';
                }
            }
            cout<<endl;
            cout<<2<<endl;
            cout<<ansblue;
            return 0;
        }
        else{
            for(int i=0;i<3;i++){
                cout<<st[red[i]].index;
                if(i!=2){
                    cout<<' ';
                }
            }
            cout<<endl;
            cout<<1<<endl;
            cout<<ansred;
            return 0;
        }
    }
}