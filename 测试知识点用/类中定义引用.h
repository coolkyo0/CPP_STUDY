/**
* 测试类中是否可以定义引用
*
* @结论 类中定义引用或const类型变量必须在初始化列表中初始化，在类对象建立之前进行初始化。
*/
#pragma  once

class ClassWithQuota
{
public:
	ClassWithQuota() : m_q(m_i)
	{

	}
	~ClassWithQuota()
	{

	}

private:
	int m_i;
	int& m_q;
};

void funClassWithQuotaTest()
{
	ClassWithQuota cwq;
}