#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*����һ��3��4�е��������󣬼��㲢������Խ����ϵ�Ԫ��֮��

�����ʽ
3��4����������

�����ʽ
���Խ����ϵ�Ԫ��֮��

��������
1   2   3   4
5   6   7   8
9  10  11  12

�������
18

��ʾ
1��6��11*/

int main()
{
	int a[3][4];
	int i,j,sum;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	sum=a[0][0]+a[1][1]+a[2][2];
	printf("%d",sum);
}

