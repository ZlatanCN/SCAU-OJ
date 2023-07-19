#include "stdio.h"

int main()
{
	int a[20];
	int i;
	int j;
	int cnt=0;
	int num;
	for(i=0;i<20;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<19;i++)
	{
		for(j=i+1;j<20;j++)
		{
			if(a[i]==a[j])
			{
				cnt++;
				break;
			}
		}
	}
	
	num=20-cnt;
	//printf("%d",cnt);//ต๗สิ 
	printf("%d",num);
}


