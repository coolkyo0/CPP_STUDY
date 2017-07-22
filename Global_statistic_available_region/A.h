#pragma once
#define STATIC_TEST 1
/*
被任何一个文件包含，都会产生一个不同地址的stat_param、global_param，说白了就是产生了不容副本的变量
*/

#include "globalVar.h"

static int stat_param = 10;
static int global_param = 20;

extern int ext_a;
extern int ext_b;

extern int global;

class A
{
public:
	A();
	A(int n, int m);
	~A();

	void _print();
};

