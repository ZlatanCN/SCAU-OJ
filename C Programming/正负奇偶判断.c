#include <stdio.h>
#include <stdlib.h>
int main()
{
	int x;
	scanf("%d",&x);
	if(x>0)
	{
		printf("positive\n");
		if((x+1)%2==0)
		{
			printf("odd");
		}
		else
		{
			printf("even");
		}
	}
	if(x<0)
	{
		printf("negative\n");
		if((x*3)%2==0)
		{
			printf("even");
		}
		else
		{
			printf("odd");
		}
	}
}
 

