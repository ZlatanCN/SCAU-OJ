#include <stdio.h>

int main()
{
	int n,a=1,b;
	n>0&&n<12;
	scanf("%d",&n);
	while(n>1)
	{
		b=n*(n-1);
		a=a*b;
		n=n-2;
	}
	printf("%d",a);
	return 0;
}

