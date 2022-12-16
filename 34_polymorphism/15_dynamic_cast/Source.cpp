#include <memory>
#include "animal.h"
#include "feline.h"
#include "dog.h"

void do_something_with_animal_ptr(Animal* animal)
{
	std::cout << "In function taking base pointer..." << std::endl;
	Feline* feline_ptr = dynamic_cast<Feline*>(animal);

	if (feline_ptr) 
	{
		feline_ptr->do_some_feline_thingy();
	}
	else 
	{
		std::cout << "Couldn't cast to Feline pointer,Sorry." << std::endl;
	}

}

void do_something_with_animal_ref(Animal& animal)
{
	std::cout << "In function taking base reference..." << std::endl;
	Feline* feline_ptr_1{ dynamic_cast<Feline*>(&animal) };
	if (feline_ptr_1)
	{
		feline_ptr_1->do_some_feline_thingy();
	}
	else 
	{
		std::cout << "Couldn't cast to Feline reference,Sorry." << std::endl;
	}
}

int main()
{
	//// Base class pointer - Smart Pointer version
	//std::shared_ptr<Animal> animal1 = std::make_shared<Feline>("stripes", "feline1");
	////animal1->do_some_feline_thingy(); // It is not a virtual function

	//std::cout << "\n==========================\n\n";

	//// To solve the problem showed above we can use a dynamic cast

	//// If the cast succeeds, we get a valid pointer back,
	//// if it fails, we get nullptr. So we can check before
	//// calling stuff on the returned pointer
	//std::shared_ptr<Feline> feline_ptr = std::dynamic_pointer_cast<Feline>(animal1);
	//feline_ptr->do_some_feline_thingy();

	//std::cout << animal1 << std::endl; // Point to the same address
	//std::cout << feline_ptr << std::endl; // Point to the same address

	// Base class pointer - Normal Pointers
	Animal* animal1 = new Feline("stripes", "feline1");
	//animal1->do_some_feline_thingy(); // It is not a virtual function

	std::cout << "\n==========================\n\n";

	// To solve the problem showed above we can use a dynamic cast

	// If the cast succeeds, we get a valid pointer back,
	// if it fails, we get nullptr. So we can check before
	// calling stuff on the returned pointer
	Feline* feline_ptr = dynamic_cast<Feline*>(animal1);
	feline_ptr->do_some_feline_thingy();

	std::cout << animal1 << std::endl; // Point to the same address
	std::cout << feline_ptr << std::endl; // Point to the same address

	// If we try to change to Dog pointer, we will get Exception Thrown
	Dog* dog_ptr = dynamic_cast<Dog*>(animal1);
	// So we need to check if our pointer is not nullptr
	if (dog_ptr)
		dog_ptr->do_some_dog_thingy();
	else
		std::cout << "Couldn't do the transformation from Animal* to Dog*" << std::endl;


	delete animal1;
	animal1 = nullptr;
	feline_ptr = nullptr;

	std::cout << "\n==========================\n\n";

	// Can do the transformation downstream for references

	// Base class reference
	Feline feline2{ "stripes", "feline2" };
	Animal& animal_ref = feline2;

	// Calling non-virtual methods on animal_ref won't work
	//animal_ref.do_some_feline_thingy();

	Feline& feline_ref{ dynamic_cast<Feline&>(animal_ref) };
	feline_ref.do_some_feline_thingy();

	// If we change to Dog reference, we will get unhandled exception
	//Dog& dog_ref{ dynamic_cast<Dog&>(animal_ref) };

	// We have doing proper checks with references
	// Change base reference to base pointer
	Feline* feline_ptr1{ dynamic_cast<Feline*>(&animal_ref) };
	if (feline_ptr1)
		feline_ptr1->do_some_feline_thingy();
	else
		std::cout << "Couldn't cast to Feline, sorry!" << std::endl;

	std::cout << "\n==========================\n\n";

	do_something_with_animal_ptr(animal1);
	do_something_with_animal_ref(animal_ref);

	std::cout << "\n==========================\n\n";

	//int data{ 25 };
	//std::string data_str = dynamic_cast<std::string>(data);

	//int* data1 = new int{ 45 };
	//double* x = dynamic_cast<double*>(data1);

	return 0;
}