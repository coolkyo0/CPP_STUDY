/**
* ��Ҫ��Ϊ�˼��ϵͳ���ɵ����������Ƿ����ó�Ա��������������
*
* @���� ��ʹ��ϵͳ�Զ����ɵ���������Ҳ��������Ա������������
*/
#pragma once
#include <iostream>
using namespace std;

class A13_6
{
public:
	A13_6();
	~A13_6();

private:

};

class TestDtor
{
public:
	TestDtor();

	A13_6 m_a;
};


void fun13_6systemGenerateDtorCallMemberVarDtor();