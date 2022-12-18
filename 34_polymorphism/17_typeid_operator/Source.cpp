#include <iostream>
#include <typeinfo>
#include <memory>

#include "polymorphic.h"
#include "nonpolymorphic.h"


int main()
{
	// 1. typeid() with fundamental types
	std::cout << "Fundamental types:" << std::endl;
	std::cout << "typeid(float).name(): " << typeid(float).name() << std::endl;

	if (typeid(22) == typeid(int))
		std::cout << "22 is an int" << std::endl;
	else
		std::cout << "22 is NOT an int" << std::endl;

	std::cout << "\n==============================================\n\n";

	// 2. typeid() with references(polymorphic)
	std::cout << "Polymorphic references:" << std::endl;
	DynamicDerived dynamic_derived;
	DynamicBase& base_ref = dynamic_derived;
	std::cout << "Type of dynamic_derived: " << typeid(dynamic_derived).name() << std::endl;
	std::cout << "Type of base_ref: " << typeid(base_ref).name() << std::endl;

	std::cout << "\n==============================================\n\n";

	// 3. typeid with pointers(polymorphic)
	std::cout << "Polymorphic pointers:" << std::endl;
	std::unique_ptr<DynamicBase> b_ptr = std::make_unique<DynamicDerived>();
	std::cout << "Type of b_ptr: " << typeid(b_ptr).name() << std::endl;

	// ATTENTION
	// For pointers we have to dereference to see the dynamic type
	std::cout << "Type of *b_ptr: " << typeid(*b_ptr).name() << std::endl;

	std::cout << "\n==============================================\n\n";

	// 4. typeid with non-polymorphic pointers and refs: we wil get static types
	// because we're using static bindings, the default behavior
	std::cout << "Non-polymorphic refs and pointers:" << std::endl;
	StaticDerived static_derived;
	StaticBase& static_base_ref = static_derived;
	std::unique_ptr<StaticBase> b_ptr_s = std::make_unique<StaticDerived>();

	std::cout << "Type of static_base_ref: " << typeid(static_base_ref).name() << std::endl;
	std::cout << "Type of *b_ptr_s: " << typeid(*b_ptr_s).name() << std::endl;

	return 0;
}