/**
* 类的析构函数为虚函数的好处？
*
* @好处 如果基类析构函数是虚函数，基类指针指向子类时，析构指针，先析构子类再析构父类。
* @收货 只要基类析构函数是虚函数就可以了，如果子类析构函数为虚而父类析构函数不为虚，那么编译可以通过，运行时将出错。
* @好处 如果基类析构函数不是虚函数，那么基类指针指向子类，析构时只析构父类而不会析构子类，这存在很大的内存泄漏风险。
* @收货 如果子类指针指向子类，即使析构函数不为虚，那么也会把子类和父类都给析构了。
* @收货 只有当基类指针需要释放子类资源时才定义虚析构函数，只需要定义基类的析构函数就可以了，不需要定义子类析构为虚。虚函数会降低性能，不需要用就别用了。
*/

#pragma once
#include <iostream>
using namespace std;

class DestructorA
{
public:
	DestructorA(){}
	~DestructorA()
	{
		cout << "~DestructorA()" << endl;
	}
};

class DestructorB : public DestructorA
{
public:
	DestructorB(){}
	~DestructorB()
	{
		cout << "~DestructorB()" << endl;
	}
};

class VirtualDestructorA
{
public:
	VirtualDestructorA(){}
	virtual ~VirtualDestructorA()
	{
		cout << "virtual ~VirtualDestructorA()" << endl;
	}
};

class VirtualDestructorB : public VirtualDestructorA
{
public:
	VirtualDestructorB(){}
	virtual ~VirtualDestructorB()
	{
		cout << "virtual ~VirtualDestructorB()" << endl;
	}
};

void forVirtualDestructor()
{
	DestructorA* pda = new DestructorB;
	delete pda;
	pda = NULL;

	VirtualDestructorA* pvda = new VirtualDestructorB;
	delete pvda;
	pvda = NULL;
}