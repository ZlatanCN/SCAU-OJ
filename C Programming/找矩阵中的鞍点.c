/*由键盘输入一个3＊4（3行4列）的数字矩阵，其中任意两个数字均不相同。要求输出该数字矩阵中的鞍点（即在矩阵行中最大，列中最小的数）。
若没有鞍点，输出“NO”字样。



输入样例
87  90  110  98
70  97  210  65
99  45  91   30


输出样例
110*/

#include "stdio.h"

int main()
{
	int a[3][4];
	int i,j;
	int n=1;
	int bot;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			if(a[i][j]>=a[i][0]&&a[i][j]>=a[i][1]&&a[i][j]>=a[i][2]&&a[i][j]>=a[i][3]&&a[i][j]<=a[0][j]&&a[i][j]<=a[1][j]&&a[i][j]<=a[2][j])
			{
				bot=a[i][j];
				n=0;
				printf("%d",bot);
				break;
			}		
		}
	}
	if(n==1)
	{
		printf("NO");
	}
	return 0;
}


