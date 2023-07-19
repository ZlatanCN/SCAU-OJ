#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*输入两个字符串s1和s2(每个串占一行，以换行回车符结束)，计算两个字符串的所有字符的ASCII码值之和的差。

输入格式
两行字符，第行字符不超过80个字符

输出格式
ASCII码值之和的差

输入样例
234
123

输出样例
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


