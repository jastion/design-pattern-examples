#include <iostream>
#include <string>
#include "creator.cpp"
using namespace std;

void ClientCode (const Creator& creator) {
    cout << "Client: I'm not aware of creator's class but it still works. \n" << creator.SomeOperation() << endl; 
}

int main() {
    cout << "App: Launched with ConcreteCreator1" << endl;
    Creator* creator = new ConcreteCreator1();
    ClientCode(*creator);
    cout << endl;
    cout << "App: Launched with ConcreteCreator2" << endl;
    Creator* creator2 = new ConcreteCreator2();
    ClientCode(*creator2);

    delete creator;
    delete creator2;
    return 0;
}