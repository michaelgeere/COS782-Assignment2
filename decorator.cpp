#include <iostream>
#include <string>

// Base Interface
class IceCream
{
public:
    virtual std::string getDescription() = 0;
    virtual double cost() = 0;
    virtual ~IceCream() = default;
};

// Concrete Components
class Vanilla : public IceCream
{
public:
    std::string getDescription() override
    {
        return "Vanilla Ice Cream";
    }
    double cost() override
    {
        return 1.50;
    }
};

class Chocolate : public IceCream
{
public:
    std::string getDescription() override
    {
        return "Chocolate Ice Cream";
    }
    double cost() override
    {
        return 1.75;
    }
};

// Decorator Base Class
class IceCreamDecorator : public IceCream
{
protected:
    IceCream *iceCream;

public:
    IceCreamDecorator(IceCream *iceCream) : iceCream(iceCream) {}
    virtual ~IceCreamDecorator()
    {
        delete iceCream;
    }
};

// Concrete Decorators
class Sprinkles : public IceCreamDecorator
{
public:
    Sprinkles(IceCream *iceCream) : IceCreamDecorator(iceCream) {}
    std::string getDescription() override
    {
        return iceCream->getDescription() + " with Sprinkles";
    }
    double cost() override
    {
        return iceCream->cost() + 0.25;
    }
};

class ChocolateSauce : public IceCreamDecorator
{
public:
    ChocolateSauce(IceCream *iceCream) : IceCreamDecorator(iceCream) {}
    std::string getDescription() override
    {
        return iceCream->getDescription() + " with Chocolate Sauce";
    }
    double cost() override
    {
        return iceCream->cost() + 0.50;
    }
};

class WhippedCream : public IceCreamDecorator
{
public:
    WhippedCream(IceCream *iceCream) : IceCreamDecorator(iceCream) {}
    std::string getDescription() override
    {
        return iceCream->getDescription() + " with Whipped Cream";
    }
    double cost() override
    {
        return iceCream->cost() + 0.75;
    }
};

int main()
{
    IceCream *iceCream = new Vanilla();
    iceCream = new Sprinkles(iceCream);
    iceCream = new ChocolateSauce(iceCream);
    iceCream = new WhippedCream(iceCream);

    std::cout << iceCream->getDescription() << " costs $" << iceCream->cost() << std::endl;

    delete iceCream;
    return 0;
}