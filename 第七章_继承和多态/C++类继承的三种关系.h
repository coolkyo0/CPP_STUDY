/**
* 学习第7.1章
*
* @目标1 如果不是虚函数，子类的函数覆盖父类的函数会产生编译错误吗？ 
* @目标2 protected：当子类不能代替父类完成父类接口而声明的接口。子类不能代替父类完成父类接口是什么意思？
* @目标3 protected：子类不能自动转换成父类接口是什么意思？
* @目标4 子类protected继承父类的成员函数、成员变量，子类是否有权限访问。
* @目标5 如何理解private是一种实现继承？
* @目标6 如何理解private继承：子类不能代替父类完成父类声明的接口？子类不能自动转换成父类的接口是什么意思？
* @目标7 子类对象能否访问父类的私有、保护成员？
*/

#pragma once

#include <iostream>

using namespace std;

class Base
{
public:
	void printBasePublic(){ cout << "printBasePublic" << endl; }

	/** 目标1 如果不是虚函数，子类的函数覆盖父类的函数会产生编译错误吗？ */
	void overrideTest(){ cout << "父类" << endl; }

	void baseQ4()
	{
		cout << "baseQ4" << endl;
	}

	virtual void baseQ6()
	{
		cout << "Base baseQ6" << endl;
	}

	/**
	* virtual void grammarTest() = 0;
	* @语法 子类如果不实现父类的纯虚函数会报语法错误。
	*/



	void 你好啊()
	{
		cout << "你好啊" << endl;
	}


protected:
	void printBaseProtectd(){ cout << "printBaseProtectd" << endl; }

	/**
	* @目标2 protected：当子类不能代替父类完成父类接口而声明的接口。子类不能代替父类完成父类接口是什么意思？
	*
	*/
	virtual void q2()
	{
		cout << "Base q2" << endl;
	}

private:
	/** @目标7 子类能否访问父类的私有、保护成员？ */
	void subclassAccessSupclassPrivate(){ cout << "subclassAccessSupclassPrivate" << endl; }
	int supclassIntMem;
};

class PublicBase : public Base
{
public:
	void for7_1_Q7()
	{
		/**
		* Q7:子类对象能否访问父类的私有、保护成员？
		*
		* @结论 public继承父类时，子类函数无法访问父类的私有成员，可以访问父类的protected
		* @现象 subclassAccessSupclassPrivate();	编译错误
		* @现象 supclassIntMem = 10;				编译错误
		*/
		printBaseProtectd();
	}
protected:
private:
};

class ProtectedDervied : protected Base
{
public:
	void q7()
	{
		/**
		* 目标7：子类能否访问父类的私有、保护成员？
		*
		* @目标7结论 子类不能访问父类的私有函数 subclassAccessSupclassPrivate();
		* @目标7结论 子类不能访问父类的私有变量 supclassIntMem = 10;
		* @目标7结论 强行访问会产生编译错误。
		*/
		
		
	}

	/**
	* 由于是保护继承自父类，所以虚函数也没多大意义，因为父类指针不能指向子类，也就不能形成多态！
	*
	*
	*/
	virtual void q2()
	{
		cout << "Derived q2" << endl;
	}

	void derived1Q4()
	{
		baseQ4();
	}

	void derviedForQ7()
	{
		/**
		* Q7:子类对象能否访问父类的私有、保护成员？
		*
		* @结论 protected继承父类时，子类函数无法访问父类的私有成员，可以访问父类的protected
		* @现象 subclassAccessSupclassPrivate();	编译错误
		* @现象 supclassIntMem = 10;				编译错误
		*/
		printBaseProtectd();
	}
};
class PrivateDervied : private Base
{
public:
	/** q5 */
	void print()
	{
		printBasePublic();
		printBaseProtectd();
	}

	/** q6 */
	void baseQ6()
	{
		cout << "PrivateDervied" << endl;
	}
};

class A : public ProtectedDervied
{
public:
	void print()
	{
		printBaseProtectd();
		printBasePublic();
	}

	/**
	* 目标1：如果不是虚函数，子类的函数覆盖父类的函数会产生编译错误吗？
	* 
	* @目标1结论 如果不是虚函数，子类函数覆盖父类函数不会发生编译错误。
	*
	*/
	void overrideTest(){ cout << "子类" << endl; }


};

