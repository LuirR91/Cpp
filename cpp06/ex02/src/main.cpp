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
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type of the object pointed to by p: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type of the object pointed to by p: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type of the object pointed to by p: C" << std::endl;
	return ;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Type of the object pointed to by p: A" << std::endl;
	}
	catch(const std::exception& e){}

	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Type of the object pointed to by p: B" << std::endl;
	}
	catch(const std::exception& e){}

	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Type of the object pointed to by p: C" << std::endl;
	}
	catch(const std::exception& e){}
	return ;
}

int main()
{
	Base	*test1;
	Base	*test2;
	Base	*test3;

	srand (time(NULL));

	test1 = generate();
	test2 = generate();
	test3 = generate();

	std::cout << "\n<<<<< Base	*identify >>>>>" << std::endl;
	std::cout << "Test 1: ";
	identify(test1);
	std::cout << "Test 2: ";
	identify(test2);
	std::cout << "Test 3: ";
	identify(test3);

	std::cout << "\n<<<<< Base& identify >>>>>" << std::endl;
	std::cout << "Test 1: ";
	identify(*test1);
	std::cout << "Test 2: ";
	identify(*test2);
	std::cout << "Test 3: ";
	identify(*test3);

	delete test1;
	delete test2;
	delete test3;
	return 0;
}
