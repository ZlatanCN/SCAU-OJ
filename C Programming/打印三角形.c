/*��д������������n�����n�е��ַ�ͼ��������n=5ʱ�����

    *
   **
  ***
 ****
*****
 ****
  ***
   **
    *

�����ʽ
����һ������

�����ʽ
���2*n-1�е�������*/

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
