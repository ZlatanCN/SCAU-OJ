/*һ�����100�׵ĸ߶��������£�ÿ����غ����ԭ���߶ȵ�һ�롣���㲢�����n�����ʱ���������˶����ף���n�ε���ĸ߶��Ƕ���?�����ʾ3λС����

�����ʽ
�Ӽ�������һ����n��n>0��

�����ʽ
������������ֱ�Ϊ�������������͵�n�ε���ĸ߶ȣ���һ���ո�ָ�

��������
1

�������
100.000 50.000*/

#include <stdio.h>
#include <math.h>

double m(int n);
double h(int n);
int main()
{
	int n;
	scanf("%d",&n);
	printf("%.3f %.3f",m(n),h(n));
}
double m(int n)
{
	double result;
	if(n==1)
	result=100.000;
	else
	{
		result=m(n-1)+100.0/(pow(2,n-2));
	}
	return result;
}
double h(int n)
{
	double result;
	if(n==1)
	result=50.000;
	else
	{
		result=h(n-1)/2.0;
	}
	return result;
}
