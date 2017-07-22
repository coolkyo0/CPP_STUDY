/**
* 单例
*/


////////////////////////////////////////////////
// FileName: singlet.h
// Author: Liulei
// Date: 2011-9-20 15:05
// Description: 简单易用的单件实现基类
////////////////////////////////////////////////

#ifndef _SINGLET_H_
#define _SINGLET_H_

#include <memory>

template<class T>
class CSingleT
{
public:

	static T * Instance()
	{
		if (!ms_pObject)
		{
			ms_pObject = new T;
		}
		return ms_pObject;
	}

	static void Create()
	{
		if (!ms_pObject)
		{
			ms_pObject = new T;
		}
	}

	static void Destroy()
	{
		if (ms_pObject)
		{
			delete ms_pObject;
			ms_pObject = NULL;
		}
	}

	static T* Get()
	{
		return ms_pObject;
	}

	static void Reset()
	{
		Destroy();
		Create();
	}

protected:
	static T*	ms_pObject;
};

/**
* @明白 即使不初始化ms_pObject，在编译时也会初始化位NULL。
*
* @不明白 为什么不声明 ms_pObject就会出现编译错误呢？
*
*/
template<class T>
T* CSingleT<T>::ms_pObject;// = NULL;



/***************************************************************************/
class A13_1
{
public:
	A13_1()
	{
		/**
		*
		* @错误 m_cNum = 10;	
		* @attention 类的常量成员不能在构造函数中初始化，值可以在类中定义时或者初始化列表，其中初始化列表比定义后初始化，所以初始化列表中的值会覆盖定义时初始化的值。
		*/
	}

	A13_1(int i) : m_cNum(i)			/** const成员变量的初始化1：初始化列表中初始化。比定义初始化迟，所以这里初始化的值会覆盖定义时的值 */	
	{

	}

	~A13_1(){}

	static int m_snum;					/** 注意：static变量不能在类中初始化，因为该变量不属于类 */
	const int m_cNum = 2;				/** const成员变量的初始化2：定义的时候初始化。比初始化列表中早 */
	const static int m_csNum = 12;		/** const static的值在类中定义时初始化，初始化效果类似于小面的编号1，只能选择其中一种，否则会出现重复初始化编译错误 */
	static const std::string str;
	const static char m_pcstr[m_csNum];	// = "Hello";  不能初始化，否则会出错
};

const std::string A13_1::str("123");
/** 编号1 *///const int A13_1::m_csNum = 12;				

const char A13_1::m_pcstr[m_csNum] = "Hello World";

/**
* 静态的的整形、枚举成员变量也可以在类中初始化
*
*/

/**
* 通常类静态成员变量在类声明中初始化
*
* @问题1 为什么要在类声明中初始化？
* @问题2 除了类声明中还可以在哪里初始化？
*
* @回答1 
* @回答2 除了头文件还可以在实现文件中初始化。  可以在头文件中初始化吗？
*/
/*int A13_1::m_i = 0;*/
#endif