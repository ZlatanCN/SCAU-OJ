/*�Ӽ�������һ��������int���ͣ�������������Ǽ�λ����*/

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
