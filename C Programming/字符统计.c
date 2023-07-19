#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*编写一个函数，统计一个字符串中字母、数字和空格的个数。使用全局变量存放字母和数字个数，函数返回值是空格个数

输入格式
输入一行字符，以'\n'符结束

输出格式
统计结果

输入样例
Ab 45

输出样例
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

