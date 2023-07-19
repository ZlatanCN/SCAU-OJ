#include <stdio.h>
#include <math.h>

int main()
{
	int a,b,c,d,e,f;
	d=0;
	scanf("%d",&a);
	e=a%10;
	do
	{
		c=a/10;
		f=c%10;
		b=a%10;
		if(b>=e&&b>=f&&b>=d)
		{
			d=b;
		}
		else if(f>=b&&f>=e&&f>=d)
		{
			d=f;
		}
		else
		{
			d=d;
		}
		a=a/10;
		e=a%10;
	}
	while(a>0);
	printf("%d",d);
	return 0;
}

