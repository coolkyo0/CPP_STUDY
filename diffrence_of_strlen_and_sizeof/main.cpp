/**
* ��Ҫ��̽��strlen��sizeof������
* @ sizeof
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	char* s = "0123456789";
	char arr[] = "0123456789";

	/** sizeof(pointer) = 4, sizeof(str) = strlen(str) + 1 = 10 + 1  = 11 */
	cout << "sizeof(s) = " << sizeof(s) << endl << "strlen(s) = " << strlen(s) << endl;

	/** sizeof(array) != sizeof(pointer), sizeof(array) = strlen(array) + 1  = 10 + 1 = 11*/
	cout << "sizeof(arr) = " << sizeof(arr) << endl << "strlen(arr) = " << strlen(arr) << endl;

	/**
	* sizeof������ű���ʱ���Բ������ţ�sizeof�����������ʱҪ�����ţ�����ᱨ��
	* @char a;
	* @sizeof a;			//correct
	* @sizeof char;			//error
	* @sizeof(char);		//correct	
	*/
	cout << "sizeof s = " << sizeof s << endl;
	cout << "sizeof(int) = " << sizeof(int) << endl;
	system("pause");
	return 0;
}