#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*�����ʽ
�ɼ�������һ������

�����ʽ
���������λ����֮��

��������
123

�������
6

��ʾ
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


