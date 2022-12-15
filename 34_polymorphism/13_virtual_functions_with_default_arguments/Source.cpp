#include <iostream>
#include <memory>
#include "base.h"
#include "derived.h"


int main()
{
	// Base ptr: uses polymorphism
	std::unique_ptr<Base> base_ptr1 = std::make_unique<Derived>();
	double result = base_ptr1->add();
	std::cout << "Result (base ptr): " << result << std::endl; // 12, because the default parameters are from Base class (5+5+2)

	std::cout << "\n===================================\n\n";

	// Base ref: uses polymorphism
	Derived derived1;
	Base& base_ref1 = derived1;
	result = base_ref1.add();
	std::cout << "Result (base ref): " << result << std::endl; // 12, because the default parameters are from Base class (5+5+2)

	std::cout << "\n===================================\n\n";

	// Raw objects
	Base base3;
	result = base3.add();
	std::cout << "Result (raw): " << result << std::endl; // 11, because it calls method from base class (5+5+1)

	std::cout << "\n===================================\n\n";

	// Direct object: uses static binding
	Derived derived2;
	result = derived2.add();
	std::cout << "Result (direct object): " << result << std::endl; // 22, because it calls method from Derived class (10+10+2)

	std::cout << "\n===================================\n\n";

	// Raw objects - slicing: uses static binding
	Base base1 = derived2;
	result = base1.add();
	std::cout << "Result (raw object assignment): " << result << std::endl; // 11, because it calls method from base class (5+5+1)

	return 0;
}