#pragma once

#include <iostream>
#include <memory>
#include <string_view>

class Dog;

class Person
{
public:
	Person(std::string_view name);
	~Person();

	void adopt_dog(std::unique_ptr<Dog> dog);
private:
	int m_age;
	std::string m_name;
};

