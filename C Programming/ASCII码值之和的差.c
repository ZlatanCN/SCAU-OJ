#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*���������ַ���s1��s2(ÿ����ռһ�У��Ի��лس�������)�����������ַ����������ַ���ASCII��ֵ֮�͵Ĳ

�����ʽ
�����ַ��������ַ�������80���ַ�

�����ʽ
ASCII��ֵ֮�͵Ĳ�

��������
234
123

�������
3*/

int main()
{
	int sum1=0,sum2=0,i;
	char s1[80],s2[80];
	gets(s1);
	for(i=0;s1[i]!='\0';i++)
	{
		sum1+=s1[i];
	}
	//printf("%d",sum1);
	gets(s2);
	for(i=0;s2[i]!='\0';i++)
	{
		sum2+=s2[i];
	}
	printf("%d",sum1-sum2); 
} 


