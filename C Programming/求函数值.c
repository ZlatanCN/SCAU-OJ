#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*����x(xΪ����)������ֵ�������������£�

F(x)=x          	         xС��3
F(x)=F(x/3)*2   	         x���ڵ���3��xΪ3�ı���
F(x)=F((x-1)/3)+1   	x���ڵ���3��x��3��1
F(x)=F((x-2)/3)+2   	x���ڵ���3��x��3��2

��������
20

�������
6*/

int F(int x);
int main()
{
	int x;
	scanf("%d",&x);
	printf("%d",F(x)); 
}
int F(int x)
{
	int ans;
	if(x<3)
	ans=x;
	if(x>=3&&x%3==0)
	ans=F(x/3)*2;
	if(x>=3&&x%3==1)
	ans=F((x-1)/3)+1;
	if(x>=3&&x%3==2)
	ans=F((x-2)/3)+2;
	return ans;
} 


