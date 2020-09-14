//
// Created by wtZhou on 2020/7/19.
//
#include <iostream>
#include <math.h>
using namespace std;
/*
int jiou(int x)
{
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x%i == 0)
		{
			return 0;
		}
	}
	return 1;
	}
*/
/*
int work(int n, int *a, int aLen)
{
	int outcome = n;
	for (int i = 1; i < aLen; i++)
	{
		int cha = a[i] - a[i - 1];
		while (cha>1)
		{
			if (jiou(cha))
			{
				break;
			}
			while (cha >= 2)
			{
				cha--;
				if (jiou(cha))
				{
					outcome++;
					break;
				}
			}
		}
	}
	return outcome;
}
*/

void work(int* arr, int aLen)
{
    int i=0, j=aLen-1;
    while(i<=j)
    {
        if(arr[i] < arr[j] && arr[i]<arr[i+1])
        {
            cout<<arr[i];
            i++;
        }
        else if(arr[i] < arr[j] && arr[i] == arr[i+1])
        {
            i++;
        }
        else if(arr[i] > arr[j] && arr[j] < arr[j-1])
        {
            cout<<arr[j];
            j--;
        }
        else if(arr[i] > arr[j] && arr[j] == arr[j-1])
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    cout<<arr[j];
}

int main()
{
    int a[]={1,2,2,5,10,9,8,2,1,1};
    work(a,sizeof(a)/4);
    return 0;
}

