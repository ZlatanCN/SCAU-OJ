#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*�ɼ�������һ���������, Ҫ�����ж�������Ƿ��ڵ�λԲ(Բ��������0,0)�ϣ�����Բ�����Y, ����Բ�����N��
ʹ��С�����3λ���Ƚ����жϡ�

��������
0.707,0.707

�������
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
