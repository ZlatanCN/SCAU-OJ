#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*���������ַ�����ÿ���Ի��лس�Ϊ����������ÿ�в�����80���ַ���ͳ�Ʋ�������ж��ٸ���д��ĸ��

�����ʽ
�����ַ���

�����ʽ
��д��ĸ����

��������
A-1 123
ABC abc
G

�������
5*/

void daxie(char *s);
int cnt=0;
int main()
{
	char s1[80],s2[80],s3[80];
	gets(s1);gets(s2);gets(s3);
	daxie(s1);daxie(s2);daxie(s3);
	printf("%d",cnt);
}
void daxie(char *s)
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
		cnt++;
	}
} 
