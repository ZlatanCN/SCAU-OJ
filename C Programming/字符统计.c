#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*��дһ��������ͳ��һ���ַ�������ĸ�����ֺͿո�ĸ�����ʹ��ȫ�ֱ��������ĸ�����ָ�������������ֵ�ǿո����

�����ʽ
����һ���ַ�����'\n'������

�����ʽ
ͳ�ƽ��

��������
Ab 45

�������
2 2 1*/

int nL=0, nN=0;

int statistics(char *s)
{
    int sum=0;
    while(*s!='\0')
    {
    	if((*s>='a'&&*s<='z')||(*s>='A'&&*s<='Z'))
   		nL++;
    	if(*s>='0'&&*s<='9')
    	nN++;
    	if(*s==' ')
    	sum++;
    	s++;
	}
	return sum;
}

int main()
{
    char s[81];
    int nS;
    gets(s);
    nS = statistics(s);
    printf("%d %d %d\n", nL, nN, nS);
    return 0;
}

