/*����10���������������ǵ�ƽ��ֵ����ͳ���ж��ٸ�����ƽ��ֵ��

�����ʽ
10������

�����ʽ
��ƽ��ֵ������ĸ���

��������
0 1 2 3 4 5 6 7 8 9

�������
5*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int a[10];
	int i,sum=0,cnt=0;
	double aver;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
		sum=sum+a[i];
	}
	//printf("%d",sum);
	aver=sum/10.0;
	for(i=0;i<10;i++)
	{
		if(a[i]>aver)
		cnt++;
	}
	printf("%d",cnt);
} 
