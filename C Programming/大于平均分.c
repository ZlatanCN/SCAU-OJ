/*输入10个整数，计算它们的平均值，并统计有多少个数比平均值大。

输入格式
10个整数

输出格式
比平均值大的数的个数

输入样例
0 1 2 3 4 5 6 7 8 9

输出样例
5*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int a[10];
	int i,sum=0,cnt=0;
	double aver;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
		sum=sum+a[i];
	}
	//printf("%d",sum);
	aver=sum/10.0;
	for(i=0;i<10;i++)
	{
		if(a[i]>aver)
		cnt++;
	}
	printf("%d",cnt);
} 
