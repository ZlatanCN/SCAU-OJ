#include <stdio.h>
int main()
{
	int a,b,c;
	scanf("%d,%d,%d",&a,&b,&c);
	//a��� 
	if(a>b&&a>c){if(b>c){
		printf("%d,%d,%d",c,b,a);
	}else{
		printf("%d,%d,%d",b,c,a);
	}
	}
	//b��� 
	if(b>a&&b>c){if(a>c){
		printf("%d,%d,%d",c,a,b);
	}else{
		printf("%d,%d,%d",a,c,b);
	}
	}
	//c��� 
	if(c>a&&c>b){if(a>b){
		printf("%d,%d,%d",b,a,c);
	}else{
		printf("%d,%d,%d",a,b,c);
	}
    }
}
	
