/*����һ���Ի��з��������ַ���ͳ�Ʋ��������Ӣ����ĸ�����֡��ո�������ַ��ĸ�����

�����ʽ
һ���ַ����Ի��з�����

�����ʽ
һ��4�����ֱַ�Ϊ��Ӣ����ĸ�����֡��ո�������ַ��ĸ�����������֮����һ���ո�ָ�

��������
ABC 456!

�������
3 3 1 1*/

#include "stdio.h"
#include <math.h>
#include "string.h"

int main()
{
	int i;
	int word=0,num=0,space=0,other=0;
	char s[80];
	gets(s);
	for(i=0;s[i]!='\0';i++);
	{
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
		{
			word++;
		}
		else if(s[i]>='0'&&s[i]<='9')
		{
			num++;
		}
		if(s[i]==' ')
		{
			space++;
		}
		else
		{
			other++;
		}
	}
	printf("%d %d %d %d",word,num,space,other);
}
