


#include <iostream>
#include <stdlib.h>

/**
* ���صĵ�ַ�ϵ�ֵ�ǲ��ᷢ���κθı��
* ��Ϊ�ֲ������ַ����Ǵ���ȫ���������ģ������޷����ı䣬
* һ�����Ըı�ͻᷢ��������������Ҿ��ú������ý������õ�ַ�ϵ�ֵҲ���ᷢ���仯��
*/
char* getMemory()
{
	char p[] = "Hello World";
	return p;
}

void getMemory1()
{
	char* p = (char*)malloc(10);
}

void main()
{
	char* t = getMemory();
	
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;

	system("pause");
}