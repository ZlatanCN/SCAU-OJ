/*输入10个整数，输出其中不同的数，即如果一个数出现了多次，只输出一次。

输入格式
输入10个整数

输出格式
依次输出不同的数字（一行一个，从上到下依次输出先出现的数）

输入样例
1 2 1 3 3 2 4 5 5 9

输出样例
1
2
3
4
5
9*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int a[10];
	int i,flag=0,j;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("%d\n",a[0]);
	for(i=1;i<10;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i]!=a[j])
			{
				flag=1;
			}
			else
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			printf("%d\n",a[i]);
		}
	}
}

