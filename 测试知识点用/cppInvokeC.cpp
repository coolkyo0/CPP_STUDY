#include "cppInvokeC.h"


cppInvokeC::cppInvokeC()
{
}


cppInvokeC::~cppInvokeC()
{
}


/**
* CPPֱ�ӵ���C�Ĵ�����ֵĴ��������
*

* ����	1	error LNK2019: �޷��������ⲿ���� "void __cdecl print_hello_world(void)" (?print_hello_world@@YAXXZ)��
			�÷����ں��� "void __cdecl fun13_11cppinvokec(void)" (?fun13_11cppinvokec@@YAXXZ) �б�����	D:\STUDY\CPP_STUDY\����֪ʶ����\cppInvokeC.obj	����֪ʶ����

* ����	2	error LNK1120: 1 ���޷��������ⲿ����	D:\STUDY\CPP_STUDY\Debug\����֪ʶ����.exe	����֪ʶ����
* 
* 
* @ԭ�� C��C++���뷽ʽ��һ����C����û������û�аѲ��������ȥ�� c�ı��뷽ʽΪ__cdecl
* @
*/
void fun13_11cppinvokec()
{
	print_hello_world();
}
