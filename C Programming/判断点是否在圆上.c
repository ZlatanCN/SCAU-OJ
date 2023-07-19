#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*由键盘输入一个点的坐标, 要求编程判断这个点是否在单位圆(圆心在坐标0,0)上，点在圆上输出Y, 不在圆上输出N。
使用小数点后3位精度进行判断。

输入样例
0.707,0.707

输出样例
Y*/
main()
{
	double x,y;
	scanf("%lf,%lf",&x,&y);
	if(fabs((x*x+y*y)-1)<=0.001)
	printf("Y");
	else
	printf("N");
}
