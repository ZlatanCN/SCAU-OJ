#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*读入一行字符串（不多于80个字符，以回车结束），判断该字符串是否为回文串（即从左向右拼写与从右向左拼写是一样的），是则输出Y，不是则输出N。

输入格式
一行字符串

输出格式
是则输出Y，不是则输出N

输入样例
abba

输出样例
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


