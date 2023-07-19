#include "stdio.h"
#include <math.h>
#include "string.h"

int main()
{
	int i,cnt=0,num=0,cnt1=0,cnt2=0,num1;
	char s[80];
	gets(s);
	for(i=strlen(s)-1;s[i]!='.';i--)
	{
		if(s[i]=='0')
		{
			num++;
		}
		cnt++;
	}
	if(cnt==num)
	{
		printf("0");
		return 0;
	}
	for(i=strlen(s)-1;s[i]!='.';i--)
	{
		if(s[i]!='0')
		{
			num1=i;
			break;
		}
	}
	while(s[num1]!='.')
	{
		cnt1++;
		num1--;
	}
	if(cnt1>5)
	{
		printf("EX");
	}
	else
	{
		printf("%d",cnt1);
	}
}
