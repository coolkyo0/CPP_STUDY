/**
* 本例主要为了考察C++中包含const、引用成员变量时，copy构造函数是什么情况
*
* @结论 引用成员变量必须用引用形参进行初始化，这样引用成员才可以指向初始化的对象，如果用int型变量初始化变量，会在栈上形成形参，用形参初始化引用，当函数结束时，成员变量指向栈地址，该引用变量的值是未定义的。
*/

#pragma once
class ClassWithQuotaMember
{
public:
	//ClassWithQuotaMember();
	ClassWithQuotaMember(int i, int c, int& q);
	virtual ~ClassWithQuotaMember();

	
	int m_i;
	const int m_ci = 10;
	//const int& m_qi;	// = m_i;
	int &m_ri;	// = m_i;

	
};

void fun13_5classWithQuotaMem();