#include <iostream>
#include "my_shared_ptr.h"

class Example
{
private:
	int m_value;
public:
	Example()
	{
		std::cout << "Example class construct@" << this << std::endl;
	}
	Example(int value)
		:m_value(value)
	{

	}
	~Example()
	{
		std::cout << "Example class destruct@" << this << std::endl;
	}
};

int main()
{
	my::Shared_ptr<Example> shared_ptr1;
	my::Shared_ptr<Example> shared_ptr2(shared_ptr1);

	return 0;
}