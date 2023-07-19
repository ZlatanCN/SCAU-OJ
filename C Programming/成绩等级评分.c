/*输入一行以换行符结束的字符，统计并输出其中英文字母、数字、空格和其它字符的个数。

输入格式
一行字符，以换行符结束

输出格式
一行4个数字分别为：英文字母、数字、空格和其它字符的个数，两数据之间以一个空格分隔

输入样例
ABC 456!

输出样例
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
