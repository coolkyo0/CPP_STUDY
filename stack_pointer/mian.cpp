


#include <iostream>
#include <stdlib.h>

/**
* 返回的地址上的值是不会发生任何改变的
* 因为局部常量字符串是存在全局数据区的，而且无法被改变，
* 一旦尝试改变就会发生编译错误，所以我觉得函数调用结束，该地址上的值也不会发生变化。
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