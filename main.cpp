#include <iostream>
#include "milky_lane.h"

// ====== Custom Decorators made by client =======
class WhippedCream {
public:
    double toppingCost() const {
        return 0.75;
    }

    std::string getDescription() {
        return "Whipped Cream";
    }
};

// ====== Client Runtime using the Ice Cream Decorator Library =======
int main() {
    IceCream<ChocolateSauce, Sprinkles, Oreo> chocoNsprinkles;
    IceCream<WhippedCream> choco;

    std::cout << chocoNsprinkles.getDescription() << std::endl;
    std::cout << chocoNsprinkles.getCost() << std::endl << std::endl;;

    std::cout << choco.getDescription() << std::endl;
    std::cout << choco.getCost() << std::endl;


    return 0;
}
