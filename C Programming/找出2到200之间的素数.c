#include <stdio.h>

int main()
{
	int a=1,b=1;
	printf("2\n");
	for(a=3;a<=200;a++)
	{
		for(b=2;b<=a;b++)
		{
			if(a%b==0)
			break;
		}
		if(a==b)
		{
			printf("%d\n",a);
		}
	}
	return 0;
}
