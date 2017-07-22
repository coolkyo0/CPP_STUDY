/**
* 测试函数返回对象是如何调用构造函数的
*/
#include <iostream>
using namespace std;

class A_13_10
{
public:
	A_13_10();
	A_13_10(const A_13_10& a13)
	{
		cout << "拷贝构造" << endl;
	}
	~A_13_10();

private:

};

A_13_10::A_13_10()
{
	cout << "默认构造函数" << endl;
}

A_13_10::~A_13_10()
{
}

A_13_10 getValue(A_13_10 a)
{
	return a;
}

void fun13_10()
{
	A_13_10 a1310;
	/*A_13_10 b = */getValue(a1310);
}