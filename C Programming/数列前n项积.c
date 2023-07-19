#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
有如下规律的数列，请编程求该数列的前N项积，要求计算过程达到double精度要求，
    1/5  4/11  7/17  10/23  13/29
最终结果采用“%.10lf”显示10位小数.

输入格式
一个正整数N(N<=20)

输出格式
前N项积，显示10位小数

输入样例
2

输出样例
0.0727272727*/

int main() 
{
	double pdt=1,an,i,n;
	scanf("%lf",&n);
	for(n=n;n>0;n--)
	{
		an=((3*n)-2)/((6*n)-1);
		pdt=pdt*an;
		//printf("%.10f\n",an);
	}
	printf("%.10f\n",pdt);
} 
