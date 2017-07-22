/**
* 本Demo主要目的
*
* @目的1 了解什么叫拷贝构造，什么叫赋值，拷贝构造与赋值的区别？
* @目的2 了解类默认的赋值是深拷贝还是浅拷贝，当类中有指针时比较好比较。
*/

#include <iostream>

using namespace std;

class Test
{
	int a;
public:
	Test(){}
	Test(int n) : a(n){}
	/**
	* 为什么Test(const Test&t)会是拷贝构造函数呢？
	* 因为Test a1; Test a2 = a1;相当于Test a2(a1);
	*
	*/
 	Test(const Test& t)
 	{
		cout << "copy construct" << endl;
 		a = t.a;
 	}

	/**
	* 重载操作符是如何定义的？
	* @note 我认为重载拷贝构造函数应该是这个呀？
	* @note 下面应该是重载赋值操作符吧，拷贝构造函数被赋值之间的区别？是什么？
	* @note 拷贝构造函数是构造，是在构造一个对象以后才会执行的动作。
	* @note 赋值运算符不是在构造时的动作，而是对象已经被构造后对其进行赋值的操作。
	*/
	Test& operator = (const Test& t)			//a = b = c = d;
	{
		cout << "operator =" << endl;
		if (&t != this)
		{
			a = t.a;
		}
		
		return *this;
	}

// 	void operator = (const Test& t)				//a = b = c; 连等会出错
// 	{
// 		
// 		if (&t != this)
// 		{
// 			a = t.a;
// 		}
// 	}

	~Test(){}

private:

};

void fun1(Test test)
{
	cout << "fun1..." << endl;
}

Test fun2()
{

	Test t2;
	cout << "fun2..." << endl;
	return t2;
}

/**
* 写出函数打印的是什么？
* @考点1 识别出什么时候调用拷贝构造，什么时候调用赋值。
* @考点2 区分什么叫拷贝构造，什么叫赋值。
*
*/
void printIsWhat()
{
	Test t1(1);
	Test t2 = t1;	//调用拷贝构造
/*	Test t5(t2);	//调用拷贝构造*/

// 	Test t4;
// 	t4 = t2;

	cout << "before fun1()..." << endl;
	fun1(t1);

	Test t3 = fun2();
	cout << "after fun2()..." << endl;
}


/**
* 当类中含有指针成员变量时，默认的拷贝构造函数是否是深拷贝？
* @note C++中默认会有构造、析构、拷贝构造、赋值、☆☆取地址（这个我不太明白，也就是int a;int *p = &a;）
*/
class CHavePointer
{
public:
	CHavePointer()
	{
		m_str = NULL;
		m_strLen = 0;
	}
	CHavePointer(const char* str)
	{
		if (str != NULL)
		{
			m_strLen = strlen(str);
			m_str = new char(m_strLen + 1);
			strncpy_s(m_str, m_strLen + 1, str, m_strLen + 1);

			m_use++;
		}
	}

	CHavePointer(CHavePointer& ch)
	{
		m_use++;
		m_str = ch.m_str;
		m_strLen = ch.m_strLen;
	}

	CHavePointer& operator = (CHavePointer& ch)
	{
		m_use++;
		m_str = ch.m_str;
		m_strLen = ch.m_strLen;

		return *this;
	}

	~CHavePointer()
	{
		if (m_use > 0)
		{
			m_use--;
		}
		else
		{
			/** 删除数组时[]放在数组名的前面 */
			delete []m_str;
			m_str = NULL;
		}
	}

public:
	char* m_str;
	unsigned int m_strLen;
	static int m_use;
};

int CHavePointer::m_use = 0;

/**
* 本函数是为了探索当类中存在指针时，系统默认的拷贝构造函数与赋值函数是深拷贝还是浅拷贝。
*
*/
void deepOrShadowCopy()
{
	CHavePointer var1("Hello World");
	CHavePointer var2 = var1;

	if (var1.m_str == var2.m_str)
	{
		cout << "system default copy construct is shadow copy" << endl;
	}
	else
	{
		cout << "system default copy construct is deep copy" << endl;
	}

	CHavePointer var3;
	var3 = var2;

	if (var3.m_str == var2.m_str)
	{
		cout << "system default assignment is shadow assign" << endl;
	}
	else
	{
		cout << "system default assign is deep assign" << endl;
	}
}


/**
* 类中系统默认的函数在用户定义了以后就不会再生成了。
* @note 那么问题来了？ 这些构造函数是使用后才会生成还是类定义时就默认生成呢？
*/
class ClassTest
{
public:
	ClassTest(){}
	~ClassTest(){}

private:

};

void printClassSize()
{
	ClassTest t1;
	cout << "sizeof(ClassTest) = " << sizeof(ClassTest) << endl;

	ClassTest t2 = t1;
	cout << "after use default copy construct, sizeof(ClassTest) = " << sizeof(ClassTest) << endl;


	/**
	* 如果类中没有数据成员也没有成员函数时，类的大小为1，为什么呢？因为系统插入一个字节方便定位？？？
	*
	*/
}



int main()
{

	//deepOrShadowCopy();
	
	
	
	//printIsWhat();


	printClassSize();

	system("pause");
	return 0;
}