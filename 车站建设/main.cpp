#include <iostream>
#include <math.h>
using namespace std;

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