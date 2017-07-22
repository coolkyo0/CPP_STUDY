/**
* 探索static把变量的作用于控制在模块内，那么什么叫做模块呢？ 凡是.c、.cpp结尾的文件都是模块。
*
*
*
*/

#pragma once
#include <stdlib.h>
#include "useStatic1.h"
#include "useStatic2.h"
#include "useStatic3.h"
#include "useStatic4.h"

void main()
{

	useStatic1();
	useStatic2();

	/**
	* .h不算是模块，所以引用同一个头文件中的static变量，地址是一样的
	*/
	useStatic3();
	useStatic4();

	/**
	* .c、.cpp都算是一个模块
	*/
	useStatic5();
	useStatic6();

	system("pause");
}