/*���ʵ�֣��ɼ�������n�������������ǰn��͡������������λС������ʾ��Ҫʹ��double�����򾫶Ȳ�����
    2/1  3/2  5/3  8/5  13/8  21/13

��������
20

�������
32.6603*/

#include "stdio.h"
#include <math.h>
#include "string.h"

int main()
{
	int n,i;
	double a=2,b=1;
	double result=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		result=result+a/b;
		a=a+b;
		b=a-b;
	}
	printf("%.4f",result);
}
