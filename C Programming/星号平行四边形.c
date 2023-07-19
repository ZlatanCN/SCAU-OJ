#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*给定正整数n，输出如下边长为n的星号平行四边形。
例如n=3时，输出
*
**
***
 **
  *
例如n=4时，输出
*
**
***
****
 ***
  **
   *
要求星号平行四边形上部不能有多余空行，左边不能有多余空列*/

main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf(" ");
		}
		for(j=i;j<n;j++)
		{
			printf("*");
		}
		printf("\n");
	}
}


