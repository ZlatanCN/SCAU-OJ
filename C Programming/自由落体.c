/*一个球从100米的高度自由落下，每次落地后弹起的原来高度的一半。计算并输出第n次落地时，共经过了多少米，第n次弹起的高度是多少?结果显示3位小数。

输入格式
从键盘输入一个数n（n>0）

输出格式
输出两个数，分别为共经过的米数和第n次弹起的高度，以一个空格分隔

输入样例
1

输出样例
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
