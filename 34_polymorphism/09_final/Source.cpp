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


//Intersting fact #1
/*
class Plane final{
    Plane()=default;
};
//This will trigger a compiler error
class FigherJet : public Plane{

};
*/

int main() {

    std::cout << "Hello" << std::endl;
    return 0;
}