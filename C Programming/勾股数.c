/*若三个正整数a、b、c，其中a<=b<=c，满足a^2+b^2=c^2，其中^表示上标，称这三个数为“勾股数”，例如：3、4、5是勾股数。编程输出不大于n的所有勾股数。

输入格式
输入一个数(n<=100)

输出格式
输出所有勾股数，按第1个数字由小到大排列（若第1个数字相同，按第2个数字排）

输入样例
16

输出样例
3 4 5
5 12 13
6 8 10
9 12 15*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int n,a,b,c;
	scanf("%d",&n);
	for(a=1;a<=n;a++)
	{
		for(b=a+1;b<=n;b++)
		{
			for(c=a+2;c<=n;c++)
			{
				if(a*a+b*b==c*c)
				{
					printf("%d %d %d\n",a,b,c);
				}
			}
		}
	}
} 
