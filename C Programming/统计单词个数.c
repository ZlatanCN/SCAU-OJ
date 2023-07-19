#include <stdio.h>
#include <stdlib.h>

main()
{
	int i;
	int cnt=0;
	char msg[80];
	gets(msg);
	for(i=0;msg[i]!='\0';i++)
	{
		if(msg[i]==' ')
		{
			if(msg[i+1]!=' ')
			{
				cnt++;
			}
		}
	}
	printf("%d",cnt+1);
}
