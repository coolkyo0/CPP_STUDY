/**
* 本文件主要是定义引用的引用，以及了解引用的地址与被引用地址之间的关系，有人说引用是封装自指针，那么是如何封装的呢？
*/

#include <iostream>
#include <stdlib.h>

using namespace std;




/**
* 常量引用可以指向非常量，所以就不能通过常量引用改变被引用的值。
* 但是直接改变被引用的值会出现问题吗？书上的意思是可以的，但是我还是要亲自去实验下。
*
*/
void fun()
{
	int a = 0;
	const int& quo = a;
	/** 直接改变a的值不会报语法错误 */
	a = 2;		
}


void main()
{
	int a = 1;
	int b = 2;
	int &c = b;
	int &d = c;

	cout << "&b = " << &b << endl;
	cout << "&c = " << &c << endl;
	cout << "&d = " << &d << endl;
	

	/** 引用的引用该如何定义？请参考指针的指针 char** p; 也就是 char&& p; */

	system("pause");
}