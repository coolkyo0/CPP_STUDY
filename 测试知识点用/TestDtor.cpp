#include "TestDtor.h"

A13_6::A13_6()
{
}

A13_6::~A13_6()
{
	cout << "A Dtor called" << endl;
}

TestDtor::TestDtor()
{
}

void fun13_6systemGenerateDtorCallMemberVarDtor()
{
	TestDtor td;
}
