/*
目的：考察虚函数对类大小的影响，函数对类大小的影响，成员变量对类大小的影响，没有任何对象的类是如何计算大小的。

技巧：
1，类维护一个虚函数表，当类有多个虚函数时，类的大小只增加4个字节。
2，当类没有任何成员变量时，系统会自动添加一个char字节用以标记它的每一个对象。
3，类中的普通成员函数不会增加类的大小。
4，成员变量会增加类对象的大小。
*/


#include <iostream>

using namespace std;

//sizeof(Base) = 4
class Base
{
public:
	Base(int x) : a(x)
	{

	}

	void print()
	{
		cout << "base" << endl;
	}

private:
	int a;
};

//sizeof(Derived) = 8
class Derived : public Base
{
public:
	Derived(int x) : Base(x - 1), b(x)
	{

	}

	void print()
	{
		cout << "derived" << endl;
	}

private:
	int b;
};

//sizeof(A) = 8
class A
{
public:
	A(int x) : a(x)
	{

	}

	virtual void print()
	{
		cout << "A" << endl;
	}
private:
	int a;
};

//sizeof(B) = 12
class B : public A 
{
public:
	B(int x) : A(x - 1), b(x)
	{

	}
	virtual void print()
	{
		cout << "B" << endl;
	}

private:
	int b;
};




int main()
{
	Base obj1(1);
	cout << "size of Base obj is " << sizeof(obj1) << endl;		//4

	Derived obj2(2);
	cout << "size of Derived obj is " << sizeof(obj2) << endl;	//8

	A a(1);
	cout << "size of A obj is " << sizeof(a) << endl;			//8

	B b(2);
	cout << "size of B obj is " << sizeof(b) << endl;			//12

	system("pause");
}