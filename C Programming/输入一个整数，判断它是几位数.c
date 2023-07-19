/*从键盘输入一个整数（int类型），输出该整数是几位数。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int x,cnt=0;
	scanf("%d",&x);
	while(x!=0)
	{
		x/=10;
		cnt++;
	}
	printf("%d",cnt);
} 
