/**
* ��ʮһ�� STL(��׼ģ���)
*
* @Ŀ�� ����ѧϰ��׼ģ���
*/
#include <stdlib.h>

#include "11_18����ָ��.h"
#include "11_x�Լ�ʵ��һ���ַ�����.h"

void main()
{
	//fun11_18autoPtr();

	/**
	* �е�û����Ϊʲô����Ĵ��룬delete�ͷ�char*����ʱ�������쳣��   �������´��
	* @fuck ��fuck, new char[num];   new �������Ӧ����[]�����Ŷ�����()����������������������������
	* @���� char* str = new char(10);  ���ǳ��ֱ�������



	//����Ĵ����Ǵ���������ȷ��Ӧ����  new char[10]
	char* str = new char(10);
	strcpy_s(str, 10, "123");
	delete str;

	*/

	fun11_xTest1();
	fun11_xTest2();

	system("pause");
}
