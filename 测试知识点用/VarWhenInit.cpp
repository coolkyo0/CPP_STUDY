#include "VarWhenInit.h"

int VarWhenInit::m_i2 = 2;
const int VarWhenInit::m_i3;	//只可以定义，不可以初始化
VarWhenInit::VarWhenInit() : m_i1(10)
{

}


VarWhenInit::~VarWhenInit()
{
}

void fun13_4whenToInitVar()
{
	VarWhenInit vwi;

	cout << "vwi.m_i1 = " << vwi.m_i1 << endl;
	cout << "vwi.m_i2 = " << vwi.m_i2 << endl;
	cout << "vwi.m_i3 = " << vwi.m_i3 << endl;

	const VarWhenInit& vwi1 = vwi;

	cout << "vwi1.m_i1 = " << vwi1.m_i1 << endl;
	cout << "vwi1.m_i2 = " << vwi1.m_i2 << endl;
	cout << "vwi1.m_i3 = " << vwi1.m_i3 << endl;

	const VarWhenInit& vwi2 = vwi1;

	cout << "vwi2.m_i1 = " << vwi2.m_i1 << endl;
	cout << "vwi2.m_i2 = " << vwi2.m_i2 << endl;
	cout << "vwi2.m_i3 = " << vwi2.m_i3 << endl;
}
