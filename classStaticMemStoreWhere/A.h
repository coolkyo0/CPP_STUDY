#pragma once

class CA
{
public:
	CA();
	~CA();


	static int m;


	/** 为什么类的静态成员常量可以在类中进行初始化？奇怪啦 */
	const static int n = 0;
};

/**
* 静态成员声明以后必须初始化，否则会出现错误：error LNK2001: 无法解析的外部符号 "public: static int CA::m" (?m@CA@@2HA)
* error LNK1120: 1 个无法解析的外部命令	D:\STUDY\CPP_STUDY\Debug\classStaticMemStoreWhere.exe	classStaticMemStoreWhere
* @note 初始化不能为static int CA::m = 0;
* @note 初始化不能放在头文件中，否则会出现错误	1	error LNK2005: "public: static int CA::m" (?m@CA@@2HA) 已经在 A.obj 中定义	
* @note 错误	2	error LNK1169: 找到一个或多个多重定义的符号	D:\STUDY\CPP_STUDY\Debug\classStaticMemStoreWhere.exe	classStaticMemStoreWhere
*/