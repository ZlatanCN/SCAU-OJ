#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*输入x(x为整数)，求函数值，函数定义如下：

F(x)=x          	         x小于3
F(x)=F(x/3)*2   	         x大于等于3且x为3的倍数
F(x)=F((x-1)/3)+1   	x大于等于3且x除3余1
F(x)=F((x-2)/3)+2   	x大于等于3且x除3余2

输入样例
20

输出样例
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


