#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*由键盘输入10个浮点数，任取其中两数相减求绝对值，求其中最小值（保留两位小数）

输入格式
10个浮点数，由空格分隔

输出格式
最小差值

输入样例
1.1 2.2 3.3 4.4 5.5 6.6 7.7 8.8 9.9 9

输出样例
0.20*/

int main()
{
	double a[10],min;
	int i,j;
	for(i=0;i<10;i++)
	{
		scanf("%lf",&a[i]);
	}
	min=fabs(a[0]-a[1]);
	for(i=0;i<10;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(fabs(a[i]-a[j])<min)
			{
				min=fabs(a[i]-a[j]);
			}
		}
	}
	printf("%.2f",min);
} 


