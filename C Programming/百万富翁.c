/*一个百万富翁遇到一个陌生人，陌生人找他谈了一个换钱的计划。该计划如下：我每天给你m元，
而你第一天只需给我一分钱。第二天我仍给你m元，你给我2分钱。第三天，我仍给你m元，
你给我4分钱。依次类推，你每天给我的钱是前一天的两倍，直到一个月(30天)。
百万富翁很高兴，欣然接受这个契约。现要求，编写一个程序，由键盘输入m，
计算多少天后，百万富翁开始亏钱。*/
#include <stdio.h>
int main()
{
	int day=1;
	double m,r,x,t;
	r=1.0;
	scanf("%lf",&m);
	x=m*100.0;
	t=m*100.0;
	while(t>=r)
	{
		r=r*2;
		t=t+x-r;
		day=day+1;
	}
	printf("%d",day+1);
	return 0;
}
