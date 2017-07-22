#include "TestStaticMem.h"

/**
* 为什么静态成员初始化一定要在类的实现文件中，而且必须定义，否则会出现链接错误

* @意外 今天看到一个人说类中的静态成员是声明，看到这句话我是眼前一亮，因为如果类的实现文件中如果不定义，那么就会出现error LINK2001:无法解析的外部符号：?mi@TestStaticMem::m_i，很简单，这个错误的原因就是由于只有声明而找不到实现造成的。
*
*
*
*/
int TestStaticMem::m_i = 0;

TestStaticMem::TestStaticMem()
{
}


TestStaticMem::~TestStaticMem()
{
}



void FunTestStatic()
{
	TestStaticMem ts;
	ts.printMem();
}
