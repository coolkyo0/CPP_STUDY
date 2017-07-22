/**
* 本例旨在探讨C语言中struct与class的区别
* 
* @note <iostream>是C++中的，C语言中不能包含。
* @note 当我们在结构体S中定义构造函数时，编译器会报错，说明在C语言中struct是不能有成员函数的，只能有成员变量。
* @note C语言中定义结构体的成员要用struct S sa;除非用typedef，否则不能使用直接用S sa;来定义，编译器会报错。
* @note struct中的成员默认是public
* @note 在C语言中没有public、protect、private关键字。
*
* @note C语言中没有类的概念，定义了编译器会报错。
*
*
*****/


//#include <iostream>
//using namespace std;


#include <stdlib.h>




struct S
{
	int a;
	// S(){}
	//~S(){}
};


// class C
// {
// public:
// 	C(){}
// 	~C(){}
// 
// private:
// 
// };

void main()
{

	struct S sa;
	sa.a = 10;

}