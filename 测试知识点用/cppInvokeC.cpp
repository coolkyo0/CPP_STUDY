#include "cppInvokeC.h"


cppInvokeC::cppInvokeC()
{
}


cppInvokeC::~cppInvokeC()
{
}


/**
* CPP直接调用C的代码出现的错误如此下
*

* 错误	1	error LNK2019: 无法解析的外部符号 "void __cdecl print_hello_world(void)" (?print_hello_world@@YAXXZ)，
			该符号在函数 "void __cdecl fun13_11cppinvokec(void)" (?fun13_11cppinvokec@@YAXXZ) 中被引用	D:\STUDY\CPP_STUDY\测试知识点用\cppInvokeC.obj	测试知识点用

* 错误	2	error LNK1120: 1 个无法解析的外部命令	D:\STUDY\CPP_STUDY\Debug\测试知识点用.exe	测试知识点用
* 
* 
* @原因 C与C++编译方式不一样，C语言没有重载没有把参数编译进去。 c的编译方式为__cdecl
* @
*/
void fun13_11cppinvokec()
{
	print_hello_world();
}
