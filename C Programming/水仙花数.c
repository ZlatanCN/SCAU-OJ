#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*ˮ�ɻ�����ָһ�� 3 λ��������ÿ��λ�ϵ����ֵ� 3����֮�͵������������磺1^3 + 5^3+ 3^3 = 153*/

int main()
{
	int n,a,b,c;
	for(n=100;n<1000;n++)
	{
		a=n/100;
		b=n/10%10;
		c=n%10;
		if(a*a*a+b*b*b+c*c*c==n)
		printf("%d\n",n);
	}
} 
