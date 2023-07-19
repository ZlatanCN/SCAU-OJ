#include<stdio.h>
 
int main()
{
  char a,b,c,d,e;
  scanf("%c%c%c%c%c",&a,&b,&c,&d,&e);
  if(a>='A'&&a<='Z')a=a+32;
  if(b>='A'&&b<='Z')b=b+32;
  if(c>='A'&&c<='Z')c=c+32;
  if(d>='A'&&d<='Z')d=d+32;
  if(e>='A'&&e<='Z')e=e+32;
  printf("%c%c%c%c%c",a,b,c,d,e);
}
