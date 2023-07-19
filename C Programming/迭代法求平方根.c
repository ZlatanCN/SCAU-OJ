#include <stdio.h>
#include <math.h>

int main()
{
    double a, x0, x1;
    scanf("%lf", &a);
    x0=a/2;
    x1=(x0+a/x0)/2;
    if(a==0)
    {
    	printf("0.0000");
    	return 0;
	}
    while(fabs((x0-x1)>=1E-5))
    {
    	x0=x1;
    	x1=(x0+a/x0)/2;
	}
	printf("%.4f",x1);
}
