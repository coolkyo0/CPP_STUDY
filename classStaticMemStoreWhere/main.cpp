/**
* ��������̽����ľ�̬��Ա�����洢����
*
*
****/

#include <iostream>
#include <stdlib.h>


using namespace std;


#include "A.h"

int b;

void main()
{

	/**
	* ����ͨ�������ӡȫ�ֱ������ྲ̬��Ա������ַ����ȫ�ֱ����ĵ�ַΪ
	* 0x00BF324�����ྲ̬��Ա�����Ǵ洢��0x00BF320����2����ַ�������ڣ�
	* ˵���ྲ̬��Ա����Ҳ�Ǵ洢�ھ�̬���ġ�
	*/

	cout << "b�ĵ�ַ = " << &b << endl;				//0x00BF324

	cout << "CA.m�ĵ�ַ = " << &(CA::m) << endl;	//0x00BF320

	
		

	system("pause");
}