#include <iostream>
#include "math.h"
using namespace std;

int zhishu(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int work(int n,int* a,int alen)
{
    int outcome= n;
    for(int i=0;i<alen-1;i++)
    {
        int temp=a[i+1]-a[i];
        if(temp==1 || zhishu(temp))
        {
            continue;
        }
        else if(temp%2==0)
        {
            outcome++;
        }
        else
        {
            if(zhishu(temp-2))
            {
                outcome++;
            }
            else
            {
                outcome=outcome+2;
            }
        }
    }
    return outcome;
}

int main()
{
    int a[3]={0,7,11};
    int outcome=work(3,a,3);
    cout<<outcome;
    return 0;
}