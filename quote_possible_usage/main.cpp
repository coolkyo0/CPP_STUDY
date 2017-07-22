/*
*@	本Demo旨在探索引用的各种用法：
*@	1：引用接收函数成员变量，改变引用的值函数成员变量也跟着变化。
*/



/*
*@	stdlib 头文件即standard library标准库头文件。stdlib.h里面定义了五种类型、一些宏和通用工具函数。 类型例如size_t、wchar_t、div_t、ldiv_t和lldiv_t； 
*@	宏例如EXIT_FAILURE、EXIT_SUCCESS、RAND_MAX和MB_CUR_MAX等等； 常用的函数如malloc()、calloc()、realloc()、free()、system()、atoi()、atol()、rand()、srand()、exit()等等。 
*@	具体的内容可以打开编译器的include目录里面的stdlib.h头文件查看。
*/
#include <stdlib.h>

/*
*@ 标准输入输出，诸如：printf、scanf、getc、getchar、puts、gets等等。
*/
#include <stdio.h>




/*
*@	1：引用接收函数成员变量，改变引用的值函数成员变量也跟着变化。
*/
class A
{
public:
	A() : m_nMember1(1), m_nMember2(2)
	{

	}

	int& GetMember1(){ return m_nMember1; }
	int& GetMember2(){ return m_nMember2; }

	void SetMember1(int nParam){ m_nMember1 = nParam; }


private:
	int m_nMember1;
	int m_nMember2;
};


class B
{
public:
	B(){}
	~B(){}

	void SetMember(const A& aObj){ m_aObj = aObj; }

private:
	A m_aObj;
};

int main()
{
	/*
	*	1.函数返回引用，可以用非引用m1和m2接收返回值，但是当m1和m2的值改变时，aObj的成员m_nMember1、m_nMember2不跟着改变。
	*/
	A aObj1, aObj2;

	int m1 = aObj1.GetMember1();
	int m2 = aObj1.GetMember2();

	m1 = 10;
	m2 = 20;

	/*
	*	1.函数返回引用，用引用qm1、qm2接收返回值，当m1和m2的值改变时，aObj的成员m_nMember1、m_nMember2跟着改变。
	*	2.如果GetMember1返回非引用，用引用qm1去接收会报错。
	*/


	/*
	*@	这样不太好，私有成员变量被随意改动
	*/
	int& qm1 = aObj2.GetMember1();		
	int& qm2 = aObj2.GetMember2();

	qm1 = 10;							
	qm2 = 20;


	B bObj1, bObj2;

	bObj1.SetMember(aObj1);
	bObj2.SetMember(aObj2);

	system("pause");
	return 1;
}