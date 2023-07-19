#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*水仙花数是指一个 3 位数，它的每个位上的数字的 3次幂之和等于它本身。例如：1^3 + 5^3+ 3^3 = 153*/

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
