#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* �ɼ�������������ַ��������ŵ�����Сд�ַ�bye��Ϊ������־�����������ַ�������bye����д���½����ļ�answer.txt�У�ע���ļ����ڵ�ǰĿ¼���� 
����ɸù��ܣ���ע�⣬����⣬�벻Ҫʹ��return 0�����������Ӱ�����ж��д�

������������������£�
He, can you write the code?
Yes, you can.bye
No, you can't.

������ִ�к����ļ�answer.txt���������£�
He, can you write the code?
Yes, you can.bye

��ע����No, you can't.��bye֮�����Բ������
��ע�������в�Ҫʹ��return��exit()�������������У�*/

main()
{
	char ch,ch1,ch2,ch3;
	FILE *fp;
	fp=fopen("answer.txt","w");
	if(fp==NULL)
	return 1;
	while((ch=getchar())!=EOF)
	{
		fputc(ch,fp);
		ch1=ch2;
		ch2=ch3;
		ch3=ch;
		if(ch1=='b'&&ch2=='y'&&ch3=='e')
		break;
	}
	fclose(fp);
}
