//
// Created by wtZhou on 2020/9/21.
//
#include <iostream>

using namespace std;

//class A{
//public:
//    ~A();
//};
//
//A::~A() {
//    printf("delete A");
//}
//
//class B:
//public A{
//public:~B();
//};
//
//B::~B() {
//    printf("delete B");
//}
//
//int main(){
//    A *pa = new B();
//    delete pa;
//}

int fun(int x){
    int count =0;
    while(x){
        count++;
        x = x & (x-1);
    }
    return count;
}

int  main(){
    cout<<fun(65530);
}