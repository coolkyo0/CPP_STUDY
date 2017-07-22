/**
* 本Demo目的是检测编译的Boost库是否成功。
*
*
*
*/
#include <iostream>  
#include <boost/thread/thread.hpp>  

void hello()
{
	std::cout << "Hello world, I'm a thread!" << std::endl;
}

int main()
{
	boost::thread thrd(&hello);
	thrd.join();

	system("pause");
}