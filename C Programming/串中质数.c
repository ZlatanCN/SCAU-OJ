#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*输入一行由数字字符（不含字符'0'）构成的字符串（最长不超过80字符，以回车结束），从字符串中任意的选取连续的
两个或三个数字字符，构成的数字如果是质数则称为找到一个“串中质数”，请编程计算在给定的字符串中
最多能找到多少个不同的“串中质数”

注：两个“串中质数”，只要它们中有一个字符不同或位置不同，就算不同的两个“串中质数”，例如
2131中有三个串中质数，分别为“13”、“31”和“131”

输入格式
一行字符串（如题目描述）

输出格式
不同的“串中质数”的数量

输入样例
2131

输出样例
3*/

main()
{
	char s[80];
	int a[80],flag,i,cnt=0;
	gets(s);
	for(i=0;s[i+2]!='\0';i++)
	{
		int n=2;
		a[i]=s[i]-'0';
		a[i+1]=s[i+1]-'0';
		a[i+2]=s[i+2]-'0';
		//printf("%d\n",a[i]*100+a[i+1]*10+a[i+2]);
		for(n=2;n<(a[i]*100+a[i+1]*10+a[i+2]);n++)
		{
			if((a[i]*100+a[i+1]*10+a[i+2])%n==0)
			{
				flag=0;
				break;
			}
			else
			flag=1;
		}
		if(flag==1)
		{
			//printf("%d\n",a[i]*100+a[i+1]*10+a[i+2]);
			cnt++;
		}
	}
	for(i=0;s[i+1]!='\0';i++)
	{
		int n=2;
		a[i]=s[i]-'0';
		a[i+1]=s[i+1]-'0';
		for(n=2;n<(a[i]*10+a[i+1]);n++)
		{
			if((a[i]*10+a[i+1])%n==0)
			{
				flag=0;
				break;
			}
			else
			flag=1;
		}
		if(flag==1)
		{
			cnt++;
		}
	}
	printf("%d",cnt);
}


