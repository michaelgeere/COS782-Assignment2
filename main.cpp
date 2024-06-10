#include <iostream>
#include <concepts>
#include <type_traits>

#include "library.h"

class WhippedCream {
public:
    double toppingCost() const {
        return 0.75;
    }

    std::string getDescription() {
        return "Whipped Cream";
    }
};

class InvalidTopping {
public:
    // Missing toppingCost() function
};

int main() {
    IceCream<ChocolateSauce, Sprinkles, Oreo> chocoNsprinkles;
    IceCream<ChocolateSauce> choco;
    // IceCream<ChocolateSauce, Sprinkles, InvalidTopping> chocolateSauce; // Will not compile

    std::cout << chocoNsprinkles.getDescription() << std::endl;
    std::cout << chocoNsprinkles.getCost() << std::endl << std::endl;;

    std::cout << choco.getDescription() << std::endl;
    std::cout << choco.getCost() << std::endl;


    return 0;
}
