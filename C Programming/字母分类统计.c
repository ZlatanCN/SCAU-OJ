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
	char s[80];
	gets(s);
    int word=0, num=0, space=0, other=0;
    int i;
    for(i=0;s[i]!='\0';i++)
    {
    	if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
    	word++;
    	else if(s[i]>='0'&&s[i]<='9')
    	num++;
    	else if(s[i]==' ')
    	space++;
    	else
    	other++;
	}
    printf("%d %d %d %d\n", word, num, space, other);
    return 0;
}
