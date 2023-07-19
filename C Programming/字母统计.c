#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*输入三行字符串（每行以换行回车为结束符），每行不超过80个字符。统计并输出其有多少个大写字母。

输入格式
三行字符串

输出格式
大写字母个数

输入样例
A-1 123
ABC abc
G

输出样例
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
