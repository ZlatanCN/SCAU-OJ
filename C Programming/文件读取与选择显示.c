#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*�ڵ�ǰĿ¼�д����ļ���Ϊ"case1.in"���ı��ļ�����Ҫ��򿪸��ļ�����������������ַ���ֻ�����е������ַ����Ⱥ�˳����ʾ����Ļ�ϡ�

����case1.in�������£� 
13 cats and 22 bikes

������Ļ�����������£� 
1322*/

main()
{
	FILE *fp;
    char ch;
	if((fp=fopen("case1.in","r"))==NULL)
        return 0;
    while((ch=fgetc(fp))!=EOF)
    {
    	if(ch>='0'&&ch<='9')
    	putchar(ch);
    }
    fclose(fp);
}
