#pragma once
#include "dog.h"
class BullDog : public Dog
{
public:
    BullDog();
    virtual ~BullDog();


    //Will throw a compiler error
   // THis function is marked as a final is a Dog class
   //virtual void run() const override{
   //    std::cout << "Bulldog::run() called" << std::endl;
   //}
   //

};

