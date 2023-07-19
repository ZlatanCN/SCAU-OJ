/**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void binary(int n)
{
	int a[100];
	int i,j=0;
	for(i=0;n>0;i++)
	{
		a[i]=n%2;
		n=n/2;
		//printf("%d",a[i]);
		j++;
	}
	//printf("%d",j);
	for(i=j-1;i>=0;i--)
	{
		printf("%d",a[i]);
	}
}

main()
{
    int n;
    scanf("%d", &n);
    binary(n);
}
