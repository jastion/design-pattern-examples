#include <iostream>
#include <string>
#include "product.cpp"

using namespace std;

class Creator {
    public:
    virtual ~Creator(){};
    virtual Product* FactoryMethod() const = 0;
    string SomeOperation() const { 
        Product* product = this->FactoryMethod();
        string result = "Creator: same creator's code just worked with " + product->Operation();
        delete product;
        return result;
    }
};

class ConcreteCreator1 : public Creator {
    public:
        Product* FactoryMethod() const override {
            return new ConcreteProduct1();
        }
};

class ConcreteCreator2 : public Creator {
    public:
        Product* FactoryMethod() const override {
            return new ConcreteProduct2();
        }
};