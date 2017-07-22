/**
* 学习显示调用的用法以及好处
*

详见：http://www.cnblogs.com/this-543273659/archive/2011/08/02/2124596.html
explicit 关键字只能用于类内部的构造函数声明上。
explicit 关键字作用于单个参数的构造函数。
在C++中，explicit关键字用来修饰类的构造函数，被修饰的构造函数的类，不能发生相应的隐式类型转换

http://blog.csdn.net/luomoshusheng/article/details/47133603

*/
#pragma once
class Explicit
{
public:
	explicit Explicit();

	/** 使用explicit修饰就不能隐式转换了，必须显示的调用 */
	explicit	
		Explicit(int i);
	~Explicit();

	int m_i;
};

void fun13_4explicitTest();