/**
* 考察派生类继承基类，当基类中有私有成员变量时该如何初始化基类的私有变量
*
* @note 写这个Demo的原因是由于对文章中的代码持怀疑态度
*/
#include <iostream>

using namespace std;

class Base
{
public:
	Base() : i(0)
	{
		cout << "Base()" << endl;
	}
	Base(int n) : i(n)
	{
		cout << "Base(int)" << endl;
	}
	Base(const Base& b) : i(b.i)
	{
		cout << "Base(Base&)" << endl;
	}
	~Base(){}

private:
	int i;
};

class Dervied : public Base
{
public:
	Dervied() : Base(0), j(0)
	{
		cout << "Dervied()" << endl;
	}

	Dervied(int m, int n) : Base(m), j(n)
	{
		cout << "Dervied(int)" << endl;
	}

	/**
	* 敲了这么多代码就是怀疑这个函数，用派生类初始化基类的拷贝构造函数，可以吗？
	*
	*/
	Dervied(Dervied& obj) : Base(obj), j(obj.j)
	{
		cout << "Dervied(Dervied&)" << endl;
	}

private:
	int j;
};


void main()
{
	Base b(1);
	Dervied obj(2, 3);
	cout << "---------------" << endl;
	/** 事实证明可以用派生类对象初始化基类哦！！！！！！！ */
	Dervied d(obj);
	cout << "---------------" << endl;

	system("pause");
}