#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*����һ���ַ�����������80���ַ����Իس����������жϸ��ַ����Ƿ�Ϊ���Ĵ�������������ƴд���������ƴд��һ���ģ����������Y�����������N��

�����ʽ
һ���ַ���

�����ʽ
�������Y�����������N

��������
abba

�������
Y*/

int main()
{
	char s[80];
	int length,i;
	gets(s);
	//printf("%d",strlen(s));
	length=strlen(s)-1;
	for(i=0;i<=length/2;i++)
	{
		if(s[i]!=s[length-i])
		{
			printf("N");
			return 0;
		}
	}
	printf("Y");
} 


