#include "ClassA_B.h"

A_::A_()
{
	cout << "A�Ĺ��캯��" << endl;
}

A_::~A_()
{
}


/**
* ��̬�������ò��ᱨ��ֻҪʹ�þͱ���ʵ����������ᱨLNK ERR2001
*/
//ClassA_B::A_ a;
ClassA_B::ClassA_B()
{
	cout << "B�Ĺ��캯��" << endl;
}


ClassA_B::~ClassA_B()
{
}

void fun13_9initOrder()
{
	ClassA_B b;
	ClassA_B::a.print();
}
