/*�ɼ�����������n��n<10����Ҫ����������м�����Ϊn������ͼ����

�����ʽ
�����ұ߲�������ո�

��������
4

�������
   1
  121
 12321
1234321
 12321
  121
   1
*/
#include "stdio.h"
#include <math.h>
int main()
{
	int n,i,j,k,row,m;
	scanf("%d",&n);
	for(i=n,row=1;i>0;i--,row++)
	{
		for(j=i-1;j>0;j--)
		printf(" ");
		for(m=1;m<=row;m++)
		{
			printf("%d",m);
		}
		for(m=row-1;m>0;m--)  					
		{
			printf("%d",m);
		}
		printf("\n");
	}
	for(i=1,row=n;i<=n-1;i++,row--)
	{
		for(j=1;j<=i;j++)
		printf(" ");
		for(m=1;m<row;m++)
		{
			printf("%d",m);
		}
		for(m=row-2;m>0;m--)
		{
			printf("%d",m);
		}
		printf("\n");
	}
	
}
