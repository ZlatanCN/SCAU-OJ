#include "stdio.h"

int binary(int n);
main()
{
    int n;
    scanf("%d", &n);
    binary(n);
}
int binary(int n)
{
	if(n>0)
	{
		binary(n/2);
		printf("%d",n%2);
	}	
} 
