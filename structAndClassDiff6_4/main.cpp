/**
* 本例在于探索struct与class的区别  -----------注意：本代码只是讨论在C++中的区别
* @note struct中的成员变量以及继承关系默认是public，而class中默认是private。
* @note struct和class均可以继承。
* @note struct和class一样都可以定义除了构造/析构以外的函数。
* @note struct不能用于模板。
*/


/**
* c语言中的区别我们暂不讨论，但是我们可以写下来他们的区别，
* struct只是个结构体，只能有变量不能有成员函数。
*
*/

#include <iostream>
#include <stdlib.h>
#include <Windows.h>

#include "Singleton.h"
#include "Singleton.cpp"

using namespace std;



struct SA 
{
	int a;
	int b;
public:
	SA()
	{
		OutputDebugString("StructObj construct---------------------------\n");
	}

	virtual ~SA()
	{
		OutputDebugString("StructObj destruct---------------------------\n");
	}

	virtual void _print()
	{
		cout << "SA _print" << endl;
	}

private:

};

struct SB : public SA
{
	SB(){}
	~SB(){}

	virtual void _print()
	{
		cout << "SB _print" << endl;
	}
};

class CA
{

	int a;

public:
	CA(){}
	~CA(){}

	virtual void _print()
	{
		cout << "CA _print" << endl;
	}

private:

};

class CB : public CA
{
public:
	CB(){}
	~CB(){}

	virtual void _print()
	{
		cout << "CB _print" << endl;
	}

private:

};

/**
* struct和class均可以继承。
* struct和class一样都可以定义除了构造/析构以外的函数。
*
*
*/
void _pointer()
{
	/** struct特性的研究 */
	SA sa;
	sa.a = 10;

	SB sb;
	sb.a = 10;
	sb.b = 20;


	SA* psa = new SA;
	SB* psb = new SB;

	SA* psat = psb;
	SB* psbt = (SB*)psa;

	cout << "psa - > psb ";
	psat->_print();
	cout << "psb - > psa ";
	psbt->_print();


	/** class特性的研究 */
	CA* pca = new CA;
	CB* pcb = new CB;

	CA* pcat = pcb;
	CB* pcbt = (CB*)pca;

	cout << "pca - > pcb ";
	pcat->_print();
	cout << "pcb - > pca ";
	pcbt->_print();
}

/** struct中的成员变量默认是public，而class中默认是private */
void memAccessible()
{
	SA sa;
	CA ca;

	sa.a = 10;
	/**
	* sa.a = 10;
	* 编译不报错说明struct中的a默认情况下是公有的。
	*/


	/**
	* ca.a = 10;
	* 编译器报错说明class中的a默认情况下是私有的。
	*
	****/

}

/**
* class模板的使用
* 
* @
*/
void useClassTemplatePrint()
{
	int a = 10;
	int b = 20;

	TC1<int> t;
	t.setValue(a, b);
	t.print();
}

/**
* struct模板的使用
* @note C/C++面试大全上说struct不能使用模板，但是我们实际敲代码可以确定可以使用类模板啊？？？？
* @note 经过再次阅读书籍，我们得知他的意思是不能定义这样的模板：template<struct T> class TC{}。
*/
void useStructTemplatePrint()
{
	int a = 1;
	int b = 2;

	TS1<int> t;
	t.setValue(a, b);
	t.print();
}




void main()
{



	useClassTemplatePrint();

	useStructTemplatePrint();

	templateFunPrint(1, 2);
	templateFunPrint("123", "456");
	templateFunPrint('A', 'B');
	//_pointer();



	system("pause");
}