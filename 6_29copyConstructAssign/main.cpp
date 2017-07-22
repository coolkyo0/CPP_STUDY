/**
* 本例主要是为了明白函数中返回一个变量时是否会构造一个对象。
*
*/
#include <iostream>
#include <Windows.h>

#include "6_30staticMemAndTemVar.h"
#include "6_31tempVar.h"
#include "6_33funOverload.h"

using namespace std;




class A
{
public:
	A() : m(0)
	{
		print_s("普通构造 A() : m(0)");
		cout << "普通构造 A() : m(0)" << endl;
	}

	A(const A& a)
	{
		print_s("拷贝构造 A(const A& a)");
		cout << "拷贝构造 A(const A& a)" << endl;
		m = a.m;
	}



#define TEST

#ifdef TEST

	/**
	* 返回引用可以少一次构造函数，直接把*this返回，那么被赋值的和接收的地址是否一样？
	* @答案 如果返回引用，那么接收者和this是同一个对象。
	*/
	A& operator = (const A& a)
	{
		cout << "赋值 A& operator = (const A& a)" << endl;
		m = a.m;

		print_s("赋值 A& operator = (const A& a)");

		//cout << "\t\t\t\t\tthis = " << this << endl;
		return *this;
	}

	void print_s(const int n)
	{
		char ch[100];
		sprintf_s(ch, "m = %d\n", n);
		OutputDebugString(ch);
	}

	void print_s(const char* pcstr)
	{
		char ch[100];
		sprintf_s(ch, "%s\n", pcstr);
		OutputDebugString(ch);
	}

#else
	A& operator = (const A a)
	{
		cout << "A& operator = (const A& a)" << endl;
		m = a.m;

		return *this;
	}
#endif // 1

	~A()
	{
		cout << "析构 ~A()" << " m = " << m << endl;
		print_s(m);
		
// 		if (m == 10)
// 		{
// 			int *p = NULL;
// 			*p = 10;
// 		}
	}

	int m;

private:

};

A fun()
{
	A b;		//调用普通构造
	return b;	//调用拷贝构造返回，以a为副本
}

A& funRtQuote()
{
	A b;		//调用普通构造
	return b;	//调用拷贝构造返回，以a为副本
}

void fun1()
{
	A a;
}

/**
* 测试返回引用后可否改变被引用的值
*
*/

// #define TEST_1 0
// 
// #if TEST_1
// 	A *gpa = new A;
// 	A fun1()
// 	{
// 		cout << "fun1 ga = " << gpa << endl;
// 		/** 直接返回*ga对象，并不会以*ga作为对象构造一个返回！！！切记 */
// 		return *gpa;	//只调用了一次析构
// 	}
// #else
// 	A gpa;
// 	A fun1()
// 	{
// 		return gpa;
// 	}
// #endif






/**
* 测试函数返回时是否会构造一个对象进行返回？
* @答案 试验结果表明不会构造返回一个对象进行返回。
*/
// void Test()
// {
// 	/** 直接以*ga作为副本调用拷贝构造函数，所以ga与&rtga的地址是不同的 */
// 	A rtga = fun1();
// 	cout << "&rtga = " << &rtga << endl;
// 
// #if TEST_1
// 	gpa->m = 10;
// #else
// 	gpa.m = 10;
// #endif
// 
// 	cout << "Hello" << endl;
// }



void main()
{
// 	{
// 		A a;
// 		a = fun();
// 
// 		cout << "\t\t\t\t\t&a = " << &a << endl;
// 	}


	/**
	* @note fun有返回值，返回值不是引用，那么不管返回值有没有变量接收，函数return时都会调用拷贝构造函数
	*/
	//A a = fun();		
	//a.m = 10;


	/**
	* @note  funRtQuote 有返回值，返回的是引用，如果用引用接收，return是不会调用拷贝构造函数的
	*/
	//A& b = funRtQuote();


	/**
	* @note  fun 有返回值，返回的不是引用，如果用引用接收，return会调用一个拷贝构造函数
	* @note 经过我们的不停探索我们发现return是一个会调用构造函数的指令，除非接收变量以及函数返回值都是引用时才不会调用拷贝构造！！！！
	*
	*
	*/
	//A& c = fun();


	//fun1();

	//fun();
	
	//Test();

	

	
	//staticVarAndCopyConstruct(); //6_30

	//temVarWithFun();	//6_31


	//竟然把float、double的大小记模糊了
	printBaseClassSize();
	system("pause");
}