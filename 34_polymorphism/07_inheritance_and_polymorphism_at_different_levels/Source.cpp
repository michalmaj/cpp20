/*
 * Animal inheritance hierarchy:
 *											Animal(breaths)
 *				Feline(runs)												Bird(flies)
 *		Dog(barks)			Cat(meows)							Pigeon(coos)			Crow(caws)
 */

#include <iostream>
#include <functional>
#include <memory>
#include <vector>
#include "animal.h"
#include "feline.h"
#include "dog.h"
#include "cat.h"
#include "bird.h"
#include "pigeon.h"
#include "crow.h"

int main()
{
    //Animal polymorphism
    Dog dog1("dark gray", "dog1");
    Cat cat1("black stripes", "cat1");
    Pigeon pigeon1("white", "pigeon1");
    Crow crow1("black", "crow1");

    std::reference_wrapper<Animal> animals[]{ dog1, cat1, pigeon1, crow1 };

    for (const auto& animal : animals)
        animal.get().breathe();

    std::cout << "\n======================================\n\n";

    //Feline polymorphism
    Dog dog2("dark gray", "dog2");
    Cat cat2("black stripes", "cat2");
    Pigeon pigeon2("white", "pigeon2");//Putting pigeon in felines will result in compiler error
									   // pigeon is and Animal,a but is not a feline.

    Animal animal1{ "Some Animal" }; // Same here, we can't put Animal into feline

    std::unique_ptr<Feline> felines[]{ std::make_unique<Dog>(dog2), std::make_unique<Cat>(cat2)/*, std::make_unique<Pigeon>(pigeon2)*//*, std::make_unique<Animal>(animal1)*/ };
    for (const auto& feline : felines)
    {
        feline->run();
    }

    std::cout << "\n======================================\n\n";

    // Bird polymorphism
    Pigeon pigeon3("white", "pigeon1");
    Crow crow3("black", "crow1");

    std::vector<std::reference_wrapper<const Bird>> birds{ pigeon3, crow3 };

    for (const auto& bird : birds)
        bird.get().fly();


	return 0;
}