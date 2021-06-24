#include <iostream>
#include <string>

using namespace std;

class Product {
    public:
        virtual ~Product() {}
        virtual string Operation() const = 0;
};

class ConcreteProduct1 : public Product {
    public:
        string Operation() const override {
            return "{Result of ConcreteProduct1}";
        }
};

class ConcreteProduct2 : public Product {
    public:
        string Operation() const override {
            return "{Result of ConcreteProduct2}";
        }
};