/*编程实现，由键盘输入n，计算输出数列前n项和。（结果保留四位小数，提示：要使用double，否则精度不够）
    2/1  3/2  5/3  8/5  13/8  21/13

输入样例
20

输出样例
32.6603*/

#include "stdio.h"
#include <math.h>
#include "string.h"

int main()
{
	int n,i;
	double a=2,b=1;
	double result=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		result=result+a/b;
		a=a+b;
		b=a-b;
	}
	printf("%.4f",result);
}
