#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*����10��������������в�ͬ�����������һ���������˶�Σ�ֻ���һ�Ρ�

�����ʽ
����10������

�����ʽ
���������ͬ�����֣�һ��һ�������ϵ�����������ȳ��ֵ�����

��������
1 2 1 3 3 2 4 5 5 9

�������
1
2
3
4
5
9*/

int main()
{
	int a[10],i,j,flag;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("%d\n",a[0]);
	for(i=1;i<10;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i]!=a[j])
			{
				flag=1;
			}
			if(a[j]==a[i])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			printf("%d\n",a[i]);
		}
	} 
}

