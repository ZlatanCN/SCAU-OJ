/*
1  1/2  2/3  3/5  5/8  8/13  13/21
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int n,i;
	double result=0,a=1,b=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		result=result+a/b;
		b=a+b;
		a=b-a;
	}
	printf("%.4f",result);
} 
