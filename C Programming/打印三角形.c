/*编写程序，输入整数n，输出n行的字符图案。例如n=5时输出：

    *
   **
  ***
 ****
*****
 ****
  ***
   **
    *

输入格式
输入一个整数

输出格式
输出2*n-1行的三角形*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int n,line,i;
	scanf("%d",&n);
	for(line=-(n-1);fabs(line)<n;line++)
	{
		for(i=fabs(line);i>0;i--)
		{
			printf(" ");
		}
		for(i=1;i<=n-fabs(line);i++)
		{
			printf("*");
		}
		printf("\n");
	}
} 
