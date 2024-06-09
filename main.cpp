#include <iostream>
#include <memory>
#include <type_traits>

// In the library
template<typename Derived>
class IceCream {
public:
    double cost() const {
        return static_cast<const Derived*>(this)->costImpl();
    }
};

template<typename Decorated>
class Decorator : public Decorated {
public:
    double cost() const {
        return Decorated::cost() + this->extraCostImpl();
    }
    double extraCostImpl() const {
        return 0; // Default implementation
    }
};


// In the ice cream program
class Vanilla : public IceCream<Vanilla> {
public:
    double costImpl() const {
        return 1.0;
    }
};

template<typename Decorated>
class ChocolateChips : public Decorator<Decorated> {
public:
    double extraCostImpl() const {
        return 0.2;
    }
};

int main() {
    ChocolateChips<Vanilla> deliciousIceCream;
    std::cout << "Total cost: $" << deliciousIceCream.cost() << std::endl;
    return 0;
}