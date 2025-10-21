#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	Base* base;
	switch (rand() % 3)
	{
		case 0:
			std::cout << "Generating object A" << std::endl;
			return base = new A();
		case 1:
			std::cout << "Generating object B" << std::endl;
			return base = new B();
		case 2:
			std::cout << "Generating object C" << std::endl;
			return base = new C();
	}
	return base;
}
void identify(Base* p)
{
	return ;
}
void identify(Base& p)
{
	return ;
}

int main()
{
	return 0;
}
