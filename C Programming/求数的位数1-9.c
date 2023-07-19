#include "stdio.h"
#include "stdlib.h"
int main()
{
	int a;
	a>0&&a<1000000000;
	scanf("%d",&a);
	if(0<a&&a<10)
	printf("1");
	if(10<a&&a<100)
	printf("2");
	if(100<a&&a<1000)
	printf("3");
	if(1000<a&&a<10000)
	printf("4");
	if(10000<a&&a<100000)
	printf("5");
	if(100000<a&&a<1000000)
	printf("6");
	if(1000000<a&&a<10000000)
	printf("7");
	if(10000000<a&&a<100000000)
	printf("8");
	if(100000000<a&&a<1000000000)
	printf("9");	
}
