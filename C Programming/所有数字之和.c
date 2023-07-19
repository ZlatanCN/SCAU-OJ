#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*输入格式
由键盘输入一个整数

输出格式
输出该数各位数字之和

输入样例
123

输出样例
6

提示
1+2+3=6*/

int sum(int n)
{
	int res=0;
	while(n>0)
	{
		res+=n%10;
		n/=10;
	}
	return res;
}

main()
{
    int n;
    scanf("%d", &n);
    printf("%d", sum(n));
}


