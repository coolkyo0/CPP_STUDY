#pragma once

#include <iostream>
using namespace std;

/**
* 我们再这里尝试定义class的模板类，为什么要在这里定义模板类呢？因为书上说struct不能用模板类来定义
* @define template<class T> or template<typename T>
***/
template<typename T> class TC1
{
public:
	TC1();
	TC1(T t1);
	~TC1<T>();

	T m1;
	T m2;

	void setValue(T var1, T var2);
	T getMax();

	void print();
private:

};

template<typename T>
void TC1<T>::print()
{
	cout << "class template:" << "m1 = " << m1 << endl;
	cout << "class template:" << "m2 = " << m2 << endl;
}

/**
* 为什么模板的实现要用template<class T> TC1<T>::TC1() 呢？
* template<class T> TC1::TC1()也不会错吧?
* @note 模板的声明和实现应该放在同一个文件夹里，否则会出现链接错误，因为模板在使用时才产生对象实例。
* @note 错误	1	error LNK2019: 无法解析的外部符号 "public: __thiscall TC1<int>::TC1<int>(void)" (??0?$TC1@H@@QAE@XZ)，该符号在函数 "void __cdecl useTemplatePrintMax(void)" (?useTemplatePrintMax@@YAXXZ) 中被引用
* @note 模板函数在实现时应该定义为下面的格式：template<class T> TC1<T>::TC(){}  注意，不能定义为TC1::TC()，否则会出现编译错误：error C2955: “TC1”: 使用 类 模板 需要 模板 参数列表，error C2244: “TC1<T>::{ctor}”: 无法将函数定义与现有的声明匹配	
*
*/
template<typename T>
TC1<T>::TC1()
{

}

template<class T> TC1<T>::TC1(T t1)
{

}

template<class T> TC1<T>::~TC1()
{

}

template<typename T>
void TC1<T>::setValue(T var1, T var2)
{
	m1 = var1;
	m2 = var2;
}


template<typename T>
T TC1<T>::getMax()
{
	return m1 > m2 ? m1 : m2;
}






/**
* 我们再这里尝试定义struct的模板类
*
***/
template<class T> struct TS1
{
public:
	TS1();
	TS1(T t1);
	~TS1<T>();

	T m1;
	T m2;

	void setValue(T var1, T var2);
	T getMax();

	void print();
private:

};

template<class T>
void TS1<T>::setValue(T var1, T var2)
{
	m1 = var1;
	m2 = var2;
}

template<class T>
void TS1<T>::print()
{
	cout << "struct template:" << "m1 = " << m1 << endl;
	cout << "struct template:" << "m2 = " << m2 << endl;
}

template<class T>
TS1<T>::TS1()
{

}

template<class T> TS1<T>::TS1(T t1)
{

}

template<class T> TS1<T>::~TS1()
{

}


/**
* 下面我们定义模板函数
*
*
*
*/
template<class T>
void templateFunPrint(T var1, T var2)
{
	cout << "templateFunPrint: var1 = " << var1 << "\tvar2 = " << var2 << endl;
}