#pragma once
#define STATIC_TEST 1
/*
���κ�һ���ļ��������������һ����ͬ��ַ��stat_param��global_param��˵���˾��ǲ����˲��ݸ����ı���
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

