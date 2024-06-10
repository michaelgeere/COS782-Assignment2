#include <type_traits>
#include "decorator_library.h"

// ======= Create Constraints that Decorator must uphold =========
MAKE_DECORATOR(
    IceCreamDecorator,
    DECORATOR_CONSTRAINT(toppingCost, double)
    DECORATOR_CONSTRAINT(getDescription, std::string)
);


// ======== Defining the interface which will use the decorator values ========
template<typename... ConcreteDecorator>
class IceCream;

template<>
class IceCream<> {
public:
    double getCost() const {
        return 1.0;
    }

    std::string getDescription() {
        return " Ice Cream";
    }
};

template<typename T, typename... ConcreteDecorators>
class IceCream<T, ConcreteDecorators...> {
    static_assert(IceCreamDecorator<T>, "Type does not satisfy decorator constraints.");
public:

    double getCost() const {
        return T().toppingCost() + IceCream<ConcreteDecorators...>().getCost();
    }

    std::string getDescription() {
        // check sizeof of Concrete deceorators with if to see if this is the last one
        if constexpr (sizeof...(ConcreteDecorators) == 2) {
            return T().getDescription() + ", " + IceCream<ConcreteDecorators...>().getDescription();
        } else if constexpr (sizeof...(ConcreteDecorators) == 1) {
            return T().getDescription() + " and " + IceCream<ConcreteDecorators...>().getDescription();
        } else {
            return T().getDescription() + IceCream<ConcreteDecorators...>().getDescription();
        }
    }
};

// ======= Defining Usefull Decorators =========
class ChocolateSauce {
public:
    double toppingCost() const {
        return 0.5;
    }

    std::string getDescription() {
        return "Chocolate Sauce";
    }
};

class Sprinkles {
public:
    double toppingCost() const {
        return 0.25;
    }

    std::string getDescription() {
        return "Sprinkles";
    }
};

class Oreo {
public:
    double toppingCost() const {
        return 0.3;
    }

    std::string getDescription() {
        return "Oreo";
    }
};
