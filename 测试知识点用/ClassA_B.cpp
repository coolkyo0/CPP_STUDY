#include "ClassA_B.h"

A_::A_()
{
	cout << "A的构造函数" << endl;
}

A_::~A_()
{
}


/**
* 静态变量不用不会报错，只要使用就必须实例化，否则会报LNK ERR2001
*/
//ClassA_B::A_ a;
ClassA_B::ClassA_B()
{
	cout << "B的构造函数" << endl;
}


ClassA_B::~ClassA_B()
{
}

void fun13_9initOrder()
{
	ClassA_B b;
	ClassA_B::a.print();
}
