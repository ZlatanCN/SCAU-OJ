/*����10����������������С�������һ���������������������һ����������ʹ��3������������⣺
(1) ����10�������ĺ���
(2) ���н�������ĺ���
(3) ���10�����ĺ���*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void input(int a[])
{
	int i;
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
}

void swap(int a[])
{
	int b[10],i,j,temp;
	for(i=0;i<10;i++)
	{
		b[i]=a[i];
	}
	for(i=0;i<9;i++)
	{
		for(j=0;j<9-i;j++)
		{
			if(b[j]>b[j+1])
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	}
	for(i=0;i<10;i++)
	{
		//printf("%d\n",b[i]);
		if(a[i]==b[0])
		{
			a[i]=a[0];
			a[0]=b[0];
			break;
		}
	}
	for(i=0;i<10;i++)
	{
		if(a[i]==b[9])
		{
			a[i]=a[9];
			a[9]=b[9];
			break;
		}
	}
}

void display(int a[])
{
    int i;
    for(i=0; i<10; i++)
        printf("%d\n", a[i]);
}

int main()
{
    int a[10];
    input(a);
    printf("input done\n");
    swap(a);
    printf("swap done\n");
    display(a);
    printf("display done\n");
    return 0;
} 
