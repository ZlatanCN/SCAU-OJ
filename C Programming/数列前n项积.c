#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
�����¹��ɵ����У�����������е�ǰN�����Ҫ�������̴ﵽdouble����Ҫ��
    1/5  4/11  7/17  10/23  13/29
���ս�����á�%.10lf����ʾ10λС��.

�����ʽ
һ��������N(N<=20)

�����ʽ
ǰN�������ʾ10λС��

��������
2

�������
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
