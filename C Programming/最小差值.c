#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*�ɼ�������10������������ȡ����������������ֵ����������Сֵ��������λС����

�����ʽ
10�����������ɿո�ָ�

�����ʽ
��С��ֵ

��������
1.1 2.2 3.3 4.4 5.5 6.6 7.7 8.8 9.9 9

�������
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


