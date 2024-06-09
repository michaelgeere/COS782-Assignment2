#include <iostream>
#include <concepts>
#include <type_traits>

// Define a concept that checks that the type has toppingCost associated
template<typename T>
concept IsIceCreamDecorator = requires(T a) {
    { a.toppingCost() } -> std::same_as<double>;
};

// Base case for the recursive calculation of total cost
template<typename... Toppings>
class IceCream;

template<>
class IceCream<> {
public:
    double getCost() const {
        return 0.0;
    }
};

// Recursive case for calculating the total cost
template<typename T, typename... Toppings>
class IceCream<T, Toppings...> {
    static_assert(IsIceCreamDecorator<T>, "Type does not satisfy IsIceCreamDecorator concept.");
public:

    static double constexpr baseCost = 1.0;
    double getCost() const {
        return baseCost + T().toppingCost() + IceCream<Toppings...>().getCost();
    }
};

class ChocolateSauce {
public:
    double toppingCost() const {
        return 0.5;
    }
};

class Sprinkles {
public:
    double toppingCost() const {
        return 0.3;
    }
};

class InvalidTopping {
public:
    // Missing toppingCost() function
};

int main() {
    IceCream<ChocolateSauce, Sprinkles> chocolateSauce;
    // IceCream<ChocolateSauce, Sprinkles, InvalidTopping> chocolateSauce; // Will not compile
    std::cout << chocolateSauce.getCost() << std::endl;
    return 0;
}





















