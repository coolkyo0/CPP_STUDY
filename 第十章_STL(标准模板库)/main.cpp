/**
* 第十一章 STL(标准模板库)
*
* @目标 深入学习标准模板库
*/
#include <stdlib.h>

#include "11_18智能指针.h"
#include "11_x自己实现一个字符串类.h"

void main()
{
	//fun11_18autoPtr();

	/**
	* 有点没看懂为什么下面的代码，delete释放char*数组时会引发异常？   网上搜下答案喽
	* @fuck ，fuck, new char[num];   new 数组后面应该是[]中括号而不是()！！！！！！！！！！！！！！
	* @所以 char* str = new char(10);  总是出现崩溃现象



	//下面的代码是错误范例，正确的应该是  new char[10]
	char* str = new char(10);
	strcpy_s(str, 10, "123");
	delete str;

	*/

	fun11_xTest1();
	fun11_xTest2();

	system("pause");
}