class B : public PrivateDervied
{
public:
	void print()
	{
		/**
		* printBaseProtectd();
		* printBasePublic();
		* 
		* @结论 如果父类的函数是其父类的私有成员，所有子类都无法访问父类私有成员，不管成员是如何继承、继承了多少次。
		*/
	}
};

void for7_1Q2Q3()
{
	Base b1;
	ProtectedDervied d1;


	Base* pb1 = (Base*)(new ProtectedDervied);			/** 注意C++是强类型语言，必须进行类型转化 */
	ProtectedDervied* pd1 = (ProtectedDervied*)(new Base);		/** 注意C++是强类型语言，必须进行类型转化 */


	/**
	* q2:protectd是一种实现继承，子类不能代替父类完成父类接口所声明的行为，此时子类不能自动转换成父类的接口。
	*
	* @现象 pb1->q2(); 语法编译通不过。
	* @理解 子类通过protected方式继承父类，所以用基类指针指向父类时无法访问直接访问父类的成员函数，只能通过自己的函数间接访问，既然只能间接访问，所以虚函数在子类中实现也就没什么意义了！
	* @理解 所以protected是一种实现继承，子类只是调用父类的实现！子类无法通过接口继承改变函数的行为方式，同时也起到了保护父类的效果！
	*
	* q3:子类不能自动转换成父类接口是什么意思？
	*
	* @理解 子类不能直接调用父类接口。
	*/

	pd1->q2();
}

void for7_1Q4()
{
	Base b1;
	ProtectedDervied d1;

	/**
	* q4:子类protected继承父类的成员函数、成员变量，子类是否有权限访问。
	*
	* @理解 d1.baseQ4();编译报错，子类无法直接访问父类的protected，但是子类的成员函数可以访问。
	*/
	b1.baseQ4();

	d1.derived1Q4();
}

void for7_1Q5()
{
	/**
	* q5:如何理解private继承是一种实现继承？
	*
	* @理解 和protected有点类似，即使子类是私有继承父类，子类的函数依然可以访问父类的函数，但是子类的对象就无法访问父类的所有函数和对象了。---
	* ------由于是私有派生，派生类对象直接访问 pd.printBasePublic(); 则报编译错误。
	*/
	PrivateDervied pd;
	pd.print();
}

void for7_1Q6()
{
	/**
	* q6 如何理解private继承：子类不能代替父类完成父类声明的接口？子类不能自动转换成父类的接口是什么意思？
	*
	* @code Base* b = (PrivateDervied*)(new PrivateDervied);
	* @code pd.baseQ6();
	* 
	* @理解 上面的代码会报错，PrivateDervied派生自Base，Base中有虚函数baseQ6，在子类中帮忙实现了baseQ6，但是当用父类指针b指向子类时，不能访问成员函数baseQ6
	*/
}


void for7_1Q7()
{
	/**
	* q7:子类对象能否访问父类的私有、保护成员？
	*
	* @结论 子类的对象不能访问，但是子类的函数实现是可以访问的。
	*/
}



/**
* 一些测试
*
*
*/
class TestBase
{
public:
	TestBase(int n1, int n2) : m(n1), n(n2)
	{

	}
protected:
	int m;

private:
	int n;
	int getN()
	{
		return n;
	}
};

class DerviedTestBase : private TestBase
{
public:

	DerviedTestBase(int i1, int i2) : TestBase(i1, i2)
	{

	}

	int getTestBaseProMem()
	{
		return m;
	}

	int getTestBasePriMem()
	{
		/**
		* @结论 return n; n是私有不可访问
		* ------return getN(); getN是私有不可访问
		* @结论 子类能否访问父类的成员与继承属性无关，和父类自身成员的属性有关，比如说父类的private对子类是不透明的。
		* @结论 子类能访问父类的保护，但是父类的保护对子类来说只提供了实现，子类无法对其进行多态来进行改造，因为protected就是保护的意思，保护父类！！！！
		*/
		
		
		return m;
	}
protected:


};

void forTestBase()
{
	DerviedTestBase tb(1, 2);

	int rt1 = tb.getTestBaseProMem();
	int rt2 = tb.getTestBasePriMem();

}


void 嗨()
{
	Base b;
	b.你好啊();
}