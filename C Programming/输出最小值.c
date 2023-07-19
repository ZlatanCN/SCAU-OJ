#include <stdio.h>
main()
{  int i,t,min;
   scanf("%d", &min);
   for(i=1;i<10;i++)
   {
      scanf("%d", &t);
      if(t<min) min=t;
   }
   printf("%d\n",min);
}
