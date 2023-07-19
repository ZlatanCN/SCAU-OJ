#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**/

struct DATE
{
	int year;
	int month;
	int day;
};

int days(struct DATE date)
{
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int sum=0,i;
	if(date.month==1)
	{
		sum=date.day;
	}
	if(date.month>1)
	{
		for(i=0;i<date.month-1;i++)
		{
			sum+=a[i]; 
		}
		if((date.year%4==0&&date.year%100!=0)||(date.year%400==0)&&(date.year>2))
		{
			sum+=1;
		}
		sum+=date.day;
	}
	return sum;
}

int main()
{
    struct DATE d;
    scanf("%d-%d-%d", &d.year, &d.month, &d.day);
    printf("%d", days(d));
}


