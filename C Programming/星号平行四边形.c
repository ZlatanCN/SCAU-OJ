#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*����������n��������±߳�Ϊn���Ǻ�ƽ���ı��Ρ�
����n=3ʱ�����
*
**
***
 **
  *
����n=4ʱ�����
*
**
***
****
 ***
  **
   *
Ҫ���Ǻ�ƽ���ı����ϲ������ж�����У���߲����ж������*/

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


